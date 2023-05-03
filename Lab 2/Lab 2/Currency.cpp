#pragma once
#include <iostream>
#include <string>

class Currency
{
protected:
	int whole;
	int frac;

public:
	//Constructers and Destructor
	Currency() {
		whole = 1;
		frac = 1;
	}
	Currency(double something);
	Currency(const Currency& origObject);
	~Currency();

	// Setters and Getters:
	int getWhole() const { return whole; }
	int getFrac() const { return frac; }
	void setWhole(int whole) { this->whole = whole; }
	void setFrac(int frac) { this->frac = frac; }

	// Other stuff
	void add(Currency other);
	void subtract(Currency other);
	bool isEqual(Currency other) const;
	bool isGreater(Currency other) const;
	void print() const;
	//Note: WHICH OF THE ABOVE FUNCTIONS IS SUPPOSED TO BE VIRTUAL????
};
