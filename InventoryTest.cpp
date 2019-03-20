
#include "MovieF.h"
#include "MovieD.h"
#include "MovieC.h"
#include "ItemInventory.h"
#include "StoreController.h"
#include "Hashtable.h"
#include "Fileparser.h"

int main() {	
	/*
	ItemInventory inventory;

	MovieC* movieC1 = new MovieC(10, "ccccc", "direcG", "Ryan", 1998);
	MovieC* movieC2 = new MovieC(10, "ccccc", "direcG", "Goose", 1998);
	MovieC* movieC3 = new MovieC(10, "ccccc", "direcG", "Alan", 1994);
	MovieC* movieC4 = new MovieC(10, "ccccc", "direcG", "Alan", 1998);

	MovieD* movie1 = new MovieD(10, "ccccc", "direcG", 1998);
	MovieD* movie2 = new MovieD(11, "hhhhh", "direcA", 1997);
	MovieD* movie3 = new MovieD(1, "hhhhh", "direcK", 1998);
	MovieD* movie4 = new MovieD(1, "aaaaa", "direcK", 1932);

	inventory.add(movieC1);
	inventory.add(movieC2);
	inventory.add(movieC3);
	inventory.add(movieC4);
	
	cout << "Stock before borrowing: " << movieC3->getStock() << endl;
	cout << "Borrowing available: " << inventory.borrowItem(movieC3) << endl;
	cout << "Stock after borrowing: " << movieC3->getStock() << endl;
	cout << "Borrowing unavailable: " << inventory.borrowItem(movieC3) << endl;
	cout << "Returning available: " << inventory.returnItem(movieC3) << endl;
	cout << "Stock after returning: " << movieC3->getStock() << endl;
	cout << "Returning unavailable: " << inventory.returnItem(movieC3) << endl;
	cout << "Stock after returning: " << movieC3->getStock() << endl;

	cout << "Finding movie 2: " << inventory.find(movieC2) << endl;

	cout << endl;
	inventory.printAll(cout);
	*/

	/*
	MovieD* movieD1 = new MovieD(10, "ccccc", "direcG", 1998);
	MovieD* movieD2 = new MovieD(11, "hhhhh", "direcA", 1997);
	MovieD* movieD3 = new MovieD(1, "hhhhh", "direcK", 1998);
	MovieD* movieD4 = new MovieD(1, "aaaaa", "direcK", 1932);

	MovieF* movieF1 = new MovieF(10, "dd", "direcG", 1998);
	MovieF* movieF2 = new MovieF(11, "ss", "direcA", 1997);
	MovieF* movieF3 = new MovieF(1, "aa", "direcK", 1998);
	MovieF* movieF4 = new MovieF(1, "asdg", "direcK", 1932);

	MovieC* movieC1 = new MovieC(10, "ccccc", "direcG", "Ryan", 1998);
	MovieC* movieC2 = new MovieC(10, "ccccc", "direcG", "Goose", 1998);
	MovieC* movieC3 = new MovieC(10, "ccccc", "direcG", "Alan", 1994);
	MovieC* movieC4 = new MovieC(10, "ccccc", "direcG", "Alan", 1998);
	*/

	Customer* cust1 = new Customer(1088, "Adam", "Snyder");
	Customer* cust2 = new Customer(1029, "Vlad", "Netrebchenko");

	StoreController* store = new StoreController();

	ifstream infile1("data4customers.txt");
	ifstream infile2("data4movies.txt");

	Fileparser parser;
	parser.parseCustomers(infile1, store);
	parser.parseMovies(infile2, store);
	
	return 1;
}