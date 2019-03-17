#include <iostream>
#include "HashList.h"
using namespace std;

class Hashtable
{
public:
	static const int MAX_SIZE = 101;

	Hashtable();
	~Hashtable();
	void put(int, string);
	string get(const int);
	void remove(int key);
	const bool containsKey(const int);

private:
	HashList *table;
	int hash(const int);
};

