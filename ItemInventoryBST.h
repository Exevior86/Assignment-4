#ifndef ITEMINVENTORY_H
#define ITEMINVENTORY_H
#include <iostream>
using namespace std;

class ItemInventoryBST
{
public:
	ItemInventoryBST();
	~ItemInventoryBST();
	void add();
	void remove();
	const bool borrowMovie();
	const bool returnMovie();
	bool find();
	string printAll();

private:
	struct itemNode {
		itemNode* left;
		itemNode* right;
	};
	itemNode* root;
};

#endif // !ITEMINVENTORY_H