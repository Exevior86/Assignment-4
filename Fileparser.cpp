//------------------------------ Name.cpp ------------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Description of what the files does
//----------------------------------------------------------------------------
// Any special requirements or algorithms
//----------------------------------------------------------------------------

#include "Fileparser.h"
#include <sstream>
#include <string>
#include <iostream>


using namespace std;

// constructor
Fileparser::Fileparser()
{
}

//------------------------- Constructor ---------------------------------
// Description: Creates a graph with infinity values, sets all
// nodes to not visited, distances to infinity, and paths to zero
// --------------------------------------------------------------
Fileparser::~Fileparser()
{
}

//------------------------- Constructor ---------------------------------
// Description: Creates a graph with infinity values, sets all
// nodes to not visited, distances to infinity, and paths to zero
// --------------------------------------------------------------
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

void Fileparser::parseCommands(ifstream& infile, StoreController *store) {

	string line;
	string token;
	string ID;

	while (getline(infile, line)) {

		token = line.substr(0,1);

		if (token == "I") {
			cout << "Printing Inventory" << endl;
		}

		else if (token == "H") {
			ID = line.substr(line.length() - 4, 4);
			int custID = stoi(ID);
			cout << "Printing History" << endl;
			cout << "Customer ID is = " << custID << endl;

			store->printTransHistory(custID, cout);
		}

		else if (token == "B" || token == "R") {
			string delimeter = ",";
			ID = line.substr(2, 4);
			string type = line.substr(9, 1);
			string date;
			string director;
			string actorName;
			string movieTitle;
			string month;
			string year;
			string brokenLine = line.substr(10, line.length());

			istringstream stream(line);
			if (type == "C") {
				date = line.substr(11, 6);
				month = date.substr(0, 1);
				year = date.substr(2, 4);
				actorName = line.substr(18, line.length());

				//cout << "****************** Returning " << type << " Movie **************" << endl;
				//cout << "actor name = " << actorName << endl;
				//cout << "date = " << date << endl;
				//cout << "month = " << month << endl;
				//cout << "year = " << year << endl;

				MovieC *movie = new MovieC(1, "placeholder", "placeholder", actorName, stoi(month), stoi(year));
				store->addTransactionC(stoi(ID), movie);
			}

			else if (type == "F") {
				date = line.substr(line.length() - 4, 4);
				movieTitle = brokenLine.substr(1, brokenLine.find(delimeter) - 1);

				//cout << "****************** Borrowing " << type << " Movie **************" << endl;
				//cout << "movieTitle = " << movieTitle << endl;
				//cout << "date = " << date << endl;

				MovieF *movie = new MovieF(1, movieTitle, "placeholder", stoi(date));
				store->addTransactionF(stoi(ID), movie);
			}

			else if (type == "D") {
				director = brokenLine.substr(1, brokenLine.find(delimeter) - 1);

				movieTitle = brokenLine.substr(director.length() + 2, brokenLine.length());
				movieTitle = movieTitle.substr(1, movieTitle.length() - 2);

				MovieD *movie = new MovieD(1, movieTitle, director, 1121);
				store->addTransactionD(stoi(ID), movie);

				//cout << "****************** Borrowing " << type << " Movie **************" << endl;
				//cout << "director = " << director << endl;
				//cout << "movie Title = " << movieTitle << endl;
			}

			else
				cout << "Incorrect type!" << endl;
		}
		else
			cout << "Invalid command" << endl;
	}

}

bool Fileparser::hasNext() {
	return false;
}

string Fileparser::nextLine() {
	return "Flocka";
}