#include "HashList.h"
using namespace std;

HashList::HashList()
{
	root = NULL;
}

HashList::~HashList()
{
}

void HashList::insert(int num, string name) 
{
	HashNode *newNode = new HashNode;
	newNode->value = name;
	newNode->key = num;
	newNode->next = root;
	root = newNode;
}

void HashList::remove(const int key) 
{
	if (root == NULL) {
		return;
	}

	if (root->key == key) {
		HashNode* temp = root->next;
		delete root;
		root = temp;
		return;
	}

	if (contains(key)) 
	{
		HashNode *start = root;

		while (start->next->key != key) {
			start = start->next;
		}

		HashNode* temp = start->next->next;
		delete start->next;
		start->next = temp;
	}
}

const bool HashList::contains(const int key) 
{
	HashNode *start = root;

	while (start != NULL && start->key != key) {
		start = start->next;
	}

	return start != NULL;
}

const string HashList::get(const int key) {
	HashNode *start = root;

	if (contains(key))
	{
		while (start != NULL && start->key != key) {
			start = start->next;
		}

		return start->value;
	}
	else 
		return "Error item doesn't exist";
}