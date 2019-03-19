#ifndef ITEMINVENTORY_H
#define ITEMINVENTORY_H
#include <iostream>
#include "Item.h"

using namespace std;

class ItemInventory
{
public:
	ItemInventory();
	~ItemInventory();

	void add(Item*);
	bool returnItem(Item*) const;
	bool borrowItem(Item*) const;
	bool find(Item*) const;
	void printAll(ostream&);

private:
	struct TreeNode {
		Item* data;
		TreeNode* left;
		TreeNode* right;
	};
	TreeNode* root;

	void addHelper(Item*, TreeNode*&);
	bool borrowHelper(Item*, TreeNode*) const;
	bool returnHelper(Item*, TreeNode*) const;
	void deleteHelper(TreeNode*);
	bool findHelper(Item*, TreeNode*) const;
	void printHelper(TreeNode*, ostream&) const;
};

#endif