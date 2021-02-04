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
	private boolean diet; // Whether the animal is Carnivorous (true) or Vegetarian (false)
	
	/**
	 * Constructor Method.
	 *
	 * @param args the arguments that go to SuperClass
	 * @param moreArgs the arguments that are for this class
	 */
	public Animal(String name, String type, boolean diet){
		this.name = name;
		this.type = type;
		this.diet = diet;
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
	 * @return Returns thisdiet.
	 */
	public boolean getDiet(){
		return this.diet;
	}

	/**
	 * Returns a String representation of an Animal Object.
	 * @return The string representation of an Animal. 
	 */
	public String toString(){
		if(this.diet){
			return this.type + " - " + this.name + " (Carnivore)";
		}else{
			return this.type + " - " + this.name + " (Vegetarian)";
		}
	}

	// Class Methods
}
