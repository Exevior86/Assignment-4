//------------------------------ HashTable.cpp ------------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// This class allows the creation of a hashtable and inserting customer lists
// inside the table.  The class allows for construction of a hashtable, 
// putting lists inside the table, getting a customer, hashing a key,
// and returning whether a table contains a customer or not.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#include "Hashtable.h"
#include <iostream>

using namespace std;

// constructor
Hashtable::Hashtable()
{
	table = new HashList[MAX_SIZE];
} // end of constructor

// destructor
Hashtable::~Hashtable() {}

//------------------------------ get ---------------------------------
// Adds customer to the store inventory if it does not already exist
// Preconditions: Customer does not already exist.
// Postconditions: None
//----------------------------------------------------------------------------
Customer* Hashtable::get(const int key)
{
	return table[hash(key)].get(key);
} // end of get

//------------------------------ put ---------------------------------
// Adds customer to the store inventory if it does not already exist
// Preconditions: Customer does not already exist.
// Postconditions: None
//----------------------------------------------------------------------------
void Hashtable::put(Customer* customer)
{
	const int index = hash(customer->getID());
	table[index].insert(customer->getID(), customer);
} // end of put

//------------------------------ containsKey ---------------------------------
// Adds customer to the store inventory if it does not already exist
// Preconditions: Customer does not already exist.
// Postconditions: None
//----------------------------------------------------------------------------
bool Hashtable::containsKey(const int key) const 
{
	return table[hash(key)].contains(key);
} // end of containsKey

//------------------------------ hash ---------------------------------
// Adds customer to the store inventory if it does not already exist
// Preconditions: Customer does not already exist.
// Postconditions: None
//----------------------------------------------------------------------------
int Hashtable::hash(const int key) const
{
	return key % MAX_SIZE;
} // end of hash