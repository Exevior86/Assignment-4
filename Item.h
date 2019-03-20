//------------------------------- Item.h -------------------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorting and storage for item attributes.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

class Item
{
public:
	// constructor
	Item(const int);

	// destructor
	~Item();

	//------------------------------ getStock ------------------------------------
	// Returns current item stock.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	int getStock() const;

	//------------------------------ getMaxStock ---------------------------------
	// Returns max item stock.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	int getMaxStock() const;

	//------------------------------ addStock ------------------------------------
	// Add to current stock.
	// Preconditions: None
	// Postconditions: Does not exceed max stock.
	//----------------------------------------------------------------------------
	void addStock(const int);

	//------------------------------ removeStock ---------------------------------
	// Remove from current stock.
	// Preconditions: None
	// Postconditions: Does not go less than zero.
	//----------------------------------------------------------------------------
	void removeStock(const int);

	//------------------------------ addMaxStock ---------------------------------
	// Add to max stock.
	// Preconditions: None
	// Postconditions: Max stock never goes below 0;
	//----------------------------------------------------------------------------
	void addMaxStock(const int);

	//------------------------------ operator< -----------------------------------
	// Returns true if this item has lower stock.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	virtual bool operator<(const Item&) const;

	//------------------------------ operator> -----------------------------------
	// Returns true if this item has greater stock.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	virtual bool operator>(const Item&) const;

	//---------------------------------- print -----------------------------------
	// Prints stock of item.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	virtual void print(ostream& out);

protected:
	int stock;		// current stock of item
	int maxStock;	// max stock of item
};

#endif