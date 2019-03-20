//------------------------------- MovieD.h -----------------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorting and storage for drama movie attributes.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#ifndef MOVIED_H
#define MOVIED_H
#include "Item.h"

class MovieD : public Item
{
public:
	// constructor
	MovieD(const int, const string, const string, const int);

	// destructor
	~MovieD();

	//------------------------------ operator< -----------------------------------
	// Returns true if this movie is less, comparing by director then title.
	// Preconditions: Other item is of type MovieD.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool operator<(const Item&) const;

	//------------------------------ operator> -----------------------------------
	// Returns true if this movie is greater, comparing by director then title.
	// Preconditions: Other item is of type MovieD.
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