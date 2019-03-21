//------------------------------ HashTable.h ------------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// The header file for HashTable.cpp, contains all the definitions for the 
// methods used.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "HashList.h"
#include "CustomerData.h"

const int MAX_SIZE = 101;					// A constant size for a hashtable

class Hashtable
{
public:
	Hashtable();							// Constructor
	~Hashtable();							// Destructor
	void put(Customer*);					// Puts a Customer in a hash table
	Customer* get(const int);				// Gets a customer from a given hash table
	bool containsKey(const int) const;		// Returns true if a hash table contains 
											// a customer key, false if not

private:
	HashList *table;						// Pointer to a hashtable
	int hash(const int) const;				// Function to hash a customer id
};

#endif // !HASHTABLE_H