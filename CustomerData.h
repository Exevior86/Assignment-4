#include <iostream>

using namespace std;

class Customer
{
public:
	Customer();
	Customer(int, string);
	~Customer();

	void addTransaction(string, string);
	void removeTransaction(string, string);
	const bool containsTransaction(const Customer);
	string getName();
	int getID();
	string printHistory();

private:
	
	struct TransactionNode {
		string type;
		string movie;
		TransactionNode* next;
	};
	int id;
	string name;
	TransactionNode* head;

};

