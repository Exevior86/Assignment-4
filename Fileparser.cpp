//-------------------------- Fileparser.cpp ----------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Parses input files into the store controller.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#include "Fileparser.h"
#include "MovieC.h"
#include "MovieD.h"
#include "MovieF.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// constructor
Fileparser::Fileparser() {}

// destructor
Fileparser::~Fileparser() {}

//------------------------------ parseCustomers ------------------------------
// Deletes all items in the inventory.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void Fileparser::parseCustomers(ifstream& infile, StoreController* store) 
{
	string line;
	string id;
	string first;
	string last;

	// for every customer, get the id, last name, and first name
	while (getline(infile, line)) 
	{
		id = line.substr(0, 4);
		first = line.substr(5, line.length());

		Customer* customer = new Customer(stoi(id), first);
		store->addCustomer(customer);
	}
} // end of parseCustomers

//------------------------------ parseMovies ---------------------------------
// Parses and adds movies into the store.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
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
			string month;
			string year;

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
				bool encounteredNumber = false;
				while (!encounteredNumber)
				{
					string temp;
					stream >> temp;
					encounteredNumber = true;

					for (int i = 0; i < temp.length(); i++)
					{
						if (!isdigit(temp.at(i)))
						{
							encounteredNumber = false;
							if (actor == "")
							{
								actor = temp;
							}
							else
							{
								actor += " " + temp;
							}
							break;
						}
					}

					if (encounteredNumber)
					{
						month = temp;
						stream >> year;
					}
				}; 

				getline(stream, token, ',');

				// add to store inventory
				store->addMovieC(new MovieC(stock, title, director, actor, stoi(month), stoi(year)));
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
				for (int i = 0; i < 5; i++)
				{
					getline(stream, token, ',');
				}

				// print error message for incorrect movie type
				cout << "Please input movies that are of type F, D, or C." << endl;
				break;
			}
		}
	}
} // end of parseMovies

//------------------------------ parseCommands -------------------------------
// Parses and acts out all valid commands in the file.
// Preconditions: None
// Postconditions: None.
//----------------------------------------------------------------------------
void Fileparser::parseCommands(ifstream& infile, StoreController* store) 
{
	string line;
	string token;
	string ID;
	string type;

	while (getline(infile, line)) 
	{
		istringstream stream(line);

		stream >> token;

		if (token == "I") 
		{
			store->printInventory(cout);
		}
		else if (token == "H") 
		{
			stream >> ID;
			int custID = stoi(ID);

			bool customerExists = store->printTransHistory(custID, cout);

			if (!customerExists) 
			{
				cout << "Customer does not exist" << endl;
			}
		}
		// parse B and R commands
		else if (token == "B" || token == "R") 
		{
			string date;
			string director;
			string actorFirst;
			string actorLast;
			string movieTitle;
			string month;
			string year;
			string genre;

			stream >> ID;
			stream >> genre;
			stream >> type;

			// C type movies
			if (type == "C") 
			{
				stream >> month;
				stream >> year;
				stream >> actorFirst;
				stream >> actorLast;

				string actorName = actorFirst + " " + actorLast;

				// create new movie and add it to the customer's transactions, or print error message
				MovieC *movie = new MovieC(1, "placeholder", "placeholder", actorName, stoi(month), stoi(year));
				bool instock = store->addTransactionC((token == "B") ? "Borrow" : "Return", stoi(ID), movie);
				if (!instock)
				{
					cout << "Please check if customer and movie exist. ";
					cout << "Movie may be out of stock, please select another one." << endl;
				}
				delete movie;
			}

			// F type movies
			else if (type == "F") 
			{
				getline(stream, movieTitle, ',');
				movieTitle = movieTitle.substr(1, movieTitle.length());
				stream >> date;

				// create new movie and add it to the customer's transactions, or print error message
				MovieF *movie = new MovieF(1, movieTitle, "placeholder", stoi(date));
				bool instock = store->addTransactionF((token == "B") ? "Borrow" : "Return", stoi(ID), movie);
				if (!instock)
				{
					cout << "Please check if customer and movie exist. ";
					cout << "Movie may be out of stock, please select another one." << endl;
				}
				delete movie;
			}

			// D type movies
			else if (type == "D") 
			{
				getline(stream, director, ',');
				director = director.substr(1, director.length());

				getline(stream, movieTitle, ',');
				movieTitle = movieTitle.substr(1, movieTitle.length());

				// create new movie and add it to the customer's transactions, or print error message
				MovieD *movie = new MovieD(1, movieTitle, director, 1121);
				bool instock = store->addTransactionD((token == "B") ? "Borrow" : "Return", stoi(ID), movie);
				if (!instock)
				{
					cout << "Please check if customer and movie exist. ";
					cout << "Movie may be out of stock, please select another one." << endl;
				}
				delete movie;
			}

			// Incorrect type
			else
				cout << "Movie type does not exist, please select another one." << endl;
		}
		else
			cout << "Invalid command." << endl;
	}
} // end of parseCommands