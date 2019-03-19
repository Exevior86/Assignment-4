#ifndef MOVIED_H
#define MOVIED_H
#include "Item.h"

using namespace std;

class MovieD : public Item
{
public:
	MovieD(const int, const string, const string, const int);
	~MovieD();

	bool operator<(const Item&) const;
	bool operator>(const Item&) const;
	void print(ostream& out);

private:
	int year;
	string title;
	string director;
};

#endif