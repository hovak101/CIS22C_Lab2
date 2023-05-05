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
	//Currency(const Currency& origObject);
	virtual ~Currency() {};

	// Setters and Getters:
	int getWhole() const { return whole; }
	int getFrac() const { return frac; }
	void setWhole(int whole);
	void setFrac(int frac);
	virtual std::string getName() const = 0;

	// Arithmetic and Comparison Functions:
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

void Currency::add(Currency* other) {
	if (this->getName() != other->getName()) {
		throw "Invalid addition.";
	}

	this->whole += other->whole;
	this->frac += other->frac;

	int temp;
	temp = frac / 100;
	whole += temp;
	frac = frac - temp * 100;
}

void Currency::subtract(Currency* other) {
	if (this->getName() != other->getName()) {
		throw "Invalid subtraction.";
	}

	//First convert both numbers to doubles. 
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

bool Currency::isEqual(Currency* other) const {
	if (this->getName() != other->getName()) {
		throw "Currencies are not of the same type.";
	}

	return (whole == other->whole) && (frac == other->frac);
}

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

void Currency::print() const {
	std::cout << whole << ".";

	if (frac < 10) {
		std::cout << "0";
	}

	std::cout << frac << " " << getName();
}

#endif