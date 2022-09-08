#include "Bonds.h"

Bonds::Bonds() //default constuctor
	:Securities(0.0, 0) //parent constructor
{
	//set all values to null
	issuer = " ";
	faceValue = 0;
	statedInterestRate = 0.0;
}
Bonds::Bonds(double pp, int qp, std::string i, int fv, double sir)//initialized data members
	:Securities(pp, qp) //default constructor for parent
{
	//initialize data members to passed in values
	issuer = i;
	faceValue = fv;
	statedInterestRate = sir;
}

void Bonds::setIssuer(std::string i) //sets parameter to issuer
{
	issuer = i;
}

void Bonds::setFaceValue(int fv) //sets parameter to face value
{
	if ((fv <= 0) || (!std::cin))//verify valid face value
	{
		while ((fv <= 0) || (!std::cin))// if not clear buffer and reprompt
		{
			std::cout << "You must enter a valid face value (greater than 0). Please try again. " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> fv;
		}
	}

	faceValue = fv;
}

void Bonds::setStatedInterestRate(double sir) //sets paramater to stated interest rate
{
	if ((sir <= 0) || (!std::cin))//verify valid stated interst rate
	{
		while ((sir <= 0) || (!std::cin))// if not clear buffer and reprompt
		{
			std::cout << "You must enter a valid stated interest rate (greater than 0). Please try again. " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> sir;
		}
	}

	statedInterestRate = sir;
}

void Bonds::setMaturityDate(Date m) //sets paramter to maturity date
{
	//prompt maturity date
	std::cout << "Maturity date";
	//call get date for input
	m.getDate();
	maturityDate = m;
}

std::string Bonds::getIssuer() //returns issuer
{
	return issuer;
}

int Bonds::getFaceValue() //returns face value
{
	return faceValue;
}

double Bonds::getStatedInterestRate() //returns stated intertest rate
{
	return statedInterestRate;
}

Date Bonds::getMaturityDate()
{
	return maturityDate;
}

double Bonds::calcIncome() //calculates income as interest from bond purchase
{
	double income{ 0 };
	income = (getQuantityPurchased() * getFaceValue() * getStatedInterestRate());
	return income;
}

bool Bonds::operator < (const Bonds& b) const //overload < for sorting
{
	bool returnval{ false };
	if (this->issuer < b.issuer) //if current object issuer less than passed in 
	{
		returnval = true; //set true
	}
	return returnval; //return true or false
}

std::ostream& operator<<(std::ostream& output, Bonds b)
{
	//outputs all of the data of the bond

	//formatting statements
	output << std::fixed << std::showpoint << std::setprecision(2);
	//prints issuer
	output << std::left << std::setw(40) << "Issuer:" << b.getIssuer() << std::endl;
	//prints purchase date
	output << std::left << std::setw(40) << "Purchase date:" << b.getPurchaseDate() << std::endl;
	//prints quantity
	output << std::left << std::setw(40) << "Quantity:" << b.getQuantityPurchased() << std::endl;
	//print total price
	output << std::left << std::setw(40) << "Total purchase price:" << b.getPurchasePrice() << std::endl;
	//prints interest rate
	output << std::left << std::setw(40) << "Stated Interest Rate:" << (100 * b.getStatedInterestRate()) << std::endl;
	//prints income
	output << std::left << std::setw(40) << "Interest Income:" << b.calcIncome() << std::endl;
	//prints face value
	output << std::left << std::setw(40) << "Face value:" << b.getFaceValue() << std::endl;
	//prints maturity
	output << std::left << std::setw(40) << "Maturity date:" << b.getMaturityDate() << std::endl;
	return output;
}