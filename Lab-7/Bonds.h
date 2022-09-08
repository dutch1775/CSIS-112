#pragma once

//include parent
#include "Securities.h"

//bond class derived from securities
class Bonds : public Securities
{
	//overload << for cout
	friend std::ostream& operator<<(std::ostream&, Bonds);

private:

	std::string issuer;  //issuer of the bond
	int faceValue;  //face value of the bond
	double statedInterestRate;  //the stated interest rate of the bond
	Date maturityDate;  //maturity date of the bond

public:

	Bonds(); //default constructor
	Bonds(double pp, int qp, std::string i,  int fv, double sir); //constructor to initialize data members
	void setIssuer(std::string i); //sets parameter to issuer
	void setFaceValue(int fv); //sets parameter to face value
	void setStatedInterestRate(double sir); //sets paramater to stated interest rate
	void setMaturityDate(Date d); //sets paramter to maturity date
	std::string getIssuer(); //returns issuer
	int getFaceValue(); //returns face value
	double getStatedInterestRate(); //returns stated intertest rate
	double calcIncome(); //calculates income as interest from bond purchase
	Date getMaturityDate(); //returns the issue date
	bool operator < (const Bonds& b) const; //overloads the < for sorting

};

