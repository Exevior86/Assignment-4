#include <iostream>
#include <fstream>
#include <string>
#include "Hashtable.h"
#include "Fileparser.h"

using namespace std;

int main() {
	Fileparser *fuck = new Fileparser;
	Hashtable *test = new Hashtable;
	Hashtable *yes;

	ifstream infile1("data4customers.txt");
	ifstream infile2("data4movies.txt");
	ifstream infile3("data4commands.txt");

	Customer one = Customer(5565, "Adam", "Donkey");
	Customer two = Customer(1000, "Vlady", "Slav");
	Customer three = Customer(6598, "Poo", "Snatcher");
	Customer four = Customer(6575, "Second", "Guy");

	test->put(one);
	test->put(two);
	test->put(three);
	test->put(four);

	cout << "Testing put(5565, Adam Donkey)" << endl;
	cout << "Get 5565 = " << test->get(5565) << endl;
	cout << (test->get(5565) == "Adam Donkey" ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing put(1000, VladySlav)" << endl;
	cout << "Get 1000 = " << test->get(1000) << endl;
	cout << (test->get(1000) == "VladySlav" ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing putting a second item in hash with collision" << endl;
	cout << "Putting 6576 = " << test->get(four.getID()) << endl;
	cout << (test->get(four.getID()) == "Second Guy" ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing getID" << endl;
	cout << "Four's ID = " << four.getID() << endl;
	cout << (four.getID() == 6575 ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing containsKey(5565)" << endl;
	cout << "Contains 5565? = " << test->containsKey(5565) << endl;
	cout << (test->containsKey(5565) == 1 ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing containsKey(1000)" << endl;
	cout << "Contains 1000? = " << test->containsKey(1000) << endl;
	cout << (test->containsKey(1000) == 1 ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing containsKey(500)" << endl;
	cout << "Contains 500? = " << test->containsKey(500) << endl;
	cout << (test->containsKey(500) == 0 ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing remove existing item 1000" << endl;
	test->remove(1000);
	cout << (test->get(1000) == "Error item doesn't exist" ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing get non existant data" << endl;
	cout << "Does hash key 5 exist? = " << test->get(5) << " ";
	cout << (test->get(5) == "Error item doesn't exist" ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing printHistory on empty list" << endl;
	cout << (one.printHistory() == "NO Transaction Data" ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing adding a transaction = " << endl;
	cout << "Adding B Fish Movie " << endl;
	one.addTransaction("B", "Fish Movie");
	cout << (one.containsTransaction(one) == 1 ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing adding a transaction = " << endl;
	cout << "Adding R Fish Movie " << endl;
	one.addTransaction("R", "Fish Movie");
	cout << (one.containsTransaction(one) == 1 ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing adding a transaction = " << endl;
	cout << "Adding B Poo Movie " << endl;
	one.addTransaction("B", "Poo Movie");
	cout << (one.containsTransaction(one) == 1 ? "pass" : "fail") << endl;
	cout << endl;

	cout << "Testing printHistory = " << endl;
	one.printHistory();
	cout << endl;

	cout << "Testing removing a transaction = " << endl;
	cout << "removing R Fish Movie " << endl << "History ";
	one.removeTransaction("R", "Fish Movie");
	cout << endl;
	one.printHistory();
	cout << endl;

	cout << "Testing removing a transaction = " << endl;
	cout << "removing B Fish Movie " << endl << "History ";
	one.removeTransaction("B", "Fish Movie");
	cout << endl;
	one.printHistory();
	cout << endl;

	cout << 5565 % 101 << endl;
	cout << 5465 % 101 << endl;
	cout << 6575 % 101 << endl;
	return 0;
}