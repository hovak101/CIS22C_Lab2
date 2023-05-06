/* Lab Number: 2
 * Names: Alex Hovakimyan, Jacqueline Fernandez Ortega
 * Purpose: This program allows the user to do addition and subtraction operations on two
 * types of currencies: Soum and Krone. The user specifies which type of operation to do
 * by using the following format: [<operation type> <value type> <value> <receiver>], where
 * operation type is either 'a'(addition) or 's'(subtraction), value type is either 's'(Soum)
 * or 'k'(Krone), value is any non-negative double, and receiver is either 'Soum' or 'Krone'.
 * The program is exited when the user enters the q key.
 */

#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>
#include <cmath>

class Currency
{
protected:
	int whole;
	int frac;

public:
	// Constructers, Copy Constructer, and Destructor:
	Currency();
	Currency(double value);
	Currency(const Currency& origObject);
	virtual ~Currency() {};

	// Setters and Getters:
	/* Returns the whole, frac or name field.
	 * Pre: 
	 * Post:
	 * Return: returns whole, frac or name. 
	 */
	int getWhole() const { return whole; }
	int getFrac() const { return frac; }
	virtual std::string getName() const = 0;

	void setWhole(int whole);
	void setFrac(int frac);

	// Arithmetic, Comparison, and Other Functions:
	void add(Currency* other);
	void subtract(Currency* other);
	bool isEqual(Currency* other) const;
	bool isGreater(Currency* other) const;
	void print() const;
};

Currency::Currency() {
	whole = 0;
	frac = 0;
}

Currency::Currency(double value) {
	if (value < 0) {
		throw "Currency can't be negative.";
	}

	whole = static_cast<int>(value);
	frac = round((value - whole) * 100);
}

Currency::Currency(const Currency& origObject) {
	this->whole = origObject.whole;
	this->frac = origObject.frac;
}

/* Sets whole or frac field to user-given value. 
 * Pre: whole >= 0, frac >= 0
 * Post: reassigns whole or frac field of object. 
 * Return:
 */
void Currency::setWhole(int whole) {
	if (whole < 0) {
		throw "Currency can't be negative.";
	}

	this->whole = whole;
}

void Currency::setFrac(int frac) {
	if (frac < 0) {
		throw "Currency can't be negative.";
	}

	this->frac = frac;
}

/* This function adds another object of the same currency to this one. 
 * Pre: other must be of same class as caller.
 * Post: currency objects are added.
 * Return: 
 */
void Currency::add(Currency* other) {
	if (this->getName() != other->getName()) {
		throw "Invalid addition.";
	}

	this->whole += other->whole;
	this->frac += other->frac;

	if (this->frac >= 100) {
		int temp;
		temp = frac / 100;
		whole += temp;
		frac = frac - temp * 100;
	}
}

/* This function subtracts another object of the same currency from this one. 
 * Pre: other must be of same class as caller, other cannot have a greater value than
 * the caller object.
 * Post: currency objects are subtracted.
 * Return: 
 */
void Currency::subtract(Currency* other) {
	if (this->getName() != other->getName()) {
		throw "Invalid subtraction.";
	}
 
	double thisVal = whole;
	thisVal += frac / 100.0;

	double otherVal = other->whole;
	otherVal += other->frac / 100.0;

	double finalVal = thisVal - otherVal;

	if (finalVal < 0) {
		throw "Invalid subtraction.";
	}
	
	//convert finalVal to whole and frac
	whole = static_cast<int>(finalVal);
	frac = round((finalVal - whole) * 100);
}

/* This function compares another object of the same type to this one for equality.
 * Pre: other must be of same class as caller. 
 * Post: 
 * Return: returns true if both the whole fields and frac fields are equal to each other. 
 */
bool Currency::isEqual(Currency* other) const {
	if (this->getName() != other->getName()) {
		throw "Currencies are not of the same type.";
	}

	return (whole == other->whole) && (frac == other->frac);
}

/* This function checks if the value of this object is greater than the value of 
 * another object of the same type. 
 * Pre: other must be of same class as caller. 
 * Post:
 * Return: returns true if this object is greater than the value of other, otherwise 
 * returns false. 
 */
bool Currency::isGreater(Currency* other) const {
	if (this->getName() != other->getName()) {
		throw "Currencies are not of the same type";
	}

	if (whole > other->whole) {
		return true;
	}

	if (frac > other->frac) {
		return true;
	}

	return false;
}

/* Print the currency in the format "xx.yy" where the xs are the whole part and the
 * ys are the fractional part. 
 * Pre: 
 * Post: print out the currency of this object. 
 * Return: 
 */
void Currency::print() const {
	std::cout << whole << ".";

	if (frac < 10) {
		std::cout << "0";
	}

	std::cout << frac << " " << getName();
}

#endif