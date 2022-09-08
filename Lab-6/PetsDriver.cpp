#include "Pets.h"
#include <time.h>
#include <iomanip>

using namespace std;

void petsNumErrorCheck(int& numPets); //error checks number of pets input
void randNumGen(int& randWeight); //generates random weight for pet

int main()
{
	string inputName, inputType; //input var for name and type of pets
	int randWeight{ 0 }, numPets{ 0 }; //var for number of pet input and random weight of pets
	Pet** petArray; //ptr to dynamic array

	//prompt user for pet ammount, error check the input, and if valid store for dynamic array
	cout << "How many pets do you have?" << endl;
	cin >> numPets;
	petsNumErrorCheck(numPets);
	petArray = new Pet*[numPets];
	srand(time(0));

	//loop for array elements
	for (int i = 0; i < numPets; ++i)
	{
		//prompt user for pet name
		cout << "What is the name of your pet?" << endl;
		cin >> inputName;

		//prompt user for pet type
		cout << "What type of pet is " << inputName << '?' <<  endl;
		cin >> inputType;

		//generate random weight for pet
		randNumGen(randWeight);
		
		//create dynamic pet object
		Pet* pet = new Pet;
		cout << endl;

		//store input and generated variables into dynamic object
		pet->setName(inputName);
		pet->setType(inputType);
		pet->setWeight(randWeight);

		//store dynamic pet in dynamic array
		petArray[i] = pet;
	}

	//display pets in arrat
	cout << "These are the pets you have:" << endl;
	for (int i = 0; i < numPets; ++i)
	{
		cout << "Pet name:" << setw(18) << right  << petArray[i]->getName() << endl; //display pet name
		cout << "Pet type:" << setw(18) << right <<  petArray[i]->getType() << endl; //display pet type
		cout <<"Pet Weight:" << setw(16) << right <<  petArray[i]->getWeight() << endl; //display rand weight
		cout << endl; //formatting endline
	}	
	

	//loop through array
	for (int i = 0; i < numPets; ++i)
	{
		delete petArray[i]; //destroy each dynamic object in array
	}
	delete[] petArray; //destroy dynamic array 
	petArray = NULL; //set dynamic pointer to null

	system("pause");
	return 0;
}

void petsNumErrorCheck(int& numPets)
{
	if (numPets < 0 || !cin) //if positive num or breaks cin
	{
		while (numPets <= 0 || !cin)//while its not valid
		{
			//prompt for re-entry, clear and ignore buffer, and take new input
			cout << "ERROR: Please enter a valid pet ammount" << endl;
			cout << "How many pets do you have?" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numPets;
		}
	}
	cout << endl; //space for formatting
}

void randNumGen(int& randWeight) //generates random weight
{
	//seed generator for time
	randWeight = 1 + rand() % 100; //gen rand num between 1 and 100
}