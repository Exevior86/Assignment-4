#ifndef HASHLIST_H
#define HASHLIST_H
#include <iostream>
#include "CustomerData.h"

using namespace std;

class HashList
{

public:
	HashList();
	~HashList();
	void insert(int, Customer*);
	bool contains(const int) const;
	Customer* get(const int key) const;

private:
	struct HashNode{
		int key;
		Customer* value;
		HashNode* next;
	};
	HashNode* root;

	void deleteHelper(HashNode* node);
};

#endif