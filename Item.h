#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

class Item
{
public:
	Item(const int);
	~Item();

	int getStock() const;
	int getMaxStock() const;
	void addStock(const int);
	void removeStock(const int);
	void addMaxStock(const int);
	virtual bool operator<(const Item&) const;
	virtual bool operator>(const Item&) const;
	virtual void print(ostream& out);

private:
	int stock;
	int maxStock;
};

#endif