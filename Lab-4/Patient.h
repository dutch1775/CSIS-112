#pragma once

#include <string>
#include <vector>
#include <iostream>


class Patient
{
private:

	std::string lastName; //patient last name
	std::vector<double> cholesterolReadings; //vector of double cholesterol readings (to account for decimals)

public:

	Patient(); //default constructor
	Patient(std::string lastName); //1 arg constructor
	void setLastName(std::string); //set lastname prviate member from argument
	std::string getLastName() const; //return patient's lastname
	void addCholesterol(); //adds a cholesterol reading to the cholesterol vector
	std::string printCholesterolReadings() const; //prints all cholesterol readings for a single patients

};