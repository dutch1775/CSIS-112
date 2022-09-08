#pragma once

//included libraries
#include <iostream>
#include <string>
#include "Date.h"
#include <iomanip>

class Securities
{
private:

	Date purchaseDate;  //security purchase date
	double purchasePrice; //security purchase price
	int quantityPurchased;  //security quantity purchased

public:

	Securities();  //default constructor
	Securities(double pp , int qp); //constructor to initialize data members
	~Securities(); //destructor to delete instanitated object
	void setPurchaseDate(Date d); //sets parameter to security purchase date
	void setPurchasePrice(double pp); //sets parameter to security pruchase price
	void setQuantityPurchased(int qp); //sets parameter to quantity purchased
	Date getPurchaseDate(); //returns purchase date of the security
	double getPurchasePrice(); //returns purchase price of the security
	int getQuantityPurchased(); //returns quantity purchased of the security

};