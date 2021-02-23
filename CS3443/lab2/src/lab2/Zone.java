package lab2;

import java.util.ArrayList;

/**
 * This class provides a Zone object.
 * A Zone object contains Animals.
 *
 * @author Quinn Murphey (pfl955)
 * @since 02/04/2021
 */
public class Zone{
	/**
	 * The name of this Zone.
	 */
	private String name;

	/**
	 * The ArrayList of Animals in this Zone.
	 */
	private ArrayList<Animal> animals;

	/**
	 * Safety rating enum for zones (LOW, MEDIUM, HIGH, CRITICAL)
	 */
	public static enum SafetyRating { 
		LOW, 
		MEDIUM, 
		HIGH, 
		CRITICAL 
	}

	/**
	 * The safety rating variable for this Zone
	 */
	private SafetyRating safetyRating;

	/**
	 * The zone code for this Zone
	 */
	private String zoneCode;

	/**
	 * Constructor Method.
	 *
   	 * @param name the arguments that go to SuperClass
	 * @param safetyString 
	 * @param zoneCode 
	 */
	public Zone(String name, String safetyString, String zoneCode){
		this.name = name;
		this.animals = new ArrayList<Animal>();
		switch(safetyString){
			case "low":
				this.safetyRating = SafetyRating.LOW;
				break;
			case "medium":
				this.safetyRating = SafetyRating.MEDIUM;
				break;
			case "high":
				this.safetyRating = SafetyRating.HIGH;
				break;
			case "critical":
				this.safetyRating = SafetyRating.CRITICAL;
				break;
			default:
				this.safetyRating = SafetyRating.LOW;
				break;
		}
		this.zoneCode = zoneCode;
	}

	// Instance Methods
	
	/**
	 * Appends an Animal object to the end of this.animals.
	 * @param newAnimal New animal to be appended to the end of this.animals
	 */
	public void addAnimal(Animal newAnimal){
		this.animals.add(newAnimal);
	}
	
	/**
	 * Removes an Animal object from this.animals.
	 * @param newAnimal Animal to be removed from this.animals
	 */
	public void removeAnimal(Animal newAnimal){
		for (int i = 0; i < this.animals.size(); i++) {
			if (this.animals.get(i).getName() == newAnimal.getName()){
				this.animals.remove(i);
				break;
			}
		}
	}

	// Getters and Setters

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
	 * Setter for this.animals
	 * @param newAnimals The new value for this.animals
	 */
	public void setAnimals(ArrayList<Animal> newAnimals){
		this.animals = newAnimals;
	}

	/**
	 * Getter for this.animals.
	 * @return The value of this.number
	 */
	public ArrayList<Animal> getAnimals(){
		return this.animals;
	}

	/**
	 * Setter for this.safetyRating.
	 * @param name Sets this.safetyRating based on safetyString
	 */
	public void setSafetyRating(String safetyString){
		switch(safetyString){
			case "low":
				this.safetyRating = SafetyRating.LOW;
				break;
			case "medium":
				this.safetyRating = SafetyRating.MEDIUM;
				break;
			case "high":
				this.safetyRating = SafetyRating.HIGH;
				break;
			case "critical":
				this.safetyRating = SafetyRating.CRITICAL;
				break;
			default:
				this.safetyRating = SafetyRating.LOW;
				break;
		}
	}
	
	/**
	 * Setter for this.getSafetyRating.
	 * @return Returns this.safetyRating.
	 */
	public SafetyRating getSafetyRating(){
		return this.safetyRating;
	}
	
	/**
	 * Setter for this.zoneCode
	 * @param zoneCode Sets this.zoneCode to zoneCode 
	 */
	public void setZoneCode(String zoneCode){
		this.zoneCode = zoneCode;
	}
	
	/**
	 * Getter for this.zoneCode.
	 * @return Returns this.zoneCode
	 */
	public String getZoneCode(){
		return this.zoneCode;
	}

	/**
	 * String representation of Zone object.
	 * @return Returns a String representation of a Zone
	 */

	public String toString(){
		String dangerString = "";
		switch(this.safetyRating){
			case LOW:
				dangerString = "(low risk)";
				break;
			case MEDIUM:
				dangerString = "(medium risk)";
				break;
			case HIGH:
				dangerString = "(high risk)";
				break;
			case CRITICAL:
				dangerString = "(critical risk)";
				break;
		}

		String finalString = this.zoneCode + ": " + this.name + " Zone " + dangerString  + ":\n----------------\n";
		for(int i = 0; i < this.animals.size(); i++){
			finalString += " >>  " + this.animals.get(i).toString() + "\n";
		}
		return finalString;
	}
}
