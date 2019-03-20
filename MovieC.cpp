#include "MovieC.h"
#include <string>

MovieC::MovieC(const int amount, const string titl, const string dir, const string majorA, const int mth, const int yr) : Item(amount) {
	title = titl;
	director = dir;
	month = mth;
	year = yr;
	majorActor = majorA;
}

MovieC::~MovieC() {}

bool MovieC::operator<(const Item& other) const {
	const MovieC& reference = dynamic_cast<const MovieC&> (other);
	return year < reference.year || year == reference.year && month < reference.month
		|| year == reference.year && month == reference.month && majorActor < reference.majorActor;
}

bool MovieC::operator>(const Item& other) const {
	const MovieC& reference = dynamic_cast<const MovieC&> (other);
	return year > reference.year || year == reference.year && month > reference.month
		|| year == reference.year && month == reference.month && majorActor > reference.majorActor;
}
void MovieC::print(ostream& out) {
	out << "C: " << month << " " << year << ", " << majorActor << ", " << title << ", " << director;
}