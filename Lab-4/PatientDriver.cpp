//This program uses composition to create a doctor, who has patients, and the patients have names and up to 5 cholesterol readings
//The doctor can have up to 3 patients and a menu sysyetsm guides the user through process
//CSIS - 112
//Michael Dutchin

#include "Doctor.h"
#include "Patient.h"

using namespace std;

void userSelection(char& selection); //menu selection function

int main()
{

	int patientcounter{ 0 }; //counter to track patients for doctor
	char selection; //variable for menu selection
	string doctorName, patientName; // variable for doctor name and patient name

	//prompt user for doctor's name
	cout << "Enter the name of the Doctor: ";
	getline(cin, doctorName); //getline for anyspaces or errors
	Doctor d(doctorName); //create doctor object with user input name and constuctor

	userSelection(selection); //call menu selection subroutine

	while (selection != 'Q') //while not exit condition
	{
		switch (selection) //switch for selection char
		{
		case 'A': //if add
			if (patientcounter != 99) //while not more than 3 patients
			{
				++patientcounter; //add to track patients

				//prompt user for patient lastname
				std::cout << "Enter the lastname of the patient: ";
				std::cin >> patientName;
				std::cout << std::endl;

				d.addPatient(patientName); //call add patient function
			}
			else //if more than 3 tell user doctor is full
			{
				cout << d.getDoctorName() << " has the maximum number of patients." << endl;
			}
			break; //break switch

		case 'L': //if list
			cout << endl << "Printing patients ..." << endl << endl; //prompt for patient info
			d.printPatientRecords(); //print patient information
			break; //break switch

		case 'Q': //if exit then leave menu
			break; 
		}

		userSelection(selection); //reprompt for user selection
	}

	system("pause");
	return 0;
}

void userSelection(char& selection)  //menu selection function
{

	cout << "Would you like to Add (A), List (L), or Quit (Q): "; //prompt user for menu input
	cin >> selection;

	if (selection != 'A' && selection != 'L' && selection != 'Q' || !cin) //if not one of options or breaks cin
	{
		while (selection != 'A' && selection != 'L' && selection != 'Q' || !cin)//while its not valid
		{
			//prompt for re-entry, clear and ignore buffer, and take new input
			cout << "You must pick from one of the menu options" << endl;
			cout << "Add (A), List (L), or Quit (Q): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> selection;
		}
	}
	cout << endl; //space for formatting
}
