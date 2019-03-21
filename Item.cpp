//------------------------------- Item.cpp -----------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorting and storage for item attributes.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#include "Item.h"

// constructor
Item::Item(const int amount) 
{
	stock = amount;
	maxStock = amount;
}

// destructor
Item::~Item() {}

//------------------------------ getStock ------------------------------------
// Returns current item stock.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
int Item::getStock() const 
{
	return stock;
} // end of getStock

//------------------------------ getMaxStock ---------------------------------
// Returns max item stock.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
int Item::getMaxStock() const 
{
	return maxStock;
} // end of getMaxStock

//------------------------------ addStock ------------------------------------
// Add to current stock.
// Preconditions: None
// Postconditions: Does not exceed max stock.
//----------------------------------------------------------------------------
void Item::addStock(const int amount) 
{
	stock = (stock + amount > maxStock) ? maxStock : stock + amount;
} // end of addStock

//------------------------------ removeStock ---------------------------------
// Remove from current stock.
// Preconditions: None
// Postconditions: Does not go less than zero.
//----------------------------------------------------------------------------
void Item::removeStock(const int amount) 
{
	stock = (stock - amount < 0) ? 0 : stock - amount;
} // end of removeStock

//------------------------------ addMaxStock ---------------------------------
// Add to max stock.
// Preconditions: None
// Postconditions: Max stock never goes below 0;
//----------------------------------------------------------------------------
void Item::addMaxStock(const int amount) 
{
	maxStock += amount;
	if (maxStock < 0)
	{
		maxStock = 0;
	}
} // end of addMaxStock

//------------------------------ operator< -----------------------------------
// Returns true if this item has lower stock.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
bool Item::operator<(const Item& other) const 
{
	return stock < other.stock;
} // end of operator<

//------------------------------ operator> -----------------------------------
// Returns true if this item has greater stock.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
bool Item::operator>(const Item& other) const 
{
	return stock > other.stock;
} // end of operator>


//---------------------------------- print -----------------------------------
// Prints stock of item.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void Item::print(ostream& out) 
{
	out << "Printing from Item... " << stock << endl;
} // end of print