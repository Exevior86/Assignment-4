#include "Fileparser.h"
#include "MovieC.h"
#include "MovieD.h"
#include "MovieF.h"
#include <iostream>
#include <sstream>

using namespace std;

Fileparser::Fileparser() {}

Fileparser::~Fileparser() {}

void Fileparser::parseCustomers(ifstream& infile, StoreController* store) 
{
	string id;
	string first;
	string last;

	// for every customer, get the id, last name, and first name
	while (infile >> id >> last >> first) 
	{
		Customer* customer = new Customer(stoi(id), first, last);
		store->addCustomer(customer);
	}
}

void Fileparser::parseMovies(ifstream& infile, StoreController* store) 
{
	// get the next line in the movies file
	string line;
	while (getline(infile, line)) 
	{
		istringstream stream(line);
		string token;

		// break apart the line along the commas
		while (getline(stream, token, ',')) 
		{
			int stock;
			string director;
			string title;
			string actor;

			if (token == "C") 
			{
				// parse stock
				getline(stream, token, ',');
				stock = stoi(token);

				// parse director
				getline(stream, token, ',');
				director = token.substr(1, token.length());

				// parse title
				getline(stream, token, ',');
				title = token.substr(1, token.length());

				// parse actor
				getline(stream, token, ',');
				actor = token.substr(1, token.length() - 8);
				if (actor.at(actor.length() - 1) == ' ') 
				{
					actor = actor.substr(0, actor.length() - 1);
				}

				// parse the month and year
				string date = token.substr(token.length() - 7, token.length());
				int year = stoi(date.substr(date.length() - 4, date.length()));
				int month = stoi(date.substr(0, 4));

				// add to store inventory
				store->addMovieC(new MovieC(stock, title, director, actor, month, year));
			}
			else if (token == "D") 
			{
				// parse stock
				getline(stream, token, ',');
				stock = stoi(token);

				// parse director
				getline(stream, token, ',');
				director = token.substr(1, token.length());

				// parse title
				getline(stream, token, ',');
				title = token.substr(1, token.length());

				// parse year
				getline(stream, token, ',');
				string yr = token.substr(1, token.length());

				// add to inventory
				store->addMovieD(new MovieD(stock, title, director, stoi(yr)));
			}
			else if (token == "F") 
			{
				// parse stock
				getline(stream, token, ',');
				stock = stoi(token);

				// parse director
				getline(stream, token, ',');
				director = token.substr(1, token.length());

				// parse title
				getline(stream, token, ',');
				title = token.substr(1, token.length());

				// parse year
				getline(stream, token, ',');
				string yr = token.substr(1, token.length());

				// add to inventory
				store->addMovieF(new MovieF(stock, title, director, stoi(yr)));
			}
			else 
			{
				// print error message for incorrect movie type
				cout << "Please input movies that are of type F, D, or C." << endl;
				break;
			}
		}
	}
}

void Fileparser::parseCommands(ifstream& infile, StoreController* store) 
{
	string line;
	string token;
	string ID;

	while (getline(infile, line)) 
	{
		token = line.substr(0, 1);

		if (token == "I") 
		{
			store->printInventory(cout);
		}
		else if (token == "H") 
		{
			ID = line.substr(line.length() - 4, 4);
			int custID = stoi(ID);
			bool customerExists = store->printTransHistory(custID, cout);
			if (!customerExists) 
			{
				cout << "Customer does not exist" << endl;
			}
		}
		else if (token == "B" || token == "R") 
		{
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

				MovieC *movie = new MovieC(1, "placeholder", "placeholder", actorName, stoi(month), stoi(year));
				bool instock = store->addTransactionC((token == "B") ? "Borrow" : "Return", stoi(ID), movie);
				if (!instock)
				{
					cout << "Please check if customer and movie exist. ";
					cout << "Movie may be out of stock, please select another one." << endl;
				}
				delete movie;
			}

			else if (type == "F") {
				date = line.substr(line.length() - 4, 4);
				movieTitle = brokenLine.substr(1, brokenLine.find(delimeter) - 1);

				MovieF *movie = new MovieF(1, movieTitle, "placeholder", stoi(date));
				bool instock = store->addTransactionF((token == "B") ? "Borrow" : "Return", stoi(ID), movie);
				if (!instock)
				{
					cout << "Please check if customer and movie exist. ";
					cout << "Movie may be out of stock, please select another one." << endl;
				}
				delete movie;
			}

			else if (type == "D") {
				director = brokenLine.substr(1, brokenLine.find(delimeter) - 1);

				movieTitle = brokenLine.substr(director.length() + 2, brokenLine.length());
				movieTitle = movieTitle.substr(1, movieTitle.length() - 2);

				MovieD *movie = new MovieD(1, movieTitle, director, 1121);
				bool instock = store->addTransactionD((token == "B") ? "Borrow" : "Return", stoi(ID), movie);
				if (!instock)
				{
					cout << "Please check if customer and movie exist. ";
					cout << "Movie may be out of stock, please select another one." << endl;
				}
				delete movie;
			}

			else
				cout << "Movie type does not exist, please select another one." << endl;
		}
		else
			cout << "Invalid command." << endl;
	}
}