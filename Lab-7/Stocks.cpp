#include "Stocks.h"

Stocks::Stocks()  //default constructor 
	:Securities(0.0, 0)  //parent default constructor
{
	ticker = " ";
	parValue = 0;
	dividendPerShare = 0.0;
}
Stocks::Stocks(double pp, int qp, std::string t, int pv, double dps) //constructor to initialize member variables
	:Securities(pp, qp)   //parent default constructor
{
	ticker = t;
	parValue = pv;
	dividendPerShare = dps;
}

void Stocks::setTicker(std::string t) //sets parameter to ticker symbol
{
	ticker = t;
}

void Stocks::setParValue(int pv) //sets paramter to par value
{
	if ((pv <= 0) || (!std::cin))//verify valid par value
	{
		while ((pv <= 0) || (!std::cin))// if not clear buffer and reprompt
		{
			std::cout << "You must enter a valid par value (greater than 0). Please try again. " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> pv;
		}
	}

	parValue = pv;
}

void Stocks::setStockType(char u) //sets user input to enum for stock type
{
	if ((u != 'C') && (u != 'P') || (!std::cin))//verify valid stock type
	{
		while ((u != 'C') && (u != 'P') || (!std::cin))// if not clear buffer and reprompt
		{
			std::cout << "You must enter a valid stock type Common or Prefered Stock (C or P). Please try again. " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> u;
		}
	}

	if (u == 'C') //if C set to COMMON enum
	{
		stockType = COMMON;
	}
	else if (u == 'P') // if P set to PREFERED enum
	{
		stockType = PREFERED;
	}
}

void Stocks::setDividentPerShare(double dps) //sets parameter to dividends per share
{
	if ((dps <= 0) || (!std::cin))//verify valid dividends per share
	{
		while ((dps <= 0) || (!std::cin))// if not clear buffer and reprompt
		{
			std::cout << "You must enter a valid dividends per share (greater than 0). Please try again. " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> dps;
		}
	}

	dividendPerShare = dps;
}

std::string Stocks::getTicker() //returns ticker symbol
{
	return ticker;
}

int Stocks::getParValue() //returns par value
{
	return parValue;
}

std::string Stocks::getStockType() //returns stock type
{
	std::string type;
	if (stockType == PREFERED) //if PREFERED enum return Prefered
	{
		type = "Prefered";
	}
	else if (stockType == COMMON)//if COMMON enum return Common
	{
		type = "Common";
	}
	
	return type;
}

double Stocks::getDividendsPerShare() //returns dividends per share
{
	return dividendPerShare;
}

double Stocks::calcIncome() //calculates income as dividend from stock purchase
{
	double income{ 0 };
	income = (getDividendsPerShare() * getQuantityPurchased());
	return income;
}

bool Stocks::operator < (const Stocks& s) const
{
	bool returnval{ false };
	if (this->ticker < s.ticker) //if current object ticker greater than compared object
	{
		returnval = true; //return true
	}
	return returnval;  //return value
}

std::ostream& operator<<(std::ostream& output, Stocks s)
{
	//print all stock information
	//format statements
	output << std::fixed << std::showpoint << std::setprecision(2);
	//print ticker
	output << std::left << std::setw(40) << "Ticker symbol:" << s.getTicker() << std::endl;
	//print purchase date
	output << std::left << std::setw(40) << "Purchase date:" << s.getPurchaseDate() << std::endl;
	//print total price
	output << std::left << std::setw(40) << "Total price:" << s.getPurchasePrice() << std::endl;
	//print quantity
	output << std::left << std::setw(40) << "Quantity of shares:" << s.getQuantityPurchased() << std::endl;
	//print par value
	output << std::left << std::setw(40) << "Par value:" << s.getParValue() << std::endl;
	//print dividends per share
	output << std::left << std::setw(40) << "Dividends per share:" << s.getDividendsPerShare() << std::endl;
	//print income
	output << std::left << std::setw(40) << "Dividends Income:" << s.calcIncome() << std::endl;
	//print price per share
	output << std::left << std::setw(40) << "Price per share:" << (s.getPurchasePrice() / s.getQuantityPurchased()) << std::endl;
	//print type
	output << std::left << std::setw(40) << "Type:" << s.getStockType() << std::endl;
	return output;
}