#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class negativeException : public std ::exception {
public:
	const char* what() const throw(){
		return "Exception: value must be postitive.";
	}
};

class typeException : public std ::exception {
public:
	const char* what() const throw(){
		return "Exception: type does not match.";
	}
};

class currencyException : public std::exception{
public:
	const char* what() const throw() {
		return "Exception: currencies don't match.";
	}
};

class Currency{	
protected:
	int whole;
	int frac;

public:
	// Constructers, Copy Constructer, and Destructor:
	Currency() {
		whole = 0;
		frac = 0;
	}

	Currency(double value) {
		// throw exception if value < 0
		if (value < 0){
			throw std::invalid_argument("Currency can't be negative.");
		}
		whole = static_cast<int>(value);
		frac = (value - whole) * 100 + 0.5;  //ask goel
	}

	Currency(const Currency& origObject) {
		// throw exception if origObject class does not match that of the caller's class.
		if(typeid(origObject) != typeid(*this)){
			throw typeException();
		}
		this->whole = origObject.whole; 
		this->frac = origObject.frac;
	}
	virtual ~Currency() {};

	// Setters and Getters:
	int getWhole() const { return whole; }
	int getFrac() const { return frac; }
	void setWhole(int whole) {
		if (whole < 0){
			throw negativeException();
		}
	this->whole = whole; 
	} //throw exception if negative
	void setFrac(int frac) { 
		if(frac < 0) {
			throw negativeException();
		}
		this->frac = frac; 
	}     //throw exception if negative

	// Arithmetic and Comparison Functions:
	void add(Currency* other) {                  
		//throw exception if other is not the same type as caller. 
		if(typeid(*other) != typeid(*this)){
			throw typeException();
		}
		this->whole += other->whole;
		this->frac += other->frac;

		int temp;
		temp = frac / 100;
		whole += temp; 
		frac = frac - temp * 100;    
	}

	void subtract(Currency* other) {                      
		//throw exception if other is not the same type as caller. 
		if(typeid(*other) != typeid(*this)){
			throw typeException();
		}
		if(this->getWhole() != other->getWhole() || this->getFrac() != other->getFrac()) {
           		throw currencyException();
	    	}
		//First convert both numbers to doubles. 
		double thisVal = whole; 
		thisVal += frac / 100.0;

		double otherVal = other->whole;
		otherVal += other->frac / 100.0;

		double finalVal = thisVal + otherVal;

		if (finalVal < 0) {
			throw negativeException(); //throw exception		
		}
		else {
			//convert finalVal to whole and frac
			whole = static_cast<int>(finalVal);
			frac = (finalVal - whole) * 100 + 0.5;
		}
	}

	bool isEqual(Currency* other) const { 
		// throw exception if other is not of the same type as caller.
		if(typeid(*other) != typeid(*this)){
			throw typeException();
		}
		return (whole == other->whole) && (frac == other->frac);
	}

	bool isGreater(Currency* other) const {    
		// throw exception if other is not the same currency. 
		if(this->getWhole() != other->getWhole() || this->getFrac() != other->getFrac()) {
           		throw currencyException();
	    	}
		if (whole > other->whole) {
			return true; 
		}

		if (frac > other->frac) {
			return true; 
		}

		return false; 
	}

	virtual void print() const = 0;
};
