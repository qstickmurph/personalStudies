#include "cards.h"
#include <stdlib.h>
#include <stdio.h>

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
	if(head == NULL){
		return head;
	}
	Card *newHead = head->next;
	free(head);
	return newHead;
}

Card *addCard(Card *head, Card *c){
	if(head->value <= c->value){
		c->next = head;
		return c;
	}
	for(Card *h = head; h != NULL; h=h->next){
		if(h->next == NULL){
			h->next = c;
			return head;
		}
		else if(h->next->value <= c->value){
			c->next = h->next;
			h->next = c;
			return head;
		}
	}
	return head;
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

void printCards(Card *head){
	for(Card *h = head; h != NULL; h = h->next){
		printCard(h);
		if(h->next != NULL){
			printf(", ");
		}
	}	
}

Card *buildCards(int n){
	if(n <= 0){
		return NULL;
	}
	Card *h = createCard();
	for(int i = 1; i < n; ++i){
		Card *new = createCard();
		h = addCard(h, new);
	}
	return h;
}

Card *destroyCards(Card *head){
	if(head == NULL){
		return head;
	}
	Card *next = head->next;
	free(head);
	destroyCards(next);
	return head;
}
