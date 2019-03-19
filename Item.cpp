#include "Item.h"

Item::Item(const int amount) {
	stock = amount;
	maxStock = amount;
}

Item::~Item() {}

int Item::getStock() const {
	return stock;
}

int Item::getMaxStock() const {
	return maxStock;
}

void Item::addStock(const int amount) {
	stock = (stock + amount > maxStock) ? maxStock : stock + amount;
}

void Item::removeStock(const int amount) {
	stock = (stock - amount < 0) ? 0 : stock - amount;
}

void Item::addMaxStock(const int amount) {
	maxStock += amount;
	if (maxStock < 0)
		maxStock = 0;
}

bool Item::operator<(const Item& other) const {
	return stock < other.stock;
}

bool Item::operator>(const Item& other) const {
	return stock > other.stock;
}

void Item::print(ostream& out) {
	out << "Printing from Item... " << stock << endl;
}