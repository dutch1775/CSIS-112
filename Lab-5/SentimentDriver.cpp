#include "Review.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
    Review r; //instantiate class variable
	char reviewInput[1000]; //create char array for file storage
    string fileName; //user input file name
    ifstream inData; //ifstream var to hold file data
    char seps[] = " .;!,\t\n"; //serparators for tokenization
    char* token = NULL; //pointer token for initial tokenization of review word
    char* next_token = NULL; //pointer for next token

    //prompt user for file name adn error check for file
    cout << "Enter the name of the review file: ";
    getline(cin, fileName);
    inData.open(fileName);
    //check to see if file opened, if not loop until valid file is found and opened
    if (!inData)
    {
        while (!inData)
        {
            cout << "Input file cannot be found. Please retry: ";
            getline(cin, fileName);
            inData.open(fileName);
        }
    }
    cout << endl;
    //read in file data into char array
    inData.getline(reviewInput, 1000);
    //print review in sentence form
    cout << reviewInput;
    cout << endl << endl;
    inData.close(); //close the file opened

    // Establish string and get the first token:
    token = strtok_s(reviewInput, seps, &next_token);

    // While there are tokens in char array
    while ((token != NULL))
    {
        // Get next token:
        if (token != NULL)
        {
            r.addWord(token); //add token to review word vector
            token = strtok_s(NULL, seps, &next_token); //tokenize next word in array
        }
    }
    //re-Nullify tokens for security
    token = NULL;
    next_token = NULL;

    r.printWords(); // print words and frequencies from array
    cout << endl;

	system("pause");
	return 0;
}