/* Lab Number: 2
 * Names: Alex Hovakimyan, Jacqueline Fernandez Ortega
 * Purpose: This program allows the user to do addition and subtraction operations on two
 * types of currencies: Soum and Krone. The user specifies which type of operation to do
 * by using the following format: [<operation type> <value type> <value> <receiver>], where
 * operation type is either 'a'(addition) or 's'(subtraction), value type is either 's'(Soum)
 * or 'k'(Krone), value is any non-negative double, and receiver is either 'Soum' or 'Krone'.
 * The program is exited when the user enters the q key.
 */

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

	/* This function returns the field name.
	 * Pre:
	 * Post:
	 * Return: returns string of name field.
	 */
	std::string getName() const override { return name; }
};

#endif