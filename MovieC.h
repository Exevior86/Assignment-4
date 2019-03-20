#ifndef MOVIEC_H
#define MOVIEC_H
#include "Item.h"

using namespace std;

class MovieC : public Item
{
public:
	MovieC(const int, const string, const string, const string, const int, const int);
	~MovieC();

	bool operator<(const Item&) const;
	bool operator>(const Item&) const;
	void print(ostream& out);

private:
	int month;
	int year;
	string title;
	string director;
	string majorActor;
};

#endif