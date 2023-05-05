#pragma once
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
	int getWhole() const { return whole; }
	int getFrac() const { return frac; }
	void setWhole(int whole) { this->whole = whole; } //throw exception if negative
	void setFrac(int frac) { this->frac = frac; }     //throw exception if negative

	// Arithmetic and Comparison Functions:
	void add(Currency* other);
	void subtract(Currency* other);
	bool isEqual(Currency* other) const;
	bool isGreater(Currency* other) const;
	virtual void print() const = 0;
};

Currency::Currency() {
	whole = 0;
	frac = 0;
}

Currency::Currency(double value) {
	// throw exception if value < 0
	whole = static_cast<int>(value);
	frac = round((value - whole) * 100);
}

Currency::Currency(const Currency& origObject) {
	// throw exception if origObject class does not match that of the caller's class. 
	this->whole = origObject.whole;
	this->frac = origObject.frac;
}

void Currency::add(Currency* other) {
	//throw exception if other is not the same type as caller. 
	this->whole += other->whole;
	this->frac += other->frac;

	int temp;
	temp = frac / 100;
	whole += temp;
	frac = frac - temp * 100;
}

void Currency::subtract(Currency* other) {
	// throw exception if other is not the same type as caller. 

	//First convert both numbers to doubles. 
	double thisVal = whole;
	thisVal += frac / 100.0;

	double otherVal = other->whole;
	otherVal += other->frac / 100.0;

	double finalVal = thisVal - otherVal;

	if (finalVal < 0) {
		//throw exception
	}
	else {
		//convert finalVal to whole and frac
		whole = static_cast<int>(finalVal);
		frac = round((finalVal - whole) * 100);
	}
}

bool Currency::isEqual(Currency* other) const {
	// throw exception if other is not of the same type as caller. 
	return (whole == other->whole) && (frac == other->frac);
}

bool Currency::isGreater(Currency* other) const {
	// throw exception if other is not the same currency. 
	if (whole > other->whole) {
		return true;
	}

	if (frac > other->frac) {
		return true;
	}

	return false;
}

