//------------------------------- MovieC.cpp ---------------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorting and storage for classic movie attributes.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#include "MovieC.h"
#include <string>

// constructor
MovieC::MovieC(const int amount, const string titl, const string dir, const string majorA, const int mth, const int yr) : Item(amount) 
{
	title = titl;
	director = dir;
	month = mth;
	year = yr;
	majorActor = majorA;
}

// destructor
MovieC::~MovieC() {}

//------------------------------ operator< -----------------------------------
// Returns true if this movie is less, comparing by year, month then actor.
// Preconditions: Other item is of type MovieC.
// Postconditions: None
//----------------------------------------------------------------------------
bool MovieC::operator<(const Item& other) const 
{
	const MovieC& reference = dynamic_cast<const MovieC&> (other);
	return year < reference.year || year == reference.year && month < reference.month
		|| year == reference.year && month == reference.month && majorActor < reference.majorActor;
} // end of operator<

//------------------------------ operator> -----------------------------------
// Returns true if this movie is greater, comparing by year, month then actor.
// Preconditions: Other item is of type MovieC.
// Postconditions: None
//----------------------------------------------------------------------------
bool MovieC::operator>(const Item& other) const 
{
	const MovieC& reference = dynamic_cast<const MovieC&> (other);
	return year > reference.year || year == reference.year && month > reference.month
		|| year == reference.year && month == reference.month && majorActor > reference.majorActor;
} // end of operator>

//---------------------------------- print -----------------------------------
// Prints attributes about this movie.
// Preconditions: None
// Postconditions: None
//----------------------------------------------------------------------------
void MovieC::print(ostream& out) 
{
	out << "C: Stock(" << stock << ") " << month << " " << year << ", " << majorActor << ", " << title << ", " << director;
} // end of print