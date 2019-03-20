#include "CustomerData.h"
#include <iostream>
#include <string>
using namespace std;

Customer::Customer()
{
	head = NULL;
}

Customer::Customer(int num, string first, string last)
{
	id = num;
	firstName = first;
	lastName = last;
	head = NULL;
}

Customer::~Customer()
{
}

void Customer::addTransaction(Item* aMovie)
{
	TransactionNode *toAdd = new TransactionNode;
	toAdd->movie = aMovie;
	toAdd->next = NULL;

	if (head == NULL)
		head = toAdd;
	else {
		toAdd->next = head;
		head = toAdd;
	}
}

const bool Customer::containsTransaction()
{
	return head == NULL;
}

/*
void Customer::removeTransaction(Item* removeMovie)
{
	TransactionNode *start = head;
	if (start == NULL)
		return;
	else
		while (start->next->movie != removeMovie) {
			start = start->next;
		}

	TransactionNode* temp = start->next->next;
	delete start->next;
	start->next = temp;
}
*/

void Customer::printHistory(ostream& out)
{
	TransactionNode *temp = head;
	out << getName() << endl;

	if (temp == NULL)
		out << "No Prior Transactions" << endl;
	else
		while (temp != NULL)
		{
			temp->movie->print(out);
			out << endl;
			temp = temp->next;
		}
	out << endl;
}

int Customer::getID() {
	return id;
}

string Customer::getName() {
	string name = firstName + " " + lastName;
	return name;
}
