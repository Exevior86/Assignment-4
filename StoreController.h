//---------------------------- StoreController.h -----------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides all required functionality for store management and encapsulates
// all internal modules.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#ifndef STORECONTROLLER_H
#define STORECONTROLLER_H
#include <iostream>
#include "MovieF.h"
#include "MovieD.h"
#include "MovieC.h"
#include "ItemInventory.h"
#include "Hashtable.h"
#include "CustomerData.h"

class StoreController
{
public:
	// constructor
	StoreController();

	// destructor
	~StoreController();

	//------------------------------ addCustomer ---------------------------------
	// Adds customer to the store inventory if it does not already exist
	// Preconditions: Customer does not already exist.
	// Postconditions: None
	//----------------------------------------------------------------------------
	void addCustomer(Customer*);

	//------------------------------ addMovieC -----------------------------------
	// Adds classic movie to the respective inventory
	// Preconditions: Movie does not already exist in inventory.
	// Postconditions: None
	//----------------------------------------------------------------------------
	void addMovieC(MovieC*);

	//------------------------------ addMovieD -----------------------------------
	// Adds drama movie to the respective inventory
	// Preconditions: Movie does not already exist in inventory.
	// Postconditions: None
	//----------------------------------------------------------------------------
	void addMovieD(MovieD*);

	//------------------------------ addMovieF -----------------------------------
	// Adds comedy movie to the respective inventory
	// Preconditions: Movie does not already exist in inventory.
	// Postconditions: None
	//----------------------------------------------------------------------------
	void addMovieF(MovieF*);

	//--------------------------- addTransactionC --------------------------------
	// Adds classic movie transaction to the customer with the given id.
	// Preconditions: Customer and movie exist in store.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool addTransactionC(const string, const int, MovieC*);

	//--------------------------- addTransactionD --------------------------------
	// Adds drama movie transaction to the customer with the given id.
	// Preconditions: Customer and movie exist in store.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool addTransactionD(const string, const int, MovieD*);

	//--------------------------- addTransactionF --------------------------------
	// Adds drama movie transaction to the customer with the given id.
	// Preconditions: Customer and movie exist in store.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool addTransactionF(const string, const int, MovieF*);

	//--------------------------- printInventory ---------------------------------
	// Prints all item inventories in the store.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	void printInventory(ostream&);

	//--------------------------- printTransHistory ------------------------------
	// Prints transaction history for customer with given id.
	// Preconditions: Customer exists in the store.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool printTransHistory(const int, ostream&);

private:
	ItemInventory movieC;	// classic movie inventory
	ItemInventory movieD;	// drama movie inventory
	ItemInventory movieF;	// funny movie inventory
	Hashtable customers;	// collection of customers
};

#endif

