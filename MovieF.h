//------------------------------- MovieF.h -----------------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorting and storage for comedy movie attributes.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#ifndef MOVIEF_H
#define MOVIEF_H
#include "Item.h"

class MovieF : public Item
{
public:
	// constructor
	MovieF(const int, const string, const string, const int);

	// destructor
	~MovieF();

	//------------------------------ operator< -----------------------------------
	// Returns true if this movie is less, comparing by title then year.
	// Preconditions: Other item is of type MovieF.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool operator<(const Item&) const;

	//------------------------------ operator> -----------------------------------
	// Returns true if this movie is greater, comparing by title then year.
	// Preconditions: Other item is of type MovieF.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool operator>(const Item&) const;

	//---------------------------------- print -----------------------------------
	// Prints attributes about this movie.
	// Preconditions: None
	// Postconditions: None
	//----------------------------------------------------------------------------
	void print(ostream& out);

private:
	int year;			// year movie was created
	string title;		// title of movie
	string director;	// director of movie
};

#endif