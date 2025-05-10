#include <cstdlib>
using namespace std;

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct LLNode {
	string name;
	int rating;
	LLNode * next;
};

struct Product {
	string code;
	string name;
	LLNode * top;
};

// Function declarations for functions in LinkedList.cpp.

LLNode * createLLNode (string name, int rating);
int sizeRatings (LLNode * top);
LLNode * insertRating (LLNode * top, string name, int rating);
LLNode * deleteRating (LLNode * top, string name);
void displayRatings (LLNode * top);
LLNode * findRating (LLNode * top, string name);
int averageRating (LLNode * top);
#endif
