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

void Customer::addTransaction(string command, string movieTitle)
{
	TransactionNode *toAdd = new TransactionNode;
	toAdd->type = command;
	toAdd->movie = movieTitle;
	toAdd->next = NULL;

	if (head == NULL)
	{
		head = toAdd;
	}
	else {
		toAdd->next = head;
		head = toAdd;
	}
}

const bool Customer::containsTransaction(const Customer root)
{
	if (root.head == NULL)
		return false;
	else
		return true;
}

void Customer::removeTransaction(string command, string movieTitle)
{
	TransactionNode *start = head;
	if (start == NULL)
		return;
	else
		while (start->next->type != command && start->next->movie != movieTitle) {
			start = start->next;
		}

	TransactionNode* temp = start->next->next;
	delete start->next;
	start->next = temp;
}


string Customer::printHistory()
{
	TransactionNode *temp = head;
	
	if (temp == NULL)
		return "NO Transaction Data";
	else
		while (temp != NULL)
		{
			cout << "Transaction " << temp->type << " " << temp->movie << endl;
			temp = temp->next;
		}
		return " ";
}


int Customer::getID() {
	return id;
}

string Customer::getName() {
	string name = lastName + ", " + firstName;
	return name;
}
