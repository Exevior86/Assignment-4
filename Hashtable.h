#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "HashList.h"
#include "CustomerData.h"

const int MAX_SIZE = 101;

class Hashtable
{
public:
	Hashtable();
	~Hashtable();
	void put(Customer*);
	Customer* get(const int);
	bool containsKey(const int) const;

private:
	HashList *table;
	int hash(const int) const;
};

#endif // !HASHTABLE_H