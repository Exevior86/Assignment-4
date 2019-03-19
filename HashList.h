#ifndef HASHLIST_H
#define HASHLIST_H
#include <iostream>

using namespace std;

class HashList
{

public:
	HashList();
	~HashList();
	void insert(int, string);
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

#endif // !HASHLIST_H