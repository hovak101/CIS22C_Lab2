#pragma once
#include <iostream>
#include <string>
#include "Currency.cpp"

class Soum : public Currency
{
private:
	std::string name;

public:
	Soum() {
		name = "Soum";
	}

	Soum (double value) : Currency(value) {
		name = "Soum";
	}

	void print() const override {
		std::cout << whole << "." << frac << " " << name << std::endl;
	}
};