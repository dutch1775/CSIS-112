#include "Patient.h"

Patient::Patient() //deafult constuctor
{
	lastName = ""; //set lastname to default empty value
}

Patient::Patient(std::string ln) //1 arg constuctor
{
	lastName = ln; //set lastname to passed in argument
}

void Patient::setLastName(std::string pn) //set lastname prviate member from argument
{
	lastName = pn; //set lastname to passed in argument
}

std::string Patient::getLastName() const //return patient's lastname
{
	return lastName; //return lastname
}

void Patient::addCholesterol() //adds a cholesterol reading to the cholesterol vector
{
	double cholesterolInput{ 0 }; //variable to store user's input for cholesterol

	std::cout << "Enter cholesterol readings for the patient one at a time, up to 5" << std::endl; //notifies them of up to 5 parameter
	for (int i = 0; i < 5; ++i) //loop for max of 5 entries
	{
		std::cout << "Enter cholesterol reading (Enter -1 to exit): "; //prompt for readings entry
		std::cin >> cholesterolInput; //get entry

		if (cholesterolInput == -1) //if exit input
		{
			break; //break loop
		}
		else //if not exit
		{
			cholesterolReadings.push_back(cholesterolInput); //add passed in reading to store in vector
		}
	}
}

std::string Patient::printCholesterolReadings() const //prints all cholesterol readings for a single patients
{
	for (int i = 0; i < cholesterolReadings.size(); ++i) //loop thorugh all cholesterol readings
	{
		std::cout << cholesterolReadings[i] << " mg/dL" << std::endl; //display all cholesterol readings
	}
	return ""; //return value of null string (only way I could get the function to work in doctor.cpp)
}