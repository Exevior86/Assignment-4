//-------------------------- Fileparser.cpp ----------------------------------
// Vlad Netrebchenko & Adam Snyder CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Parses input files into the store controller.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <iostream>
#include <string>
#include <fstream>
#include "StoreController.h"

using namespace std;

class Fileparser
{
public:
	// constructor
	Fileparser();

	// destructor
	~Fileparser();

	//------------------------------ parseCustomers ------------------------------
	// Deletes all items in the inventory.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	void parseCustomers(ifstream&, StoreController*);

	//------------------------------ parseMovies ---------------------------------
	// Parses and adds movies into the store.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	void parseMovies(ifstream&, StoreController*);

	//------------------------------ parseCommands -------------------------------
	// Parses and acts out all valid commands in the file.
	// Preconditions: None
	// Postconditions: None.
	//----------------------------------------------------------------------------
	void parseCommands(ifstream&, StoreController*);
};

#endif // !FILEPARSER_H