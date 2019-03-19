#include "MovieD.h"
#include <string>

MovieD::MovieD(const int amount, const string titl, const string dir, const int yr) : Item(amount) {
	title = titl;
	director = dir;
	year = yr;
}

MovieD::~MovieD() {}

bool MovieD::operator<(const Item& other) const {
	const MovieD& reference = dynamic_cast<const MovieD&> (other);
	return director < reference.director || director == reference.director && title < reference.title;
}

bool MovieD::operator>(const Item& other) const {
	const MovieD& reference = dynamic_cast<const MovieD&> (other);
	return director > reference.director || director == reference.director && title > reference.title;
}
void MovieD::print(ostream& out) {
	out << "D: " << director << ", " << title << ", " << year;
}