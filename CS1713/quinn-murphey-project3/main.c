#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cards.h"

int main(int argc, char *argv[]){

	srand(time(NULL));
	
	if(argc != 2){
		if(argc > 2){
			printf("ERROR: Too many arguments\n");
			return -1;
		}else{
			printf("ERROR: Missing card count\n");
			return -1;
		}
	}
	int numCards = atoi(argv[1]);
	if(numCards <= 0){
		printf("Enter a number larger than 0\n");
		return -1;
	}


	printf("Player 1 Deck: ");
	Card *p1Deck = buildCards(numCards);
	printCards(p1Deck);
	printf("\nPlayer 2 Deck: ");
	Card *p2Deck = buildCards(numCards);
	printCards(p2Deck);
	printf("\n");

	int roundNum = 1;
	while(1){
		printf("\n------------------------------------\n");
		printf("Round %d\n", roundNum);
		printf("Player 1 Cards: ");
		printCards(p1Deck);
		printf("\nPlayer 2 Cards: ");
		printCards(p2Deck);
		printf("\n------------------------------------");

		printf("\nCards in play:\nPlayer 1: ");
		printCard(p1Deck);
		printf("\tPlayer 2: ");
		printCard(p2Deck);
		printf("\n");

		if(p1Deck->type == DEFEND){
			if(p2Deck->type == DEFEND){
				printf("Both players try and defend. Nothing happens...\n");
				printf("Both players discard the top card of their deck.\n");
				p1Deck = removeCard(p1Deck);
				p2Deck = removeCard(p2Deck);
			}
			else if(p2Deck->type == ATTACK){
				printf("Player 1 defends and Player 2 attacks!\n");
				if(p2Deck->value > p1Deck->value){
					printf("Player 2's attack is stronger than Player 1's defence, so Player 2 gains a random card.\n");
					printf("Both players discard the top card of their deck.\n");
					p2Deck = removeCard(p2Deck);
					p1Deck = removeCard(p1Deck);
					p2Deck = addCard(p2Deck, createCard());
				}else{
					printf("Player 1's defence is stronger than Player 2's attack, so Player 2 loses their next card.\n");
					printf("Both players discard the top card of their deck.\n");
					p2Deck = removeCard(removeCard(p2Deck));
					p1Deck = removeCard(p1Deck);
				}
			}
			else{//RUN
				printf("Player 1 defends and Player 2 runs, so Player 1 gains a random card and Player 2 loses their next card.\n");
				printf("Both players discard the top card of their deck.\n");
				p1Deck = removeCard(p1Deck);
				p2Deck = removeCard(removeCard(p2Deck));
				p1Deck = addCard(p1Deck, createCard());
			}
		}
		else if(p1Deck->type == ATTACK){
			if(p2Deck->type == DEFEND){
				printf("Player 1 attacks and Player 2 defends!\n");
				if(p1Deck->value > p2Deck->value){
					printf("Player 1's attack is stronger than Player 2's defence, so Player 1 gains a random card.\n");
					printf("Both players discard the top card of their deck.\n");
					p1Deck = removeCard(p1Deck);
					p2Deck = removeCard(p2Deck);
					p1Deck = addCard(p1Deck, createCard());
				}else{
					printf("Player 2's defence is stronger than Player 1's attack, so Player 1 loses their next card.\n");
					printf("Both players discard the top card of their deck.\n");
					p1Deck = removeCard(removeCard(p1Deck));
					p2Deck = removeCard(p2Deck);
				}

			}
			else if(p2Deck->type == ATTACK){
				printf("Both players attack!\n");
				if(p1Deck->value > p2Deck->value){
					printf("Player 1 has a greater attack value than player two, so Player 1 gains a random card to their deck.\n");
					printf("Both players discard the top card of their deck.\n");
					p1Deck = removeCard(p1Deck);
					p2Deck = removeCard(p2Deck);
					p1Deck = addCard(p1Deck, createCard());
				}
				else if(p2Deck->value > p1Deck->value){
					printf("Player 2 has a greater attack value than player two, so Player 2 gains a random card to their deck.\n");
					printf("Both players discard the top card of their deck.\n");
					p1Deck = removeCard(p1Deck);
					p2Deck = removeCard(p2Deck);
					p2Deck = addCard(p2Deck, createCard());
				}
				else{
					printf("Both players have the same attack so neither adds a random card to their deck.\n");
					printf("Both players discard the top card of their deck.\n");
					p1Deck = removeCard(p1Deck);
					p2Deck = removeCard(p2Deck);
				}
			}
			else{//RUN
				printf("Player 1 attacks and Player 2 runs, so Player 2 loses their next card.\n");
				printf("Both players discard the top card of their deck.\n");
				p1Deck = removeCard(p1Deck);
				p2Deck = removeCard(removeCard(p2Deck));
			}
		}
		else{//RUN
			if(p2Deck->type == DEFEND){
				printf("Player 1 runs and Player 2 defends, so Player 2 gains a random card and Player 1 loses their next card.\n");
				printf("Both players discard the top card of their deck.\n");
				p1Deck = removeCard(removeCard(p1Deck));
				p2Deck = removeCard(p2Deck);
				p2Deck = addCard(p2Deck, createCard());

			}
			else if(p2Deck->type == ATTACK){
				printf("Player 1 runs and Player 2 attacks, so Player 1 loses their next card.\n");
				printf("Both players discard the top card of their deck.\n");
				p1Deck = removeCard(removeCard(p1Deck));
				p2Deck = removeCard(p2Deck);
			}
			else{//RUN
				printf("Both players run! Both players lose their next card into the abyss.\n");
				printf("Both players discard the top card of their deck.\n");
				p1Deck = removeCard(removeCard(p1Deck));
				p2Deck = removeCard(removeCard(p2Deck));
			}
		}

		if(p1Deck == NULL || p2Deck == NULL){
			break;
		}

		++roundNum;
	}

	printf("\n\nGAME OVER!\n");
	if(p1Deck == NULL){
		printf("With a final deck of: ");
		printCards(p2Deck);
		printf("\nPLAYER 2 WINS!\n");
	}else{
		printf("With a final deck of: ");
		printCards(p1Deck);
		printf("\nPLAYER 1 WINS!\n");
	}


	
	return 0;
}
