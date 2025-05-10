#include <iostream>
#include <cstdlib>
#include <cmath>
#include "LinkedList.h"

using namespace std;


LLNode * createLLNode (string name, int rating) {
	
	LLNode * newLLNode;

	newLLNode = new LLNode;
	newLLNode->name = name;
	newLLNode->rating=rating;
	newLLNode->next = NULL;
	
	return newLLNode;
}




int sizeRatings (LLNode * top) {

	if(top==NULL){
		return 0;
	}
	
	return 1+ sizeRatings(top->next);
}



LLNode * insertRating (LLNode * top, string name, int rating) {
	
	if(top==NULL || top->rating <=rating){
		LLNode * newLLNode = createLLNode(name,rating);
		newLLNode->next=top;
		return newLLNode;
	}
	top->next=insertRating(top->next, name, rating);
	
	return top;
}


LLNode * deleteRating (LLNode * top, string name) {
	
	if(top==NULL){
		return NULL;
	}
	
	if(top->name==name){
		
		LLNode * curr = top;
		top=top->next;
		
		delete curr;
		
		return top;
	}
	
	top->next=deleteRating(top->next, name);
	
	return top;
	
}
		


void displayRatings (LLNode * top) {

	if(top==NULL){
		return;
	}
	
	cout << top->name << "	" << top->rating << endl;
	
	displayRatings(top->next);
}



LLNode * findRating (LLNode * top, string name) {
	
	if(top==NULL){
		return NULL;
	}
	
	if(top->name==name){
		return top;
	}
	return findRating(top->next,name);
}
	

int averageRating (LLNode * top) {
	
	int sum=0;
	int num=0;
	
	if(top==NULL){
		return 0;
	}
	
	while(top!=NULL){
		sum+=top->rating;
		top=top->next;
		num++;
	}

	float average=(sum*1.0)/num;
	
	int avg=round(average);

	return avg;
} 
