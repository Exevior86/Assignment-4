//------------------------------- MovieF.cpp ---------------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorting and storage for comedy movie attributes.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#include "MovieF.h"
#include <string>

// constructor
MovieF::MovieF(const int amount, const string titl, const string dir, const int yr) : Item(amount) 
{
	title = titl;
	director = dir;
	year = yr;
}

// destructor
MovieF::~MovieF() {}

//------------------------------ operator< -----------------------------------
// Returns true if this movie is less, comparing by title then year.
// Preconditions: Other item is of type MovieF.
// Postconditions: None
//----------------------------------------------------------------------------
bool MovieF::operator<(const Item& other) const 
{
	const MovieF& reference = dynamic_cast<const MovieF&> (other);
	return title < reference.title || title == reference.title && year < reference.year;
} // end of operator<

//------------------------------ operator> -----------------------------------
// Returns true if this movie is greater, comparing by title then year.
// Preconditions: Other item is of type MovieF.
// Postconditions: None
//----------------------------------------------------------------------------
bool MovieF::operator>(const Item& other) const 
{
	const MovieF& reference = dynamic_cast<const MovieF&> (other);
	return title > reference.title || title == reference.title && year > reference.year;
} // end of operator>

//---------------------------------- print -----------------------------------
// Prints attributes about this movie.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void MovieF::print(ostream& out)
{
	out << "F: Stock(" << stock << ") " << title << ", " << year << ", " << director;
} // end of print