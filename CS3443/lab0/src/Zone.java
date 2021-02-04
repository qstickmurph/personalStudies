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
	 * The Array of Animals in this Zone.
	 */
	private Animal[] animals;

	/**
	 * The length of animals (static).
	 */
	private int maxAnimals;

	/**
	 * The number of nonnull elements of animals.
	 */
	private int numAnimals; // current number of animals

	/**
	 * Constructor Method.
	 *
   	 * @param name the arguments that go to SuperClass
	 * @param animals the arguments that are for this class
	 */
	public Zone(String name, int maxAnimals){
		this.name = name;
		this.animals = new Animal[maxAnimals];
		this.maxAnimals = maxAnimals;
	}

	// Instance Methods
	
	/**
	 * Appends an Animal object to the end of this.animals.
	 * @param newAnimal New animal to be appended to the end of this.animals
	 * @throws Reached_Animal_Limit This is thrown if addAnimal tries to append too many animals.
	 */
	public void addAnimal(Animal newAnimal){
		if(numAnimals >= maxAnimals){
			throw new java.lang.Error("Reached_Animal_Limit");
		}
		this.animals[numAnimals] = newAnimal;
		this.numAnimals += 1;
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
	public void setAnimals(Animal[] newAnimals){
		this.animals = newAnimals;
		this.numAnimals = newAnimals.length;
	}

	/**
	 * Getter for this.animals.
	 * @return The value of this.number
	 */
	public Animal[] getAnimals(){
		return this.animals;
	}

	/**
	 * String representation of Zone object.
	 * @return Returns a String representation of a Zone
	 */
	public String toString(){
		String finalString = this.name + " Zone :\n----------------\n";
		for(int i = 0; i < numAnimals; i++){
			finalString += " >>  " + this.animals[i].toString() + "\n";
		}
		return finalString;
	}
}
