#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "HashList.h"
#include "CustomerData.h"

using namespace std;

class Hashtable
{
public:
	static const int MAX_SIZE = 101;

	Hashtable();
	~Hashtable();
	void put(Customer);
	string get(const int);
	void remove(int key);
	const bool containsKey(const int);

private:
	HashList *table;
	int hash(const int);
};

#endif // !HASHTABLE_H