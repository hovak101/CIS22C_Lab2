#ifndef KRONE_H
#define KRONE_H

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

	std::string getName() const override { return name; }
};

#endif