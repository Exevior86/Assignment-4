#include "HashList.h"
#include "CustomerData.h"
using namespace std;

HashList::HashList()
{
	root = NULL;
}

HashList::~HashList() 
{
	deleteHelper(root);
}

void HashList::deleteHelper(HashNode* node)
{
	if (node != NULL) 
	{
		deleteHelper(node->next);
		delete node->value;
	}
}

void HashList::insert(int num, Customer* cust) 
{
	HashNode *newNode = new HashNode;
	newNode->value = cust;
	newNode->key = num;
	newNode->next = root;
	root = newNode;
}

bool HashList::contains(const int key) const
{
	HashNode *start = root;

	while (start != NULL && start->key != key) 
	{
		start = start->next;
	}

	return start != NULL;
}

Customer* HashList::get(const int key) const {
	HashNode *start = root;

	if (contains(key))
	{
		while (start != NULL && start->key != key) 
		{
			start = start->next;
		}

		return start->value;
	}
	return NULL;
}