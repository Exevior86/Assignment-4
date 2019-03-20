#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "Item.h"
#include <iostream>

using namespace std;

class Customer {
public:
	Customer();
	Customer(int, string, string);
	~Customer();

	void addTransaction(Item*);
	void removeTransaction(Item*);
	const bool containsTransaction();
	string getName();
	int getID();
	void printHistory(ostream&);

private:
	
	struct TransactionNode {
		Item* movie;
		TransactionNode* next;
	};
	int id;
	string firstName;
	string lastName;
	TransactionNode* head;
};

#endif // !CUSTOMERDATA_H