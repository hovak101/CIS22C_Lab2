#pragma once
#include <iostream>
#include <string>
#include "Currency.h"

class Soum : public Currency
{
private:
	std::string name;

public:
	Soum() { name = "Soum"; }
	Soum(double value) : Currency(value) { name = "Soum"; }

	void print() const override;
};

void Soum::print() const {
	std::cout << whole << ".";

	if (frac < 10) {
		std::cout << "0";
	}

	std::cout << frac << " " << name << std::endl;
}