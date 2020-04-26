#include <stdio.h> 
#include <string.h> 
#include "student.h"

//Print the linked list in order, starting from the “head”. For each student node, you need to print all the elements. 
void print(Student *s){
	printf("Id: %d, Name: %s, Gpa: %lf\n", s->id, s->name, s->gpa);
	if(s->next != NULL){
		print(s->next);
	}
}

// Create and insert new nodes in the linked list. The insertion should happen in alphabetical order of the name. The values are for each student insertion are passed into this function from the main, where the values are read from a file. 
Student *insertStudentSortedByName(Student *s, Student *new){
	Student *head = s;
	
	if(strcmp(new->name, head->name) < 0){
		new->next = head;
		return new;
	}
	else if(head->next == NULL){
		head->next = new;
		return head;
	}
	for(Student *i = head; i->next != NULL; i = i->next){
		if(strcmp(new->name, i->next->name) < 0){
			new->next = i->next;
			i->next = new;
			break;
		}
	}
	return head;
}

void Split(Student *head, Student **frontRef, Student **backRef){ //split a linked list into two halves and store in references
	
	Student *slow;
	Student *fast;
	slow = head;
	fast = head->next;

	while(fast != NULL){
		fast = fast->next;
		if(fast != NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}

	*frontRef = head;
	*backRef = slow->next;
	slow->next = NULL;

}

Student *Merge(Student *a, Student *b){ // merge two previously sorted linked lists
	
	Student *result = NULL;
	
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}

	if(a->id <= b->id){
		result = a;
		result->next = Merge(a->next, b);
	}
	else{
		result = b;
		result->next = Merge(a, b->next);
	}
	return result;

}
// Sort the linked list in increasing order of the student-id (integer), using any sorting algorithm.
void sortListByID(Student **headRef){
	
	Student *head = *headRef;
	Student *a, *b;

	if((head == NULL) || (head->next == NULL)){ //if the list is already sorted (because it has 1 or no elements)
		return;
	}
	else{ //otherwise, split the list into two linked lists
		Split(head, &a, &b);
	}
	
	// then sort each list individually
	sortListByID(&a);
	sortListByID(&b);
	
	// then merge the two, now sorted, lists
	*headRef = Merge(a, b);
}
