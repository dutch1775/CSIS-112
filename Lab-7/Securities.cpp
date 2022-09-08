#include "Securities.h"

Securities::Securities() //default constructor
{
	purchasePrice = 0.0;
	quantityPurchased = 0;
}
Securities::Securities(double pp, int qp) //constructor to initialize data members
{
	purchasePrice = pp;
	quantityPurchased = qp;
}

Securities::~Securities() //destructor to delete instanitated object
{
	
}

void Securities::setPurchaseDate(Date d) //sets parameter to security purchase date
{
	d.getDate();
	purchaseDate = d;
}

void Securities::setPurchasePrice(double pp) //sets parameter to security pruchase price
{
	if ((pp <= 0) || (!std::cin))//verify valid purchase price
	{
		while ((pp <= 0) || (!std::cin))// if not clear buffer and reprompt
		{
			std::cout << "You must enter a valid purchase price (greater than 0). Please try again. " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> pp;
		}
	}

	purchasePrice = pp;
}

void Securities::setQuantityPurchased(int qp) //sets parameter to quantity purchased
{
	if ((qp <= 0) || (!std::cin))//verify valid quantity
	{
		while ((qp <= 0) || (!std::cin))// if not clear buffer and reprompt
		{
			std::cout << "You must enter a valid quantity (greater than 0). Please try again. " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> qp;
		}
	}

	quantityPurchased = qp;
}

Date Securities::getPurchaseDate() //returns purchase date of the security
{
	return purchaseDate;
}

double Securities::getPurchasePrice() //returns purchase price of the security
{
	return purchasePrice;
}

int Securities::getQuantityPurchased() //returns quantity purchased of the security
{
	return quantityPurchased;
}