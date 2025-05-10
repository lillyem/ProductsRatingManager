# ProductsRatingManager

Product Ratings Manager
This C++ application allows you to manage and process customer ratings for various products using linked lists. It reads product information and a list of commands from input files, performs actions like inserting or deleting ratings, and displays rating information in various formats.

Files
main.cpp – The main logic of the program (your provided code).

LinkedList.h – Header file that contains the linked list structure (LLNode) and functions like insertRating, findRating, deleteRating, displayRatings, and averageRating.

Products.txt – Contains a list of products with their codes and names.

Commands.txt – Contains a sequence of commands for interacting with the product ratings.

Features
Load products from a file.

Insert customer ratings (1–5) for a product by a customer.

Prevent duplicate ratings by the same customer.

Display ratings for a specific product.

Display all products rated by a specific person.

Display all products with average rating greater than or equal to a value.

Delete a specific rating.

Handle invalid inputs with descriptive error messages.


Command	Description	Parameters
1	Insert a rating	<productCode> <name> <rating>
2	Display ratings for a product	<productCode>
3	Display all ratings given by a person	<name>
4	Display all products with average rating ≥ value	<rating>
5	Delete a specific rating	<productCode> <name>
99	End of command file	(no parameters)

How to Compile and Run
Ensure main.cpp, LinkedList.h, Products.txt, and Commands.txt are in the same directory.


Author
This project was developed as part of a C++ programming assignment involving file I/O, arrays, and linked lists.

