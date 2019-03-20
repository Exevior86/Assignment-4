#include "Hashtable.h"
#include <iostream>

using namespace std;

Hashtable::Hashtable()
{
	table = new HashList[MAX_SIZE];
}

Hashtable::~Hashtable() {}

Customer* Hashtable::get(const int key)
{
	return table[hash(key)].get(key);
}

void Hashtable::put(Customer* customer)
{
	const int index = hash(customer->getID());
	table[index].insert(customer->getID(), customer);
}

bool Hashtable::containsKey(const int key) const 
{
	return table[hash(key)].contains(key);
}

int Hashtable::hash(const int key) const
{
	return key % MAX_SIZE;
}