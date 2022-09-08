#pragma once

//included libraries
#include "Bonds.h"
#include "Stocks.h"
#include <vector>

class Portfolio
{ 

private:

	std::string name;  //name of portfolio
	std::vector<Bonds> portfolioBonds;  //vetor of bonds
	std::vector<Stocks> portfolioStocks;  //vector of stocks

public:

	Portfolio();  //default constructor
	Portfolio(std::string n); //constructor to initialize data members
	void setName(std::string n); //sets parameter to portfolio name
	std::string getName(); //return portfolio name
	void addBond(); //add purchased bond to portfolio
	void addStock(); //add purchased stock to portfolio
	void sortStocks(); //sorts the stocks vector
	void sortBonds(); //sorts the Bonds vector
	void printPortfolio(); //prints all stocks and bonds in portfolio along with the needed info

};
