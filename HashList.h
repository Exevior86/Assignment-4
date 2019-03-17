#include <iostream>
#include "CustomerData.h"
using namespace std;

class HashList
{

public:
	HashList();
	~HashList();
	void insert(Customer);
	void remove(const int);
	const bool contains(const int);
	const string get(const int key);

private:
	struct HashNode{
		int key;
		string value;
		HashNode *next;
	};
	HashNode *root;
};

