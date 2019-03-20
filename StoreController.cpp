//-------------------------- StoreController.cpp -----------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides all required functionality for store management and encapsulates
// all internal modules.
//----------------------------------------------------------------------------
// 
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

//------------------------------ addMovieC -----------------------------------
// Adds classic movie to the respective inventory
// Preconditions: Movie does not already exist in inventory.
// Postconditions: None
//----------------------------------------------------------------------------
void StoreController::addMovieC(MovieC* movie) 
{
	movieC.add(movie);
} // end of addMovieC

//------------------------------ addMovieD -----------------------------------
// Adds drama movie to the respective inventory
// Preconditions: Movie does not already exist in inventory.
// Postconditions: None
//----------------------------------------------------------------------------
void StoreController::addMovieD(MovieD* movie) 
{
	movieD.add(movie);
} // end of addMovieD

//------------------------------ addMovieF -----------------------------------
// Adds comedy movie to the respective inventory
// Preconditions: Movie does not already exist in inventory.
// Postconditions: None
//----------------------------------------------------------------------------
void StoreController::addMovieF(MovieF* movie) 
{
	movieF.add(movie);
} // end of addMovieF

//--------------------------- addTransactionC --------------------------------
// Adds classic movie transaction to the customer with the given id.
// Preconditions: Customer and movie exist in store.
// Postconditions: None
//----------------------------------------------------------------------------
bool StoreController::addTransactionC(const string type, const int id, MovieC* movie)
{
	if (customers.containsKey(id) && movieC.find(movie))
	{
		if (type == "Borrow")
		{
			movieC.borrowItem(movie);
		}
		else
		{
			movieC.returnItem(movie);
		}
		customers.get(id)->addTransaction(type, movieC.get(movie));
		return true;
	}
	return false;
} // end of addTransactionC

//--------------------------- addTransactionD --------------------------------
// Adds drama movie transaction to the customer with the given id.
// Preconditions: Customer and movie exist in store.
// Postconditions: None
//----------------------------------------------------------------------------
bool StoreController::addTransactionD(const string type, const int id, MovieD* movie)
{
	if (customers.containsKey(id) && movieD.find(movie))
	{
		if (type == "Borrow")
		{
			movieD.borrowItem(movie);
		}
		else
		{
			movieD.returnItem(movie);
		}
		customers.get(id)->addTransaction(type, movieD.get(movie));
		return true;
	}
	return false;
} // end of addTransactionD

//--------------------------- addTransactionF --------------------------------
// Adds drama movie transaction to the customer with the given id.
// Preconditions: Customer and movie exist in store.
// Postconditions: None
//----------------------------------------------------------------------------
bool StoreController::addTransactionF(const string type, const int id, MovieF* movie)
{
	if (customers.containsKey(id) && movieF.find(movie))
	{
		if (type == "Borrow")
		{
			movieF.borrowItem(movie);
		}
		else
		{
			movieF.returnItem(movie);
		}
		customers.get(id)->addTransaction(type, movieF.get(movie));
		return true;
	}
	return false;
} // end of addTransactionF

//--------------------------- printInventory ---------------------------------
// Prints all item inventories in the store.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void StoreController::printInventory(ostream& out) 
{
	out << endl;
	out << "****************** Comedy Movies ******************" << endl;
	movieF.printAll(out);
	out << endl << "****************** Drama Movies ******************" << endl;
	movieD.printAll(out);
	out << endl << "****************** Classic Movies ******************" << endl;
	movieC.printAll(out);
	out << endl;
} // end of printInventory

//--------------------------- printTransHistory ------------------------------
// Prints transaction history for customer with given id.
// Preconditions: Customer exists in the store.
// Postconditions: None
//----------------------------------------------------------------------------
bool StoreController::printTransHistory(const int id, ostream& out) 
{
	if (customers.containsKey(id))
	{
		customers.get(id)->printHistory(out);
		return true;
	}
	return false;
} // end of printTransHistory