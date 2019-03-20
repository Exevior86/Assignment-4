//------------------------------ HashList.h ------------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// The header file for HashList.cpp, contains all of the function definitions
// for the methods used and defines a hashlist structure.
//----------------------------------------------------------------------------

#ifndef HASHLIST_H
#define HASHLIST_H
#include <iostream>
#include "CustomerData.h"

using namespace std;

class HashList
{

public:
	HashList();									// Constructor
	~HashList();								// Deconstructor
	void insert(int, Customer*);				// Inserts a hashNode into a hashlist
	bool contains(const int) const;				// Returns if a list contains an id or not
	Customer* get(const int key) const;			// Returns a customer for a hashlist

private:
	struct HashNode{
		int key;								// A node's key for hashing
		Customer* value;						// Pointer to a node's value
		HashNode* next;							// Pointer to the next node
	};
	HashNode* root;								// Pointer to the start of a list

	void deleteHelper(HashNode* node);			// A helper method for deleting a list
};

#endif