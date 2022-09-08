#include "Temperature.h"
#include <fstream>

using namespace std;

int main()
{
	Temperature t; //create class object
	ifstream inData; //input file variable
	string fileName; //var to hold filename
	string inputMonth; //var to hold month
	int num{ 0 }, inputYear{ 0 }; //var to hold temps and year, respectively
	bool goodFile = false; //var to check if file had any problems

	//prompt user for file, grab input text, and open file
	cout << "Enter the name of the temperature file: ";
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

	//when file opens, grab month and year variables from first two lines
	inData >> inputMonth;
	t.setMonth(inputMonth);
	inData >> inputYear;
	t.setYear(inputYear);
	inData >> num; //read in a temp value from the file
	
	while (!inData.fail()) //check if fail state for input reading
	{
		
		t.addTemperature(num);//store file input in vector using function
		inData >> num; //read in a value from the file

		/*If the file object goes into the fail state, BUT the eof has not been
		reached, then the problem is due to reading a non-numeric value into
		a variable designed to hold a numeric value. */

		if (inData.fail() && !inData.eof())
		{
			cout << "A non-numeric value was found in the file...Exiting program. " << endl
				 << endl << "Please correct the problem and restart the application." << endl;
		}

		/*If the file object goes into the fail state, and the eof has been reached,
		the file object is in the fail state because the program has read past the end of the file.
		This can occur if the file is empty.  If the file is empty and you try to read in anything,
		the file object immediately goes into the fail state, and the eof function returns TRUE. */
		else if (inData.fail() && inData.eof())
		{
			cout << "End of file reached." << endl;
			goodFile = true;
		}
	}
	inData.close(); //close file
	cout << endl;
	
	if (goodFile == true) //file contained no errors so readout is appropriate
	{
		t.displayData();//display temp data
	}

	system("pause");
	return 0;
}
