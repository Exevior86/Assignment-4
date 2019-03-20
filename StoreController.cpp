//------------------------------ Name.cpp ------------------------------------
// Vlad Netrebchenko CSS 343 C
// Date started
// Date finished
//----------------------------------------------------------------------------
// Description of what the files does
//----------------------------------------------------------------------------
// Any special requirements or algorithms
//----------------------------------------------------------------------------

#include "StoreController.h"

// constructor
StoreController::StoreController() {}

// destructor
StoreController::~StoreController() {}

//------------------------------ addCustomer ---------------------------------
// Adds customer to the store inventory if it does not already exist
// Preconditions: Customer does not already exist.
// Postconditions: None
//----------------------------------------------------------------------------
void StoreController::addCustomer(Customer* cust) 
{
	customers.put(cust);
} // end of addCustomer

void StoreController::addMovieC(MovieC* movie) 
{
	movieC.add(movie);
}

void StoreController::addMovieD(MovieD* movie) 
{
	movieD.add(movie);
}

void StoreController::addMovieF(MovieF* movie) 
{
	movieF.add(movie);
}

bool StoreController::addTransactionC(const int id, MovieC* movie) 
{
	if (customers.containsKey(id) && movieC.find(movie))
	{
		customers.get(id)->addTransaction(movie);
		return true;
	}
	return false;
}

bool StoreController::addTransactionD(const int id, MovieD* movie) 
{
	if (customers.containsKey(id) && movieD.find(movie))
	{
		customers.get(id)->addTransaction(movie);
		return true;
	}
	return false;
}

bool StoreController::addTransactionF(const int id, MovieF* movie) 
{
	if (customers.containsKey(id) && movieF.find(movie))
	{
		customers.get(id)->addTransaction(movie);
		return true;
	}
	return false;
}

void StoreController::printInventory(ostream& out) 
{
	out << "Comedy Movies _________________________________" << endl;
	movieF.printAll(out);
	out << endl << "Drama Movies _________________________________" << endl;
	movieD.printAll(out);
	out << endl << "Classic Movies _________________________________" << endl;
	movieC.printAll(out);
}

bool StoreController::printTransHistory(const int id, ostream& out) 
{
	if (customers.containsKey(id))
	{
		customers.get(id)->printHistory(out);
		return true;
	}
	return false;
}