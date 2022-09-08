//Lab 1 - Loan Payment Calculator

/*The program is a mortgage calculator that determines a monthly payment for loans.
The application prompts for principle, credit score, loan term, and generates an interest rate.
Then it will calculate the monthly payment.*/
//Michael Dutchin
//CSIS 112

#include <iostream>
#include <random> //for rand num generator
#include <iomanip>

using namespace std;

void wait();
void getPrinciple(double& principle);
void getCreditScore(int& creditScore);
void getTerm(int& loanTerm);
void setInterestRate(int& creditScore, double& interestRate);
double CalcPayment(double& principle, int& creditScore, int& loanTerm, double& interestRate, double& loanPayment);

int main()
{
	cout << "Lab 1: Loan Calculator" << endl;

	//delcare and initialize variables for loan principle, interest rate,
	//credit score, loan term, and the monthly payment.
	double principle{ 0.0 }, interestRate{ 0.0 };
	int creditScore{ 0 }, loanTerm{ 0 };
	double loanPayment{ 0 };

	getPrinciple(principle);//call function to get principle of the loan
	getCreditScore(creditScore);//call function to get the credit score

	if (creditScore < 300) //if credit score too low then deny loan
	{
		cout << "Your credit score is too low. You do not qualify for a loan at this time." << endl;
	}
	else //if credit score is acceptable continue with loan
	{
		getTerm(loanTerm);//call function to get loan term
		setInterestRate(creditScore, interestRate);//call function to set an interest rate
		CalcPayment(principle, creditScore, loanTerm, interestRate, loanPayment);//calculate monthly payment

		//display formatted monthly payment
		cout << endl << "Your monthly loan payment is "
			 << fixed << showpoint << setprecision(2) << '$' << loanPayment << endl << endl;
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
void getPrinciple(double& principle)
{
	cout << "Enter the principle amount for the loan: $"; //prompt user for principle amount
	cin >> principle;

	if ((principle < 0) || (!cin)) //verify that input is numeric and positive
	{
		while ((principle < 0) || (!cin))//if not numeric and postiive clear buffer and reprompt
		{
			cout << "You must enter a positive number. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> principle;
		}
	}
}
void getCreditScore(int& creditScore)
{
	cout << "Enter customer credit score: ";//prompt user for credit score
	cin >> creditScore;

	if ((creditScore < 0) || (creditScore > 850) || (!cin)) //verify score is positive, numeric, and less than 850
	{
		while ((creditScore < 0) || (creditScore > 850) || (!cin))//if not usable then clear buffer and reprompt
		{
			cout << "You must enter a number below 850. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> creditScore;
		}
	}
}
void getTerm(int& loanTerm)
{
	//prompt for loan terms of 10, 15, or 30 years
	cout << "Enter the term of the loan (Acceptable terms are 10, 15, and 30 years): ";
	cin >> loanTerm;

	if ((loanTerm != 30) && (loanTerm != 10) && (loanTerm != 15) || (!cin))//verify input is 10, 15, or 30
	{
		while ((loanTerm != 30) && (loanTerm != 10) && (loanTerm != 15) || (!cin))// if not clear buffer and reprompt
		{
			cout << "You must enter a number. Please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> loanTerm;
		}
	}
}
void setInterestRate(int& creditScore, double& interestRate)
{
	enum creditEvaluation { EXCELLENT, GOOD, FAIR, BAD };//create enum for credit score
	creditEvaluation creditRating;
	double divide = 100.0;//create double to divide generated int

	//assign each credit score range a rating enum
	if (creditScore >= 720)
	{
		creditRating = EXCELLENT;
	}
	else if (creditScore >= 690)
	{
		creditRating = GOOD;
	}
	else if (creditScore >= 630)
	{
		creditRating = FAIR;
	}
	else if (creditScore >= 300)
	{
		creditRating = BAD;
	}

	//using enum for credit score generate a random int for interest rate for each enum case
	//each case will vary in interest range and assign rand int to interestRate
	switch (creditRating)
	{
	case EXCELLENT:
	{random_device rdevice{};//seed for random number every iteration
	default_random_engine num{ rdevice() };//nums generated will be random
	uniform_int_distribution<int> randInterestRate(275, 400);//gen rand num between given numbers
	interestRate = randInterestRate(num);}//generate num and assign to interestRate
		break;
	case GOOD:
	{random_device rdevice{};
	default_random_engine num{ rdevice() };
	uniform_int_distribution<int> randInterestRate(401, 650);//same steps just different number range
	interestRate = randInterestRate(num);}
		break;
	case FAIR:
	{random_device rdevice{};
	default_random_engine num{ rdevice() };
	uniform_int_distribution<int> randInterestRate(651, 875);//same steps just different number range
	interestRate = randInterestRate(num);}
		break;
	case BAD:
	{random_device rdevice{};
	default_random_engine num{ rdevice() };
	uniform_int_distribution<int> randInterestRate(876, 1050);//same steps just different number range
	interestRate = randInterestRate(num);}
		break;
	}
	
	//divide interestRate by double 100 to make double percentage
	interestRate = (interestRate / divide);
}
double CalcPayment(double& principle, int& creditScore, int& loanTerm, double& interestRate, double& loanPayment)
{
	double r;//create varibales for calculations
	int n;

	r = (interestRate / 12)/100; //interest rate per period
	n = loanTerm * 12; //total number of payments or periods

	//calculate monthly payment using the provided formula and calculation variables
	loanPayment = (principle * (r * (pow(1 + r, n))) / ((pow(1 + r, n)) - 1));

	//return calculated value
	return loanPayment;
}