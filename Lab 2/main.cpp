#include <iostream>
#include <string>
#include <sstream>
#include "Currency.h"
#include "Krone.h"
#include "Soum.h"

using namespace std;

int main() {
	Currency* currencies[2];
	currencies[0] = new Soum();     
	currencies[1] = new Krone();

	/*
	// what exceptions is he talking about? See below:
	// "Throw String (or equivalent) exceptions from within the classes to ensure that invalid objects cannot be created." 

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