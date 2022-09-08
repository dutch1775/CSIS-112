
//included files
#include "Animal.h"
#include "Dog.h"
#include "Fish.h"
#include "Rabbit.h"
#include "Snake.h"

using namespace std;

//function prototypes
void userSelection(int& selection);  //menu selection function

int main()
{
	Animal* Animals[5]; //array of animal pointers
	string inputName;   //string to hold user input for name
	int selection{ 0 }, generatedAge{ 0 };  //placeholder var for user choice and generated age
	srand(100); //seed the rand function

	for (int i = 0; i < 5; ++i) //loop for 5 animal options
	{
		userSelection(selection); //call menu functon

		//prompt anf get user input for animal name
		cout << "Enter the animals name: "; 
		cin >> inputName;
		//gen rand num between 1 and 20
		generatedAge = 1 + rand() % 20; 

		switch (selection) //switch on user selection
		{
		case 1: //if dog make a dynamic dog object
			Animals[i] = new Dog(inputName, generatedAge); 
			break;
		case 2:  //if rabbit make dynamic rabbit object
			Animals[i] = new Rabbit(inputName, generatedAge);
			break;
		case 3:  //if fish make dynamic fish object
			Animals[i] = new Fish(inputName, generatedAge);
			break;
		case 4:  //if snake make dynamic snake object
			Animals[i] = new Snake(inputName, generatedAge);
			break;
		}
		//store animal in array and cout formatting
		cout << endl;
	}

	for (int i = 0; i < 5; ++i) //loop through array
	{
		//print animal information and how they move
		cout << endl;
		cout << "My name is " << Animals[i]->getName() <<", and I am "
			 << Animals[i]->getAge() << " years old." << endl;
		Animals[i]->move();
	}

	cout << endl;

	//loop through the array and delete the dynamic objects and set pointer to null
	for (int i = 0; i < 5; ++i) 
	{
		delete Animals[i];
		Animals[i] = nullptr;
	}

	system("PAUSE");
	return 0;
}

void userSelection(int& selection)  //menu selection function
{
	//prompt user for menu input
	cout << "Main menu\n" << endl;
	cout << "1 - Dog\n" << endl;
	cout << "2 - Rabbit\n" << endl;
	cout << "3 - Fish\n" << endl;
	cout << "4 - Snake\n" << endl;
	cout << "Enter selection: ";
	cin >> selection;

	if (selection != 1 && selection != 2 && selection != 3 && selection != 4 || !cin) //if not one of options or breaks cin
	{
		while (selection != 1 && selection != 2 && selection != 3 && selection != 4 || !cin)//while its not valid
		{
			//prompt for re-entry, clear and ignore buffer, and take new input
			cout << "You must pick from one of the menu options" << endl;
			cout << "Dog (1), Rabbit(2), Fish(3), or Snake(4): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> selection;
		}
	}
	cout << endl; //space for formatting
}
