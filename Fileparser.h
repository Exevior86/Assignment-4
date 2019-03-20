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
	Fileparser();
	~Fileparser();

	void parseCustomers(ifstream&, StoreController*);
	void parseMovies(ifstream&, StoreController*);
	void parseCommands(ifstream&, StoreController*);
};

#endif // !FILEPARSER_H