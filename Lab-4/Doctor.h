#pragma once

#include "Patient.h"

class Doctor
{
private:

	std::string doctorName; //name of the doctor
	std::vector<Patient> patients; //vector holding all of the doctors patients

public:
	
	Doctor(); //default constuctor
	Doctor(std::string name); //1 arg constuctor 
	void setDoctorName(std::string dn); //set doctor name to passed in argument
	std::string getDoctorName() const; //return doctor name
	void addPatient(std::string pn); //adds patient object to patient vector
	void printPatientRecords() const; //prints all data of doctor patients

};
