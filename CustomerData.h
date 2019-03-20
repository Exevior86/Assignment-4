//------------------------------ CustomerData.h ------------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// The header file for the cutomerData class and defines all of the function
// definitions.


#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "Item.h"
#include <iostream>

using namespace std;

class Customer {
public:
	Customer();								// Default constructor
	Customer(int, string, string);			// Constructor
	~Customer();							// Desconstructor

	void addTransaction(string, Item*);				// Adds a transaction to a customer
	const bool containsTransaction();		// Returns if a cutomer has a transaction or not
	string getName();						// Returns the name of a customer
	int getID();							// Returns a customer's ID
	void printHistory(ostream&);			// Prints the transaction history of a customer

private:
	
	struct TransactionNode {
		string type;
		Item* movie;						// A pointer to a movie
		TransactionNode* next;				// A pointer to the next node
	};
	int id;									// The customer's id
	string firstName;						// The customer's first name
	string lastName;						// The customer's last name
	TransactionNode* head;					// Pointer to a tranasactionNode list

	void deleteHelper(TransactionNode*);
};

#endif // !CUSTOMERDATA_H