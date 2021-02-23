#include <stdio.h>
#include <stdlib.h>
#include "monsterbattle.h"

int GetRandomNumber(int min, int max)
{
	return rand()%(max-min+1)+min;
}

void FillRooms(Room *rooms, int length)
{
	int r;
	for(int i = 0; i<length; ++i)
	{
		r = GetRandomNumber(0,2); //determine room type, then fill the room with respective random data
		switch(r)
		{
			case 0:
					rooms[i].type = EMPTY;
					break;
			case 1:
					rooms[i].type = MONSTER;
					rooms[i].monster.hitPoints = GetRandomNumber(10,30);
					rooms[i].monster.experiencePoints = (rooms[i].monster.hitPoints%3 == 0) ? 1 : 0;
					break;
			case 2:
					rooms[i].type = PRIZE;
					rooms[i].prize.points = GetRandomNumber(5,10);
					break;
		}
	}
}

/* Alternative FillRooms function using rooms as a pointer rather than using rooms[i]
void FillRooms(Room *rooms, int length)
{
	int r;
	for(int i = 0; i<length; ++i)
	{
		r = GetRandomNumber(0,2); //determine room type, then fill the room with respective random data
		switch(r)
		{
			case 0:
					rooms->type = EMPTY;
					break;
			case 1:
					rooms->type = MONSTER;
					rooms->monster.hitPoints = GetRandomNumber(10,30);
					rooms->monster.experiencePoints = (rooms[i].monster.hitPoints%3 == 0) ? 1 : 0;
					break;
			case 2:
					rooms->type = PRIZE;
					rooms->prize.points = GetRandomNumber(5,10);
					break;
		}
		++rooms;
	}
}
*/

void EnterRoom(Room room, Character player, int *resultHP, int *resultXP)
{
	switch(room.type) //set resultHP and resultXP according to room type and relevant room data
	{
		case EMPTY: 
				printf("The room is empty.\n");
				*resultHP = 0;
				*resultXP = 0;
				break;
		case MONSTER:
				printf("The room has a monster in it.");
				PrintCharacter(room.monster);
				*resultHP = (player.experiencePoints > room.monster.hitPoints) ? 0 : -room.monster.hitPoints;
				*resultXP = room.monster.experiencePoints;
				break;
		case PRIZE:
			  	printf("The room has a prize in it. (PTS: %d)\n", room.prize.points);
				*resultHP = room.prize.points;
				*resultXP = 0;
				break;
	}
}

void PrintCharacter(Character c)
{
	printf("(HP: %d, XP: %d)\n", c.hitPoints, c.experiencePoints);
}
