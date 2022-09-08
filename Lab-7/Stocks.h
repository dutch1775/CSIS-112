#pragma once

//include parent
#include "Securities.h"

//stock class derived from securities
class Stocks : public Securities
{
	//overload << to cout stock
	friend std::ostream& operator<<(std::ostream&, Stocks);

private:
	
	std::string ticker;  //stock ticker symbol
	int parValue;  //stock par value
	enum typeOfStocks {COMMON, PREFERED};  //enum for stock type
	typeOfStocks stockType; //variable to told stock type enum
	double dividendPerShare;  //stock dividend per share

public:

	Stocks();  //default constuctor
	Stocks(double pp, int qp, std::string t, int pv, double dps); //constructor to initialize member variables
	void setTicker(std::string t); //sets parameter to ticker symbol
	void setParValue(int pv); //sets paramter to par value
	void setStockType(char u); //sets user input to enum for stock type
	void setDividentPerShare(double dps); //sets parameter to dividends per share
	std::string getTicker(); //returns ticker symbol
	int getParValue(); //returns par value
	std::string getStockType(); //returns stock type
	double getDividendsPerShare(); //returns dividends per share
	double calcIncome(); //calculates income as dividend from stock purchase
	bool operator < (const Stocks& s) const;  //overload < for stock sorting

};
