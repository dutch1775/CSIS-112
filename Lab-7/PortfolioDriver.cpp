//included header files
#include "Portfolio.h"
#include "Date.h"

using namespace std;

//function prototypes
void userSelection(char& selection);  //menu selection function

int main()
{
	Portfolio p; //instantiate portfolio object
	string inputName; //input variable for portfolio name
	char selection; //variable to hold menu selection

	//prompt user for porfolio name and initialize name with input
	cout << "Enter a name for your portfolio: ";
	getline(cin, inputName);
	p.setName(inputName);
	cout << endl;

	//call menu selection function
	userSelection(selection);

	while (selection != 'Q') //while not exit condition
	{
		switch (selection) //switch for selection char
		{
		case 'S': //if purchase stock
			p.addStock(); //call add stock to purchase stock 
			break; //break switch
		case 'B': //if purchase bond
			p.addBond(); //call add bond to purchase bond
			break; //break switch
		case 'L': //if list print all portfolio contents
			p.printPortfolio();
			break; //break switch
		}

		userSelection(selection); //reprompt for user selection if Q then leave
	}

	system("PAUSE");
	return 0;
}

//function definitions

void userSelection(char& selection)  //menu selection function
{
	//prompt user for menu input
	cout << "	Main Menu" << endl;
	cout << "S -- Purchase stock" << endl;
	cout << "B -- Purchase bonds" << endl;
	cout << "L -- List portfolio securities" << endl;
	cout << "Q -- Quit" << endl << endl;
	cout << "Selection: ";
	cin >> selection;

	if (selection != 'S' && selection != 'B' && selection != 'L' && selection != 'Q' || !cin) //if not one of options or breaks cin
	{
		while (selection != 'S' && selection != 'B' && selection != 'L' && selection != 'Q' || !cin)//while its not valid
		{
			//prompt for re-entry, clear and ignore buffer, and take new input
			cout << "You must pick from one of the menu options" << endl;
			cout << "Buy Stock (S), Buy Bonds (B), List Portfolio (L), or Quit (Q): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> selection;
		}
	}
	cout << endl; //space for formatting
}
