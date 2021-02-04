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
	 * The array of Zone objects in this Zoo.
	 */
	private Zone[] zones;

	/**
	 * The length of the zones Array (static).
	 */
	private int maxZones = 0;

	/**
	 * The number of nonnull elements of zones.
	 */
	private int numZones = 0; // the length of zones array
	
	/**
	 * Class constructor.
	 * 
	 * @param name The name of the zoo
	 * @param zoneCount The number of zones in the zoo
	 */
	public Zoo(String name, int zoneCount){
		this.name = name;
		this.zones = new Zone[zoneCount];
		this.maxZones = zoneCount;
		// additional implementation
	}

	// Instance Methods
	
	/**
	 * Appends zone onto this.zone.
	 *
	 * @param newZone The zone to be appended to the end of this.zone.
	 * @throws Reached_Zone_Limit This is thrown if addZone tries to append too many Zones to this zoo.
	 */
	public void addZone(Zone newZone){
		if(numZones >= maxZones){
			throw new java.lang.Error("Reached_Zone_Limit");
		}
		this.zones[numZones] = newZone;
		this.numZones += 1;
	}

	// Getters and Setters
	
	/**
	 * Setter for this.name.
	 * @param newName The new value for this.name.
	 */
	public void setName(String newName){
		this.name= newName;
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
	public void setZones(Zone[] newZones){
		this.zones = newZones;
		this.numZones = newZones.length;
	}
	
	/**
	 * Getter for this.zones.
	 * @return The value of this.zones
	 */
	public Zone[] getZones(){
		return this.zones;
	}
	
	/**
	 * The string representation of a Zoo object.
	 * @return The String representation of a Zoo object
	 */
	public String toString(){
		// TODO : FINISH toString()
		String finalString = "Welcome to the \"" + this.name + "\"!\n--------------------------------\n";
		for(int i = 0; i < this.numZones; i++){
			finalString += this.zones[i].toString() + "\n";
		}
		return finalString;
	}
}
