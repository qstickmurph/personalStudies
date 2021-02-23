package lab2;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileNotFoundException;

/**
 * This class provides a Zoo object.
 * A Zoo object contains Zones which contain Animals.
 *
 * @author Quinn Murphey (pfl955)
 * @since 02/04/2021
 */
public class Zoo{
	/**
	 * The name of this Zoo object.
	 */
	private String name;

	/**
	 * The ArrayList of Zone objects in this Zoo.
	 */
	private ArrayList<Zone> zones;
		
	/**
	 * Class constructor.
	 * 
	 * @param name The name of the zoo
	 */
	public Zoo(String name){
		this.name = name;
		this.zones = new ArrayList<Zone>();
	}

	// Instance Methods
	
	/**
	 * Reads the zones csv file to create the ArrayList<Zone> zones object
	 *	
	 * @param filePath contains the relative filepath to the csv file
	 */
	public void loadZones(String filePath) throws FileNotFoundException {
		File zoneFile = new File(filePath);
		try (Scanner zoneScanner = new Scanner(zoneFile)) {
			while(zoneScanner.hasNextLine()){
				String[] splitLine = zoneScanner.nextLine().split(",");
				this.addZone(new Zone(splitLine[0], splitLine[1], splitLine[2]));
			}
		}
	}
	
	/**
	 * Reads the animals csv file to populate zones with Animals
	 *
	 * @param filePath contains the relative filepath to the csv file
	 */
	public void loadAnimals(String filePath) throws FileNotFoundException {
		File animalFile = new File(filePath);
		try (Scanner animalScanner = new Scanner(animalFile)) {
			while(animalScanner.hasNextLine()){
				String[] splitLine = animalScanner.nextLine().split(",");
				String name = splitLine[0];
				String type = splitLine[1];
				boolean diet = splitLine[2].equals("TRUE");
				String zoneCode = splitLine[3];
				
				Zone zone = null;
				for(int i = 0; i < this.zones.size(); i++){
					if(this.zones.get(i).getZoneCode().equals(zoneCode)){
						zone = this.zones.get(i);
						break;
					}
				}
				if(zone == null){
					continue;
				}

				zone.addAnimal(new Animal(name, type, diet, zoneCode));
			}
		}
	}
	
	/**
	 * Appends zone onto this.zones.
	 *
	 * @param newZone The zone to be appended to the end of this.zones.
	 */
	public void addZone(Zone newZone){
		this.zones.add(newZone);
	}
	
	/**
	 * Relocates an animal from one zone to another
	 *
	 * @param animalName The name of the animal to be relocated
	 * @param zoneCode The zone code of the zone of which the animal will be relocated
	 */
	public void relocate(String animalName, String zoneCode){
		Animal animal = null;
		Zone originalZone = null;
		Zone destZone = null;
		for(int i = 0; i < this.zones.size(); i++){ //search for zone and animal
			ArrayList<Animal> animalList = this.zones.get(i).getAnimals();
			if(destZone == null && this.zones.get(i).getZoneCode().equals(zoneCode)){
				destZone = this.zones.get(i);
			}

			if(animal == null){
				for(int j = 0; j < animalList.size(); j++){
					if(animalList.get(j).getName().equals(animalName)){
						animal = animalList.get(j);
						originalZone = this.zones.get(i);
						break;
					}
				}
			}

			if(animal != null && destZone != null){
				break;
			}
		}

		if(animal != null && originalZone != null && destZone != null){
			animal.setZoneCode(zoneCode);
			destZone.addAnimal(animal);
			originalZone.removeAnimal(animal);
		}
	}

	/**
	 * Saves the contents of this Zoo to the file animalData/zones.csv and animalData/animals.csv
	 * @throws IOException 
	 */
	public void save() throws IOException{
		FileWriter animalFile = new FileWriter("animalData/animals.csv");
		FileWriter zoneFile = new FileWriter("animalData/zones.csv");
		
		for(int i = 0; i < this.zones.size(); i++) {
			Zone curZone = this.zones.get(i);
			ArrayList<Animal> curAnimals = curZone.getAnimals();
			for(int j = 0; j < curAnimals.size(); j++) {
				String diet;
				if(curAnimals.get(j).getDiet()) {
					diet = "TRUE";
				}else {
					diet = "FALSE";
				}
				animalFile.write(curAnimals.get(j).getName() + "," + curAnimals.get(j).getType() + "," + diet + "," + curAnimals.get(j).getZoneCode() + "\n");
			}
			String safetyString = "";
			switch(curZone.getSafetyRating()) {
				case LOW:
					safetyString = "low";
					break;
				case MEDIUM:
					safetyString = "medium";
					break;
				case HIGH:
					safetyString = "high";
					break;
				case CRITICAL:
					safetyString = "critical";
					break;
			}
			zoneFile.write(curZone.getName() + "," + safetyString + "," + curZone.getZoneCode() + "\n");
			
		}
		
		animalFile.close();
		zoneFile.close();
	}	

	// Getters and Setters
	
	/**
	 * Setter for this.name.
	 * @param newName The new value for this.name.
	 */
	public void setName(String newName){
		this.name = newName;
	}

	/**
	 * Getter for this.name.
	 * @return The value of this.name
	 */
	public String getName(){
		return this.name;
	}

	/**
	 * Setter for this.zones.
	 * @param newZones The new value for this.zones
	 */
	public void setZones(ArrayList<Zone> newZones){
		this.zones = newZones;
	}
	
	/**
	 * Getter for this.zones.
	 * @return The value of this.zones
	 */
	public ArrayList<Zone> getZones(){
		return this.zones;
	}
	
	/**
	 * The string representation of a Zoo object.
	 * @return The String representation of a Zoo object
	 */
	public String toString(){
		// TODO : FINISH toString()
		String finalString = "Welcome to the \"" + this.name + "\"!\n--------------------------------\n";
		for(int i = 0; i < this.zones.size(); i++){
			finalString += this.zones.get(i).toString() + "\n";
		}
		return finalString;
	}
}
