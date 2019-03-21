//------------------------------ CustomerData.cpp ------------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// This class allows the construction of customer nodes and can add 
// transactions to the node. The class also has a printmethod and a contains 
// methods that checks if a customer has any transations or not.
//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------

#include "MovieF.h"
#include "MovieD.h"
#include "MovieC.h"
#include "ItemInventory.h"
#include "StoreController.h"
#include "Hashtable.h"
#include "Fileparser.h"

int main() {	

	StoreController* store = new StoreController();

	ifstream infile1("data4customers.txt");
	ifstream infile2("data4movies.txt");
	ifstream infile3("data4commands.txt");

	Fileparser parser;

	parser.parseCustomers(infile1, store);
	parser.parseMovies(infile2, store);
	parser.parseCommands(infile3, store);

		
	return 1;
}