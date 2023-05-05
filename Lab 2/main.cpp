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

	string line;
	char operationType;
	char valueType;
	double value;
	string receiver;
	int receiverIndex;
	stringstream stream;
	Currency* newCurr = nullptr;

	cout << "Output: ";
	currencies[0]->print();
	cout << " ";
	currencies[1]->print();
	cout << endl;

	cout << "Input: ";
	getline(cin, line);
	stream.str(line);
	stream >> operationType >> valueType >> value >> receiver;

	while (line != "q") {  
		try {
			if (valueType == 's') {
				newCurr = new Soum(value);
			}
			else if (valueType == 'k') {
				newCurr = new Krone(value);
			}
			else {
				throw "New currency must be of type 's'(Soum) or 'k'(Krone).";
			}

			if (receiver == "Soum") {
				receiverIndex = 0;
			}
			else if (receiver == "Krone") {
				receiverIndex = 1;
			}
			else {
				throw "Receiving object must be of type 'Soum' or 'Krone'.";
			}

			if (operationType == 'a') {
				currencies[receiverIndex]->add(newCurr);
			}
			else if (operationType == 's') {
				currencies[receiverIndex]->subtract(newCurr);
			}
			else if (operationType == 'g') {
				currencies[receiverIndex]->isGreater(newCurr);
			}
			else if (operationType == 'e') {
				currencies[receiverIndex]->isEqual(newCurr);
			}
			else {
				throw "Modification must be of type 'a'(addition), 's'(subtraction), 'g'(is greater), or 'e'(is equal).";
			}
		}
		catch (const char *msg) {
			cout << "Error: " << msg << endl;
		}

		cout << "Output: ";
		currencies[0]->print();
		cout << " ";
		currencies[1]->print();
		cout << endl;

		delete newCurr;
		stream.clear();

		cout << "Input: ";
		getline(cin, line);
		stream.str(line);
		stream >> operationType >> valueType >> value >> receiver;
	}

	return 0;
}