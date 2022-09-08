#include "Circle.h"

using namespace std;

void wait();
void userRadiusInput(double& inputRadius); //validates input for class set function

int main()
{
	circle c; //create class
	double inputRadius{ 0 }; //arugment variable for validation

	userRadiusInput(inputRadius);//validate radius

	if (inputRadius != -1) //if not -1
	{
		while (inputRadius != -1) //while not -1
		{
			c.setRadius(inputRadius);//set radius
			c.calcArea();//calculate area
			c.calcCircumference();//calculate circumference
			c.showData();//display all calculates
			userRadiusInput(inputRadius);// reset radius for new calc or termination
		}
	}

	void wait();
	return 0;
}

void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer 
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}
void userRadiusInput(double& inputRadius)
{
	cout << "Enter the radius of the cirle (Enter -1 to exit): "; //enter radius or exit loop
	cin >> inputRadius;

	if ((inputRadius == 0) || (inputRadius < -1) || (!cin))//if less than 0, but not -1, or non-numeric then retry
	{
		while ((inputRadius == 0) || (inputRadius < -1) || (!cin))//clear buffer and retry
		{
			cout << "You must enter a positive number. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> inputRadius;
		}
	}
}