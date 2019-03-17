#include <iostream>
#include <string>
#include "Hashtable.h"
#include "CustomerData.h"

using namespace std;

int main() {

	Hashtable *test = new Hashtable;
	Customer one = Customer("5589", "Adam Donkey");
	Customer two = Customer("1500", "VladySlav");
	Customer three = Customer("6598", "Poo Snatcher");

	test->put(1000, "truck");
	test->put(5565, "Fuck");

	cout << "test 1 = " << test->containsKey(5565) << endl;
	cout << "test 2 = " << test->containsKey(1000) << endl;
	test->remove(1000);
	cout << "test 2 = " << test->containsKey(1000) << endl;
	cout << "Test 3 = " << test->get(5565) << endl;

	cout << "Checking spot 1 = " << test->get(0) << endl;

	cout << "Adding transaction = " << endl;
	
	return 0;
}