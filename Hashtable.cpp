#include "Hashtable.h"
#include <iostream>

using namespace std;


Hashtable::Hashtable()
{
	table = new HashList[MAX_SIZE];

}


Hashtable::~Hashtable()
{
}

string Hashtable::get(const int key)
{
	int index = hash(key);

	return table[index].get(key);
}

void Hashtable::put(const int key,const string value)
{
	int index = hash(key);

	table[index].insert(key, value);
}

const bool Hashtable::containsKey(const int key) {
	int index = hash(key);

	return table[index].contains(key);
}

void Hashtable::remove(const int key)
{
	int index = hash(key);

	table[index].remove(key);
}

int Hashtable::hash(const int num)
{
	return num % MAX_SIZE;
}