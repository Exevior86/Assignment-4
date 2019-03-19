#include "ItemInventory.h"

ItemInventory::ItemInventory() {
	root = NULL;
}

ItemInventory::~ItemInventory() {
	deleteHelper(root);
}

void ItemInventory::deleteHelper(TreeNode* node) {
	if (node != NULL) 
	{
		deleteHelper(node->left);
		deleteHelper(node->right);
		delete node->data;
		delete node;
	}
}

void ItemInventory::add(Item* newItem) {
	addHelper(newItem, root);
}

void ItemInventory::addHelper(Item* newItem, TreeNode* &node) {
	if (node == NULL) 
	{
		node = new TreeNode;
		node->left = NULL;
		node->right = NULL;
		node->data = newItem;
	}
	else if (*newItem < *node->data)
		addHelper(newItem, node->left);
	else if (*newItem > *node->data)
		addHelper(newItem, node->right);
}

bool ItemInventory::borrowItem(Item* newItem) const {
	if (find(newItem))
		return borrowHelper(newItem, root);
	return false;
}

bool ItemInventory::borrowHelper(Item* newItem, TreeNode* node) const {
	if (node == NULL)
		return false;
	if (*newItem < *node->data)
		return borrowHelper(newItem, node->left);
	if (*newItem > *node->data)
		return borrowHelper(newItem, node->right);
	if (node->data->getStock() == 0)
		return false;
	node->data->removeStock(1);
	return true;
}

bool ItemInventory::returnItem(Item* newItem) const {
	if (find(newItem))
		return returnHelper(newItem, root);
	return false;
}

bool ItemInventory::returnHelper(Item* newItem, TreeNode* node) const {
	if (node == NULL)
		return false;
	if (*newItem < *node->data)
		return returnHelper(newItem, node->left);
	if (*newItem > *node->data)
		return returnHelper(newItem, node->right);
	if (node->data->getStock() == node->data->getMaxStock())
		return false;
	node->data->addStock(1);
	return true;
}

bool ItemInventory::find(Item* newItem) const {
	return findHelper(newItem, root);
}

bool ItemInventory::findHelper(Item* newItem, TreeNode* node) const {
	if (node == NULL)
		return false;
	if (*newItem < *node->data)
		return findHelper(newItem, node->left);
	if (*newItem > *node->data)
		return findHelper(newItem, node->right);
	return true;
}

void ItemInventory::printAll(ostream& out) {
	printHelper(root, out);
}

void ItemInventory::printHelper(TreeNode* node, ostream& out) const {
	if (node != NULL) {
		printHelper(node->left, out);
		node->data->print(out);
		out << endl;
		printHelper(node->right, out);
	}
}
