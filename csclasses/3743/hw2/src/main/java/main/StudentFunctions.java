package main;

import hashdb.HashFile;
import hashdb.HashHeader;
import hashdb.Vehicle;
import misc.ReturnCodes;
import misc.MutableInteger;

import java.io.File;
import java.io.RandomAccessFile;
import java.io.IOException;
import java.io.FileNotFoundException;

import java.nio.ByteBuffer;

import java.util.Arrays;

public class StudentFunctions {
    static final int SIZE_OF_INT = 32;

    /**
     * hashCreate
     * This funcAon creates a hash file containing only the HashHeader record.
     * • If the file already exists, return RC_FILE_EXISTS
     * • Create the binary file by opening it.
     * • Write the HashHeader record to the file at RBN 0.
     * • close the file.
     * • return RC_OK.
     */
    public static int hashCreate(String fileName, HashHeader hashHeader) {
        File temp = new File(fileName);
        if (temp.exists()){
            return ReturnCodes.RC_FILE_EXISTS;
        }
        
        try {
            RandomAccessFile raf = new RandomAccessFile(temp, "rws");
            HashFile hashFile = new HashFile();
            hashFile.setFile( raf );
            hashFile.setHashHeader(hashHeader);
            hashFile.getFile().seek(0);
            hashFile.getFile().write(hashFile.getHashHeader().toByteArray()); 
            hashFile.getFile().close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        return ReturnCodes.RC_OK;    
    }

    /**
     * hashOpen
     * This function opens an existing hash file which must contain a HashHeader record
     * , and sets the file member of hashFile
     * It returns the HashHeader record by setting the HashHeader member in hashFile
     * If it doesn't exist, return RC_FILE_NOT_FOUND.
     * Read the HashHeader record from file and return it through the parameter.
     * If the read fails, return RC_HEADER_NOT_FOUND.
     * return RC_OK
     */
    public static int hashOpen(String fileName, HashFile hashFile) {
        File temp = new File(fileName);
        if ( ! temp.exists() ){
            return ReturnCodes.RC_FILE_NOT_FOUND;
        }

        try {
            hashFile.setFile( new RandomAccessFile(temp, "rws") );
            byte[] bytes = new byte[3 * SIZE_OF_INT];
            hashFile.getFile().seek(0);
            hashFile.getFile().read(bytes);
            hashFile.getHashHeader().fromByteArray(bytes);
        } catch (IOException e) {
            e.printStackTrace();
        }

        return ReturnCodes.RC_OK;
    }

    /**
     * vehicleInsert
     * This function inserts a vehicle into the specified file.
     * Determine the RBN using the Main class' hash function.
     * Use readRec to read the record at that RBN.
     * If that location doesn't exist
     * OR the record at that location has a blank vehicleId (i.e., empty string):
     * THEN Write this new vehicle record at that location using writeRec.
     * If that record exists and that vehicle's szVehicleId matches, return RC_REC_EXISTS.
     * (Do not update it.)
     * Otherwise, return RC_SYNONYM. a SYNONYM is the same thing as a HASH COLLISION
     * Note that in program #2, we will actually insert synonyms.
     */
    public static int vehicleInsert(HashFile hashFile, Vehicle vehicle) {
        int maxHash = hashFile.getHashHeader().getMaxHash();
        int hash = P2Main.hash(vehicle.getVehicleId(), maxHash);
        Vehicle oldVehicle = new Vehicle();
        if ( readRec(hashFile, hash, oldVehicle) == ReturnCodes.RC_LOC_NOT_FOUND || oldVehicle.getVehicleIdAsString().equals("") ){ // When Location is empty
            writeRec(hashFile, hash, vehicle);
            return ReturnCodes.RC_OK;
        } else if( oldVehicle.getVehicleIdAsString().equals(vehicle.getVehicleIdAsString() ) ){
            return ReturnCodes.RC_REC_EXISTS;
        } else{ // When Location has a Vehicle already in it
            int i;
            int firstEmpty = -1;
            for( i = 1; i < hashFile.getHashHeader().getMaxProbe(); i++ ){
                readRec(hashFile, hash + i, oldVehicle);
                if( vehicle.getVehicleIdAsString().equals(oldVehicle.getVehicleIdAsString()) ){
                    return ReturnCodes.RC_REC_EXISTS;
                }else if( firstEmpty == -1 && oldVehicle.getVehicleIdAsString().equals("") ){
                    firstEmpty = i;
                }
            }

            if( firstEmpty == -1){
                return ReturnCodes.RC_TOO_MANY_COLLISIONS;
            }
            
            writeRec(hashFile, hash + firstEmpty, vehicle);
            return ReturnCodes.RC_OK;
        }
    }

    /**
     * readRec(
     * This function reads a record at the specified RBN in the specified file.
     * Determine the RBA based on RBN and the HashHeader's recSize
     * Use seek to position the file in that location.
     * Read that record and return it through the vehicle parameter.
     * If the location is not found, return RC_LOC_NOT_FOUND.  Otherwise, return RC_OK.
     * Note: if the location is found, that does NOT imply that a vehicle
     * was written to that location.  Why?
      */
    public static int readRec(HashFile hashFile, int rbn, Vehicle vehicle) {
        int rba = rbn * hashFile.getHashHeader().getRecSize();
        RandomAccessFile dataFile = hashFile.getFile();

        try{
            if( rba > dataFile.length() ){
                return ReturnCodes.RC_LOC_NOT_FOUND;
            }
            byte[] bytes = new byte[ vehicle.sizeOf() ];
            dataFile.seek(rba);
            dataFile.read(bytes);
            vehicle.fromByteArray(bytes);
        } catch (IOException e){
            e.printStackTrace();
            return ReturnCodes.RC_LOC_NOT_FOUND;
        }
        return ReturnCodes.RC_OK;
    }

    /**
     * writeRec
     * This function writes a record to the specified RBN in the specified file.
     * Determine the RBA based on RBN and the HashHeader's recSize
     * Use seek to position the file in that location.
     * Write that record to the file.
     * If the write fails, return RC_LOC_NOT_WRITTEN.
     * Otherwise, return RC_OK.
     */
    public static int writeRec(HashFile hashFile, int rbn, Vehicle vehicle) {
        int rba = rbn * hashFile.getHashHeader().getRecSize();
        RandomAccessFile dataFile = hashFile.getFile();
        try {
            dataFile.seek(rba);
            dataFile.write(Arrays.copyOfRange(vehicle.toByteArray(), 0, Math.min(hashFile.getHashHeader().getRecSize(), Vehicle.sizeOf()) ));
        } catch ( IOException e ){
            e.printStackTrace();
            return ReturnCodes.RC_LOC_NOT_WRITTEN;
        }
        return ReturnCodes.RC_OK;
    }

    /**
     * vehicleRead
     * This function reads the specified vehicle by its vehicleId.
     * Since the vehicleId was provided,
     * determine the RBN using the Main class' hash function.
     * Use readRec to read the record at that RBN.
     * If the vehicle at that location matches the specified vehicleId,
     * return the vehicle via the parameter and return RC_OK.
     * Otherwise, return RC_REC_NOT_FOUND
     */
    public static int vehicleRead(HashFile hashFile, MutableInteger rbn, Vehicle vehicle) {
        int hash = P2Main.hash(vehicle.getVehicleId(), hashFile.getHashHeader().getMaxHash());
        rbn.set(hash);
        Vehicle testVehicle = new Vehicle();
        int rc = readRec(hashFile, rbn.intValue(), testVehicle);
        if(vehicle.getVehicleIdAsString().equals(testVehicle.getVehicleIdAsString()) ){
            vehicle.fromByteArray(testVehicle.toByteArray());
            return ReturnCodes.RC_OK;
        }else{
            int i;
            for( i = 1; i < hashFile.getHashHeader().getMaxProbe(); i++ ){
                readRec(hashFile, hash + i, testVehicle);
                if( vehicle.getVehicleIdAsString().equals(testVehicle.getVehicleIdAsString()) ){
                    vehicle.fromByteArray(testVehicle.toByteArray());
                    rbn.set(hash + i);
                    return ReturnCodes.RC_OK;
                }
            }

            return ReturnCodes.RC_REC_NOT_FOUND;
        }
    }

    /**
     * vehicleUpdate
     * 
     * 
     */
    public static int vehicleUpdate(HashFile hashFile, Vehicle vehicle){
        MutableInteger rbn = new MutableInteger(0);
        Vehicle storageVehicle = new Vehicle();
        storageVehicle.fromByteArray(vehicle.toByteArray());
        int rc = vehicleRead(hashFile, rbn, storageVehicle);
        if( rc == ReturnCodes.RC_REC_NOT_FOUND ){
            return ReturnCodes.RC_REC_NOT_FOUND;
        }
        writeRec(hashFile, rbn.intValue(), vehicle);
        return ReturnCodes.RC_OK;
    }   

    /**
     * vehicleDelete
     * 
     */
    public static int vehicleDelete(HashFile hashFile, char [] vehicleId){
        MutableInteger rbn = new MutableInteger(0);
        Vehicle storageVehicle = new Vehicle();
        storageVehicle.setVehicleId(vehicleId);
        int rc = vehicleRead(hashFile, rbn, storageVehicle);

        if( rc == ReturnCodes.RC_REC_NOT_FOUND ){
            return ReturnCodes.RC_REC_NOT_FOUND;
        }
        
        Vehicle vehicle = new Vehicle();
        writeRec(hashFile, rbn.intValue(), vehicle);

        /*RandomAccessFile dataFile = hashFile.getFile();
        try{
            System.out.println(rbn.intValue());
            dataFile.seek(rbn.intValue());
            dataFile.writeChars((new char[Vehicle.sizeOf() / 2]).toString());
        } catch ( IOException e ){
            e.printStackTrace();
            return ReturnCodes.RC_LOC_NOT_WRITTEN;
        }*/
        return ReturnCodes.RC_OK;
    }
}
