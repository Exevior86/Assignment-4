#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <iostream>
#include <string>
#include <fstream>
#include "CustomerData.h"

using namespace std;

class Fileparser
{
public:
	Customer parseCustomers(ifstream&); //NEED ATTENTION
	void parseMovies(ifstream&);
	void parseCommands(ifstream&);

	bool hasNext();
	string nextLine();

	Fileparser();
	~Fileparser();


};

#endif // !FILEPARSER_H