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
	StoreController();
	~StoreController();

	void addCustomer(Customer*);
	void addMovieC(MovieC*);
	void addMovieD(MovieD*);
	void addMovieF(MovieF*);
	bool addTransactionC(const int, MovieC*);
	bool addTransactionD(const int, MovieD*);
	bool addTransactionF(const int, MovieF*);
	void printInventory(ostream&);
	bool printTransHistory(const int, ostream&);

private:
	ItemInventory movieC;
	ItemInventory movieD;
	ItemInventory movieF;
	Hashtable customers;
};

#endif

