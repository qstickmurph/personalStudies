#ifndef CARDS_H
#define CARDS_H

typedef enum CardType {ATTACK, DEFEND, RUN} CardType;
typedef struct Card{
	CardType type;
	int value;
	Card *next;
}Card;
Card *createCard(Card *head);
Card *removeCard(Card *head, Card *c);
Card *addCard(Card *head);
int getLength(Card *head);
void printCard(Card *head);
void printCards(Card *head);
Card *buildCards(int n);
Card *destroyCards(Card *head);

#endif
