//------------------------------ CustomerData.cpp ------------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// This class allows the construction of customer nodes and can add 
// transactions to the node. The class also has a printmethod and a contains 
// methods that checks if a customer has any transations or not.
//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------

#include "CustomerData.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
Customer::Customer()
{
	head = NULL;
} // end of constructor

//------------------------------ constructor ---------------------------------
// Constructs a customer object and initializes it's data
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
Customer::Customer(int num, string first)
{
	id = num;
	firstName = first;
	head = NULL;
} // end of constructor

// destructor
Customer::~Customer() 
{
	deleteHelper(head);
}

//------------------------------ deleteHelper ---------------------------------
// Deletes transactions for the customer.
// Preconditions: None
// Postconditions: None
//-----------------------------------------------------------------------------
void Customer::deleteHelper(TransactionNode* node)
{
	if (node != NULL)
	{
		deleteHelper(node->next);
		delete node->movie;
		delete node;
	}
}

//------------------------------ addTransaction ---------------------------------
// Adds a transaction to a customer
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void Customer::addTransaction(string type, Item* aMovie)
{
	TransactionNode *toAdd = new TransactionNode;
	toAdd->type = type;
	toAdd->movie = aMovie;
	toAdd->next = NULL;

	if (head != NULL)
	{
		toAdd->next = head;
	}
	head = toAdd;
} // end of addTransaction

//------------------------------ containsTransaction ---------------------------------
// Returns whether or not a customer has a transaction or not
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
const bool Customer::containsTransaction()
{
	return head == NULL;
} // end of containsTransaction

//------------------------------ printHistory ---------------------------------
// Prints the history of a customer's transactions, returns an error message if
// the customer has no transactions
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void Customer::printHistory(ostream& out)
{
	TransactionNode *temp = head;
	out << "****************** " << getName() << " ******************" << endl;

	if (temp == NULL)
		out << "No Prior Transactions" << endl;
	else
		while (temp != NULL)
		{
			out << temp->type << " ";
			temp->movie->print(out);
			out << endl;
			temp = temp->next;
		}
	out << endl;
} // end of pritnHistory

//------------------------------ getID ---------------------------------
// Returns a customer's ID
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
int Customer::getID() {
	return id;
} // end of getID

//------------------------------ getName ---------------------------------
// Returns a customers name, one string conjoined from the first name and
// the last
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
string Customer::getName() {
	return firstName;
} // end of getName
