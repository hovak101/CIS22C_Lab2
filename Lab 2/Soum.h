#ifndef SOUM_H
#define SOUM_H

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

	std::string getName() const override { return name; }
};

#endif