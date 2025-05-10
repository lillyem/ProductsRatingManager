#include <iostream>
#include <cstdlib>
#include <fstream>
#include "LinkedList.h"
using namespace std;


int readProducts (Product products[]) {
	
	//opening file 
	
	ifstream in;
	
	in.open("Products.txt");
	
	if (!in.is_open()){
		cout << "Error opening the Products file. Aborting..." << endl;
		exit (1);
	}
	
	int i=0;
	string productCode;
	
	// reading until product code == END
	
	in >> productCode;
	
	while (productCode!="END"){
		products[i].code=productCode;
		in >> products[i].name;
		products[i].top = NULL;
		i++;						//iterate i to find the number of products in file
		in >> productCode;
	}
	
	return i;
}



int findProduct (Product products[], int numProducts, string code) {

	int i;
	
	//traverse array to find product
	for(i=0; i<numProducts; i++){
		if(products[i].code==code){
			return i;
		}
	}
	return -1;
}



void insertProductRating (Product products[], int numProducts, string code, string name, int rating) {
	
	//use findProduct, if found, insert the rating 
	
	int productFound= findProduct(products, numProducts, code);
	
	if (productFound==-1){
		//rating cannot be inserted, product not found
				cout << "ERROR >> Cannot insert rating. There is no product with this code: " << code << "." << endl;
	}
			
	else if (rating < 1 || rating >5){
		//rating cannot be inserted, rating out of bounds
		cout << "ERROR >> Cannot insert rating. Rating for product " << code << " is " << rating << ". It must be between 1 and 5." << endl;
	}
	else if(findRating(products[productFound].top,name)==NULL){
		//inserting rating
		products[productFound].top=insertRating(products[productFound].top, name, rating);
		cout << "-> The rating for product " << code << " by " << name << " was successfully inserted." << endl;
	}
			
	else{
		//product already rated by user
		cout << "ERROR >> Cannot insert rating. Product " << code << " has already been rated by " << name << "." << endl;	
	}
		
}



void displayProductRatings (Product products[], int numProducts, string code) {

	int productFound= findProduct(products, numProducts, code);
			
	if(productFound!=-1 && products[productFound].top!=NULL){
		//listing ratings once product is found and the LL is not null
		cout << "The following are the ratings for the product " << code << ":" << endl;
		displayRatings(products[productFound].top);
		cout << endl;
	}
	else if(productFound==-1){
		//product not found
		cout << "ERROR >> Cannot display rating. There is no product with this code: " << code << "." << endl;
	}
	else{
		//linked list is null, no ratings for product
		cout << "-> Nothing to display. There are no ratings as yet for product " << code << "." << endl;
	}
}	



void displayPersonRatings (Product products[], int numProducts, string name) {
	
	int i;
	LLNode * curr=NULL;
	bool found=false;
	
	cout << "These are the ratings made by " << name << ": " << endl;
	
	for(i=0; i<numProducts; i++){
		
		curr= findRating(products[i].top,name);
		
		if(curr!=NULL){
			//displaying product rated by person
			cout << products[i].code << "	" << products[i].name << "	" << curr->rating << endl;
			found=true;
		}
	}
	
	if(found==false){
		//no rating by the person was found
		cout << "-> Nothing to display. There are no product ratings by " << name << "." << endl;
	}
}



void displayRatingsGTE (Product products[], int numProducts, int rating) {
	
	int i;
	int avg;
			
	cout << "The following products have an average rating >= " << rating << ": " << endl;
	
	for(i=0; i<numProducts; i++){
		avg=averageRating(products[i].top);  //assigning avg to a variable
		if(avg>=rating){
			cout << products[i].code << "	" << products[i].name << endl;
		}
	}
} 



void deleteProductRating (Product products[], int numProducts,  string code, string name) {		
				  
	LLNode * curr=NULL;
			
	int productFound= findProduct(products, numProducts, code);
			
	curr = findRating(products[productFound].top, name);
		
	if(productFound==-1){
		cout << "ERROR >> Cannot delete rating. There is no product with this code: " << code << "." << endl;
	}
	else if(curr==NULL){
		cout << "ERROR >> Cannot delete rating. There is no rating for product " << code << " by " << name << "." << endl;
	}
	else{
		deleteRating(products[productFound].top, name);
		cout << "->The rating for product " << code << " by " << name << " was successfully deleted. "<< endl;
	}
		
}



int main() {
  
  	// declarations
  	Product products[1000];
  	int numProducts;
  	int command;
  	string code;
  	string name;
  	int rating;
  	
  	
  	// write code to read the Products.txt file and process
  	cout << "Reading data from Products file..." << endl;
  	numProducts=readProducts(products);
  	cout << "-> Data for " << numProducts << " product/s read." << endl;
  	cout << endl;
  	
  	//  the commands from the Commands.txt file.
  	ifstream inComm;
	
	inComm.open("Commands.txt");
	
	if (!inComm.is_open()){
		cout << "Error opening the Commands file. Aborting..." << endl;
		exit (1);
	}
	
	cout << "Processing commands from Command file..." << endl;
	cout << endl;
	
	inComm >> command;
	
	while(command!=99){
		//processing commands
		if(command==1){
			inComm >> code >> name >> rating;
			insertProductRating(products,numProducts, code,name,rating);
		}
		
		if(command==2){
			inComm >> code;
			displayProductRatings(products,numProducts,code);
		}
		
		if(command==3){
			inComm >> name;
			displayPersonRatings(products,numProducts,name);
		}
		
		if(command==4){
			inComm >> rating;
			displayRatingsGTE(products,numProducts, rating);
		}
		
		if(command==5){
			inComm >> code >> name;
			deleteProductRating(products,numProducts,code,name);
		}
		
		cout << endl;
		inComm >> command;
	}
	
	cout << "-> Command file successfully processed. " << endl;
	
	return 0;	
}
