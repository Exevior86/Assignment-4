//------------------------------- MovieC.h -----------------------------------
// Vlad Netrebchenko CSS 343 C
// 3/18/2019
// 3/19/2019
//----------------------------------------------------------------------------
// Provides sorting and storage for classic movie attributes.
//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------

#ifndef MOVIEC_H
#define MOVIEC_H
#include "Item.h"

class MovieC : public Item
{
public:
	// constructor
	MovieC(const int, const string, const string, const string, const int, const int);

	// destructor
	~MovieC();

	//------------------------------ operator< -----------------------------------
	// Returns true if this movie is less, comparing by year, month then actor.
	// Preconditions: Other item is of type MovieC.
	// Postconditions: None
	//----------------------------------------------------------------------------
	bool operator<(const Item&) const;

	//------------------------------ operator> -----------------------------------
	// Returns true if this movie is greater, comparing by year, month then actor.
	// Preconditions: Other item is of type MovieC.
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
	int month;			// month the movie was created
	int year;			// year the movie was created
	string title;		// title of movie
	string director;	// director of movie
	string majorActor;	// major actor of movie
};

#endif