#pragma once
#include <iostream>
#include <string>
#include "Currency.h"

class Krone : public Currency
{
private:
	std::string name;

public:
	Krone() { name = "Krone"; }
	Krone(double value) : Currency(value) { name = "Krone"; }

	void print() const override;
};

void Krone::print() const {
	std::cout << whole << ".";

	if (frac < 10) {
		std::cout << "0";
	}

	std::cout << frac << " " << name << std::endl;
}