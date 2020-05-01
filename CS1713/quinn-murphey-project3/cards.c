#include "cards.h"
#include <stdlib.h>

Card *createCard(){
	Card *card = (Card*)(malloc(sizeof(Card)));
	int random = rand() % 10;

	if(random < 1){ //RUN
		card->type = RUN;
		card->value = (rand() % 5) + 1; 
	}else if(random < 5){ //ATTACK
		card->type = ATTACK;
		card->value = (rand() % 6) + 3; 
	}else{ //DEFEND
		card->type = DEFEND;
		card->value = (rand() % 8) + 1; 
	}

	return card;
}

Card *removeCard(Card *head){
	Card *newHead = head->next;
	free(head);
	return newHead;
}

Card *addCard(Card *head, Card *c){
	if(head->value < c->value){
		c->next = head;
		return c;
	}
	for(Card *h = head; h != NULL; h=h->next){
		if(h->next->value < c->value){
			c->next = h->next;
			h->next = c;
			return head;
		}
	}
}

int getLength(Card *head){
	int length = 0;
	for(Card *h = head; h != NULL; h = h->next){
		length += 1;
	}
	return length;
}

void printCard(Card *head){
	if(head->type == ATTACK){
		printf("A%d", head->value);
	}else if(head->type == DEFEND){
		printf("D%d", head->value);
	}else{
		printf("R%d", head->value);
	}
}

void printCards(Card *head);{
	for(Card *h = head; h != NULL; h = h->next){
		if(h->type == ATTACK){
			printf("A%d", h->value);
		}else if(h->type == DEFEND){
			printf("D%d", h->value);
		}else{
			printf("R%d", h->value);
		}
	}	
}

Card *buildCards(int n){
	
}

Card *destroyCards(Card *head){
	
}

#endif
