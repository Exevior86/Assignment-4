//-------------------------- ItemInventory.cpp -------------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorted storage for items of a particular type.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#include "ItemInventory.h"

// constructor
ItemInventory::ItemInventory() 
{
	root = NULL;
}

// destructor
ItemInventory::~ItemInventory() 
{
	deleteHelper(root);
}

//------------------------------ deleteHelper --------------------------------
// Deletes all items in the inventory.
// Preconditions: None
// Postconditions: Inventory is empty.
//----------------------------------------------------------------------------
void ItemInventory::deleteHelper(TreeNode* node) 
{
	if (node != NULL) 
	{
		deleteHelper(node->left);
		deleteHelper(node->right);
		delete node->data;
		delete node;
	}
} // end of deleteHelper

//----------------------------------- add ------------------------------------
// Adds item to the inventory according to its sorting attributes.
// Preconditions: Item is same type as other items in tree.
// Postconditions: None
//----------------------------------------------------------------------------
void ItemInventory::add(Item* newItem) 
{
	addHelper(newItem, root);
} // end of add

//------------------------------ addHelper -----------------------------------
// Helper for add.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void ItemInventory::addHelper(Item* newItem, TreeNode* &node) 
{
	if (node == NULL) 
	{
		node = new TreeNode;
		node->left = NULL;
		node->right = NULL;
		node->data = newItem;
	}
	else if (*newItem < *node->data)
	{
		addHelper(newItem, node->left);
	}	
	else if (*newItem > *node->data)
	{
		addHelper(newItem, node->right);
	}
} // end of addHelper

//------------------------------ borrowItem ----------------------------------
// Decremenets stock of given item by one.
// Preconditions: Item is same type as other items in tree.
// Postconditions: None
//----------------------------------------------------------------------------
bool ItemInventory::borrowItem(Item* newItem) const 
{
	if (find(newItem))
	{
		return borrowHelper(newItem, root);
	}
	return false;
} // end of borrowItem

//------------------------------ borrowHelper --------------------------------
// Helper for borrowItem.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
bool ItemInventory::borrowHelper(Item* newItem, TreeNode* node) const 
{
	if (node == NULL)
	{
		return false;
	}
	if (*newItem < *node->data)
	{
		return borrowHelper(newItem, node->left);
	}
	if (*newItem > *node->data)
	{
		return borrowHelper(newItem, node->right);
	}
	if (node->data->getStock() == 0)
	{
		return false;
	}
	node->data->removeStock(1);
	return true;
} // end of borrowHelper

//------------------------------ returnItem ----------------------------------
// Increments stock of given item by one.
// Preconditions: Item is same type as other items in tree.
// Postconditions: None
//----------------------------------------------------------------------------
bool ItemInventory::returnItem(Item* newItem) const 
{
	if (find(newItem))
	{
		return returnHelper(newItem, root);
	}
	return false;
} // end of returnItem

//------------------------------ returnHelper --------------------------------
// Helper for returnItem.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
bool ItemInventory::returnHelper(Item* newItem, TreeNode* node) const 
{
	if (node == NULL)
	{
		return false;
	}
	if (*newItem < *node->data)
	{
		return returnHelper(newItem, node->left);
	}
	if (*newItem > *node->data)
	{
		return returnHelper(newItem, node->right);
	}
	if (node->data->getStock() == node->data->getMaxStock())
	{
		return false;
	}
	node->data->addStock(1);
	return true;
} // end of returnHelper

//--------------------------------- find -------------------------------------
// Returns true if item exists in the inventory.
// Preconditions: Item is same type as other items in tree.
// Postconditions: None
//----------------------------------------------------------------------------
bool ItemInventory::find(Item* newItem) const 
{
	return findHelper(newItem, root);
} // end of find

//-------------------------------- findHelper --------------------------------
// Helper for find.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
bool ItemInventory::findHelper(Item* newItem, TreeNode* node) const 
{
	if (node == NULL)
	{
		return false;
	}
	if (*newItem < *node->data)
	{
		return findHelper(newItem, node->left);
	}
	if (*newItem > *node->data)
	{
		return findHelper(newItem, node->right);
	}
	return true;
} // end of findHelper

Item* ItemInventory::get(Item* match) const 
{
	return getHelper(match, root);
}

Item* ItemInventory::getHelper(Item* match, TreeNode* node) const
{
	if (node == NULL)
	{
		return NULL;
	}
	if (*match < *node->data)
	{
		return getHelper(match, node->left);
	}
	if (*match > *node->data)
	{
		return getHelper(match, node->right);
	}
	return node->data;
}

//-------------------------------- printAll ----------------------------------
// Prints all items in inventory in inorder sorting format.
// Preconditions: Item is same type as other items in tree.
// Postconditions: None
//----------------------------------------------------------------------------
void ItemInventory::printAll(ostream& out) 
{
	printHelper(root, out);
} // end of printAll

//----------------------------- printHelper ----------------------------------
// Helper for printHelper
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void ItemInventory::printHelper(TreeNode* node, ostream& out) const 
{
	if (node != NULL) 
	{
		printHelper(node->left, out);
		node->data->print(out);
		out << endl;
		printHelper(node->right, out);
	}
} // end of printHelper
