#include "MovieF.h"
#include <string>

MovieF::MovieF(const int amount, const string titl, const string dir, const int yr) : Item(amount) {
	title = titl;
	director = dir;
	year = yr;
}

MovieF::~MovieF() {}

bool MovieF::operator<(const Item& other) const {
	const MovieF& reference = dynamic_cast<const MovieF&> (other);
	return title < reference.title || title == reference.title && year < reference.year;
}

bool MovieF::operator>(const Item& other) const {
	const MovieF& reference = dynamic_cast<const MovieF&> (other);
	return title > reference.title || title == reference.title && year > reference.year;
}
void MovieF::print(ostream& out) {
	out << "F: " << title << ", " << year << ", " << director;
}