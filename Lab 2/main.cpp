#include <iostream>
#include <string>
#include <sstream>
#include "Currency.cpp"
#include "Krone.cpp"
#include "Soum.cpp"

using namespace std;

int main() {
	
	Currency* currencies[2];
	currencies[0] = new Soum(2.35);      //should they be dynamically allocated?
	currencies[1] = new Krone();

	currencies[0]->print(); 
	/*

	// what exceptions is he talking about? See below:
	// "Throw String (or equivalent) exceptions from within the classes to ensure that invalid objects cannot be created."
	// Can we assume input won't be invalid? NO! Have to handle it. 
	// I think Krone and Soum are not supposed to be negative. \
	// Should input errors result in just error messages or exceptions that halt the program? 


	string line;
	char modificationType;
	char valueType;
	double value;
	string receiver;

	cout << "Input: ";
	getline(cin, line);
	stringstream stream;

	while (line != "q") {                   //Should I change so that it only looks for the character?
		stream.str(line);
		stream >> modificationType >> valueType >> value >> receiver;
		cout << "Output: " << endl; 
		cout << "modification type: " << modificationType << endl;
		cout << "value type: " << valueType << endl;
		cout << "value: " << value << endl;
		cout << "receiver: " << receiver << endl << endl;

		stream.clear();

		cout << "Input: ";
		getline(cin, line);
	}
	*/

	

	return 0;
}