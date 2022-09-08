#include "Doctor.h"

Doctor::Doctor() //deafult constructor
{
	doctorName = ""; //sets doctor name to default null value
}

Doctor::Doctor(std::string name) //1 arg constuctor
{
	doctorName = name; //set doctor name to passed in argument
}

void Doctor::setDoctorName(std::string dn)  //set doctor name to passed in argument
{
	doctorName = dn; //set doctor name to passed in argument
}

std::string Doctor::getDoctorName() const //return doctor name
{
	return doctorName; //return doctor name
}

void Doctor::addPatient(std::string np) //adds patient object to patient vector
{
	Patient p; //instantiate patient object

	//set user input to patient lastname
	p.setLastName(np);

	//add the patient cholesterol readings
	p.addCholesterol();

	std::cout << std::endl; //space for formatting

	patients.push_back(p); //add all patient info to patients vector
}

void Doctor::printPatientRecords() const //prints all data of doctor patients
{
	for (int i = 0; i < patients.size(); i++) //loop througl all of patients vector
	{
		std::cout << patients[i].getLastName() << std::endl; //display patient name
		std::cout << patients[i].printCholesterolReadings() << std::endl; //show all patient readings
	}
}