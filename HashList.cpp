//------------------------------ HashList.cpp ------------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// This class allows the creation of a hashlist. The hashlist is for 
// when there are collisions in the hashtable. Allows for creating a list, 
// inserting customer nodes, getting customers from the lsit, and returns
// whether a list contains a customer or not.
//----------------------------------------------------------------------------

#include "HashList.h"
#include "CustomerData.h"
using namespace std;

// constructor
HashList::HashList()
{
	root = NULL;
} // end of constructor

// destructor
HashList::~HashList() 
{
	deleteHelper(root);
} // end of destructor

//------------------------------ deleteHelper ---------------------------------
// A helper method for the deconstructor that traverses the list and deletes
// each node
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void HashList::deleteHelper(HashNode* node)
{
	if (node != NULL) 
	{
		deleteHelper(node->next);
		delete node->value;
	}
} // end of deleteHelper

//------------------------------ insert ---------------------------------
// Inserts a customer node into hashlist
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void HashList::insert(int num, Customer* cust) 
{
	HashNode *newNode = new HashNode;
	newNode->value = cust;
	newNode->key = num;
	newNode->next = root;
	root = newNode;
} // end of insert

//------------------------------ contains ---------------------------------
// Returns true if a hashlist contains a customer and false if it doesn't
// exist
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
bool HashList::contains(const int key) const
{
	HashNode *start = root;

	while (start != NULL && start->key != key) 
	{
		start = start->next;
	}

	return start != NULL;
} // end of contains

//------------------------------ get ---------------------------------
// returns a customer from the given hashlist
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
Customer* HashList::get(const int key) const {
	HashNode *start = root;

	if (contains(key))
	{
		while (start != NULL && start->key != key) 
		{
			start = start->next;
		}

		return start->value;
	}
	return NULL;
} // end of get