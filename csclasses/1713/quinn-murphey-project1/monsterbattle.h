#ifndef MONSTERBATTLE_H
#define MONSTERBATTLE_H

typedef enum TYPE {EMPTY, PRIZE, MONSTER} TYPE; //This enumeration declare the possible types of rooms a player can enter
typedef struct Character //This struct declares a data type "Character" which stores all relevant data for the player and monster
{
	int hitPoints;
	int experiencePoints;
} Character;
typedef struct Prize //This struct declares a data type "Prize" which stores the number of points a prize will give when found
{
	int points;
} Prize;
typedef struct Room //This struct declares a data type "Room" whcih stores all relevant data for a room which a player can enter
{
	TYPE type;
	Character monster;
	Prize prize;
} Room;
int GetRandomNumber(int min, int max); //Returns a random number from min to max inclusive
void FillRooms(Room *rooms, int length); //Fills an array of Room data types with randomized type, monster, and/or prize
void EnterRoom(Room room, Character player, int *resultHP, int *resultXP); //Does all the relevant calculations of what happens when a player enters a room based on the room's type
void PrintCharacter(Character character); //Prints out a character's data


#endif
