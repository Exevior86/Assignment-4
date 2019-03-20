//-------------------------- ItemInventory.h ---------------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorted storage for items of a particular type.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#ifndef ITEMINVENTORY_H
#define ITEMINVENTORY_H
#include <iostream>
#include "Item.h"

using namespace std;

class ItemInventory
{
public:
	// constructor
	ItemInventory();
	
	// destructor
	~ItemInventory();

	//----------------------------------- add ------------------------------------
	// Adds item to the inventory according to its sorting attributes.
	// Preconditions: Item is same type as other items in tree.
	// Postconditions: None
	//----------------------------------------------------------------------------
	void add(Item*);

	//------------------------------ returnItem ----------------------------------
	// Increments stock of given item by one.
	// Preconditions: Item is same type as other items in tree.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool returnItem(Item*) const;

	//------------------------------ borrowItem ----------------------------------
	// Decremenets stock of given item by one.
	// Preconditions: Item is same type as other items in tree.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool borrowItem(Item*) const;

	//--------------------------------- find -------------------------------------
	// Returns true if item exists in the inventory.
	// Preconditions: Item is same type as other items in tree.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool find(Item*) const;

	Item* get(Item*) const;

	//-------------------------------- printAll ----------------------------------
	// Prints all items in inventory in inorder sorting format.
	// Preconditions: Item is same type as other items in tree.
	// Postconditions: None
	//----------------------------------------------------------------------------
	void printAll(ostream&);

private:
	struct TreeNode {
		Item* data;
		TreeNode* left;
		TreeNode* right;
	};
	TreeNode* root;

	//------------------------------ addHelper -----------------------------------
	// Helper for add.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	void addHelper(Item*, TreeNode*&);

	//------------------------------ borrowHelper --------------------------------
	// Helper for borrowItem.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool borrowHelper(Item*, TreeNode*) const;

	//------------------------------ returnHelper --------------------------------
	// Helper for returnItem.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool returnHelper(Item*, TreeNode*) const;

	//------------------------------ deleteHelper --------------------------------
	// Deletes all items in the inventory.
	// Preconditions: None
	// Postconditions: Inventory is empty.
	//----------------------------------------------------------------------------
	void deleteHelper(TreeNode*);

	//-------------------------------- findHelper --------------------------------
	// Helper for find.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool findHelper(Item*, TreeNode*) const;

	Item* getHelper(Item* match, TreeNode* node) const;

	//----------------------------- printHelper ----------------------------------
	// Helper for printHelper
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	void printHelper(TreeNode*, ostream&) const;
};

#endif