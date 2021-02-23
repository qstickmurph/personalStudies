package lab2;

/**
 * This class provides an Animal object.
 *
 * @author Quinn Murphey (pfl955)
 * @since 02/04/2021
 */
public class Animal{
	/**
	 * The name of this Animal.
	 */
	private String name;

	/**
	 * The type of Animal this is.
	 */
	private String type;

	/**
	 * Whether the animal is Carnivorous or not.
	 * Vegetarian if false.
	 */
	private boolean diet; 
	
	/**
	 * Char representing the zoneCode of the zone where this animal is 
	 */
	private String zoneCode; 

	/**
	 * Constructor Method.
	 *
	 * @param name the name of the animal
	 * @param type the type of animal
	 * @param diet the diet of the animal (true = carnivore, false = vegetarian)
	 * @param zoneCode the code for the code of the zone in which this animal resides
	 */
	public Animal(String name, String type, boolean diet, String zoneCode){
		this.name = name;
		this.type = type;
		this.diet = diet;
		this.zoneCode = zoneCode;
	}

	// Instance Methods

	// Getters and Methods
	
	/**
	 * Setter for this.name.
	 * @param name Sets this.name to name
	 */
	public void setName(String name){
		this.name = name;
	}
	
	/**
	 * Getter for this.name.
	 * @return Returns this.name
	 */
	public String getName(){
		return this.name;
	}
	
	/**
	 * Setter for this.type.
	 * @param type The new value for this.type.
	 */
	public void setType(String type){
		this.type= type;
	}

	/**
	 * Getter for this.type.
	 * @return The value of this.type.
	 */
	public String getType(){
		return this.type;
	}

	/**
	 * Setter for this.diet.
	 * @param diet Sets this.diet to diet
	 */
	public void setDiet(boolean diet){
		this.diet= diet;
	}
	
	/**
	 * Getter for this.diet.
	 * @return Returns this.diet.
	 */
	public boolean getDiet(){
		return this.diet;
	}	

	/**
	 * Getter for this.zoneCode.
	 * @param zoneCode Sets this.name to name
	 */
	public void setZoneCode(String zoneCode){
		this.zoneCode= zoneCode;
	}
	
	/**
	 * Setter for this.zoneCode.
	 * @return Returns this.zoneCode.
	 */
	public String getZoneCode(){
		return this.zoneCode;
	}

	/**
	 * Returns a String representation of an Animal Object.
	 * @return The string representation of an Animal. 
	 */
	public String toString(){
		if(this.diet){
			return this.name+ " - " + this.type+ " (Carnivore)";
		}else{
			return this.name+ " - " + this.type+ " (Vegetarian)";
		}
	}

	// Class Methods
}
