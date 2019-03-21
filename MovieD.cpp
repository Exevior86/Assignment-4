//------------------------------- MovieD.cpp ---------------------------------
// Vlad Netrebchenko, Adam Snyder CSS 343 C
// 3/8/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorting and storage for drama movie attributes.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#include "MovieD.h"
#include <string>

// constructor
MovieD::MovieD(const int amount, const string titl, const string dir, const int yr) : Item(amount) 
{
	title = titl;
	director = dir;
	year = yr;
}

// destructor
MovieD::~MovieD() {}

//------------------------------ operator< -----------------------------------
// Returns true if this movie is less, comparing by director then title.
// Preconditions: Other item is of type MovieD.
// Postconditions: None
//----------------------------------------------------------------------------
bool MovieD::operator<(const Item& other) const 
{
	const MovieD& reference = dynamic_cast<const MovieD&> (other);
	return director < reference.director || director == reference.director && title < reference.title;
} // end of operator<


//------------------------------ operator> -----------------------------------
// Returns true if this movie is greater, comparing by director then title.
// Preconditions: Other item is of type MovieD.
// Postconditions: None
//----------------------------------------------------------------------------
bool MovieD::operator>(const Item& other) const 
{
	const MovieD& reference = dynamic_cast<const MovieD&> (other);
	return director > reference.director || director == reference.director && title > reference.title;
} // end of operator>

//---------------------------------- print -----------------------------------
// Prints attributes about this movie.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void MovieD::print(ostream& out) 
{
	out << "D: Stock(" << stock << ") " << director << ", " << title << ", " << year;
} // end of print