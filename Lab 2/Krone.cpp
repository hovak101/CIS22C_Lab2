#pragma once
#include <iostream>
#include <string>
#include "Currency.cpp"

class Krone : public Currency
{
private:
	std::string name;

public:
	Krone() {
		name = "Krone";
	}

	Krone (double value) : Currency(value) {
		name = "Krone";
	}

	void print() const override {
		std::cout << name << std::endl; 
	}
};
