#ifndef MOVIEF_H
#define MOVIEF_H
#include "Item.h"

using namespace std;

class MovieF : public Item
{
public:
	MovieF(const int, const string, const string, const int);
	~MovieF();

	bool operator<(const Item&) const;
	bool operator>(const Item&) const;
	void print(ostream& out);

private:
	int year;
	string title;
	string director;
};

#endif