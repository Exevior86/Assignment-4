#include "Fileparser.h"

#include <iostream>
using namespace std;


Fileparser::Fileparser()
{
}


Fileparser::~Fileparser()
{
}


Customer Fileparser::parseCustomers(ifstream& infile) { // NEED ATTENTION

	string id;
	string first;
	string last;

	Customer *newCustomer = new Customer;

	while (infile >> id >> last >> first) {

		Customer toAdd = Customer(stoi(id), first, last); // Can't build over others
	}
	return *newCustomer;
}

void Fileparser::parseMovies(ifstream& infile) {
	char a;
	infile >> a;
	switch (a) {
		case 'C':
			// build classic movie
			break;
		case 'D':
			// build drama movie 
			break;
		case 'F':
			// build commedy movie
			break;
		default:
			//
			cout << "Not a valid movie" << endl;
			break;
	}
}

void Fileparser::parseCommands(ifstream& infile) {
	char a;
	infile >> a;
	switch (a) {
	case 'B':
		// borrow
		break;
	case 'H':
		// print history
		break;
	case 'I':
		// print inventory
		break;
	case 'R':
		// build commedy movie
		break;
	default:
		//
		cout << "Not a valid Command" << endl;
		break;
	}
}

bool Fileparser::hasNext() {
	return false;
}

string Fileparser::nextLine() {
	return "Flocka";
}