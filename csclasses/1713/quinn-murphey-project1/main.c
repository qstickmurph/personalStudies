#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "monsterbattle.h"

int main(int argc, char *argv[])
{
	
    int numRooms; //placeholder for the number of rooms in this game
	int hpChange; //placeholder for the net hp change from a given room
	int experienceGained; //placeholder for the net xp change from a given room

 	srand((int)time(0)); //seed pseudo-random number generator

	// initialize player data in Character struct
  	Character player;
	player.hitPoints = 50;
	player.experiencePoints = 0;
	
	//If the binary is ran with an additional argument, set numRooms to that value. Otherwise, ask for desired value of numRooms. NOTE: Avoid numbers larger than 500000
	if(argc > 1) 
	{
		numRooms = atoi(argv[1]);
	}
	else
	{
    	printf("How many rooms would you like to enter?");
		scanf("%d", &numRooms);
	}

	Room rooms[numRooms];

	FillRooms(rooms, numRooms); //Fills the rooms randomly

	printf("There are %d rooms. The challenge has begun\n", numRooms);

	printf("Player Data: ");
	PrintCharacter(player);
	//Begin traversing through each room
	for(int i = 0; i < numRooms; ++i)
	{
		printf("\n----- ROOM %d of %d -----\n", i+1, numRooms);
		
		EnterRoom(rooms[i], player, &hpChange, &experienceGained); //calculate hpChange and xpChange from room[i]
		
		//Determine whether the player gained or lost hitpoints
		(hpChange < 0) ? printf("You lost %d hit points while in this room\n", -hpChange) : printf("You gained %d hit points while in this room\n", hpChange);
		
		//Check if player is dead, if so, end loop and set hp to 0
		if(- hpChange > player.hitPoints)
		{
			player.hitPoints = 0;
			break;
		}
		else
		{
			player.hitPoints += hpChange;
		}

		if(experienceGained != 0)
		{
			printf("You gained %d experience points\n", experienceGained);
		}
			
		player.experiencePoints += experienceGained;
		
		printf("Player Data: ");
		PrintCharacter(player);
	}
	
	//Determine whether or not the player survived the dungeon. And print relevant response
	if(player.hitPoints <= 0)
	{
		printf("You have died . . .\n");
		printf("Final Player Data: ");
		PrintCharacter(player);
	}
	else
	{
		printf("Congratulations! You have successfully travelled through %d rooms.\n Final Player Data: ", numRooms);
		PrintCharacter(player);
	}

    return 0;
}
