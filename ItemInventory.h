#ifndef ITEMINVENTORY_H
#define ITEMINVENTORY_H
#include <iostream>

using namespace std;

class ItemInventory
{
public:
	ItemInventory();
	~ItemInventory();

	void add();
	void remove();
	bool returnMovie();
	bool borrowMovie();
	string printAll();
	bool find();
};

#endif // !ITEMINVENTORY_H