#include "Portfolio.h"
#include <algorithm>

Portfolio::Portfolio() //default constructor
{
	name = " ";
}
Portfolio::Portfolio(std::string n) //constructor to initialize data members
{
	name = n;
}

void Portfolio::setName(std::string n) //sets parameter to portfolio name
{
	name = n;
}

std::string Portfolio::getName() //return portfolio name
{
	return name;
}

void Portfolio::addBond() //add purchased bond to portfolio
{
	//prompt purchase
	std::cout << std::setw(5) << "Purchase Bonds" << std::endl << std::endl;
	//add Bond to vector
	Bonds b; //instantiate patient object
	Date d, m; //instantiate purchase date and maturity date objects

	//variables for input
	double inPrice{ 0 }, inStated{ 0 };
	int inQuant{ 0 }, inFace{ 0 };
	std::string inIss;

	//get purchase date
	std::cout << "Purchase date";
	b.setPurchaseDate(d);

	//get purchase price
	std::cout << "Total purchase price: ";
	std::cin >> inPrice;
	b.setPurchasePrice(inPrice);

	//get quantity
	std::cout << "Quantity purchased: ";
	std::cin >> inQuant;
	b.setQuantityPurchased(inQuant);

	//clear buffer and get issuer
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Issuer: ";
	std::getline(std::cin, inIss);
	b.setIssuer(inIss);
	
	//get face value
	std::cout << "Face value: ";
	std::cin >> inFace;
	b.setFaceValue(inFace);

	//get stated interest
	std::cout << "Stated interest rate (Enter as a decimal): ";
	std::cin >> inStated;
	b.setStatedInterestRate(inStated);

	//get maturity date
	b.setMaturityDate(m);

	std::cout << std::endl; //space for formatting

	//add bond to vector
	portfolioBonds.push_back(b);
}

void Portfolio::addStock() //add purchased stock to portfolio
{
	//prompt user to purhcase
	std::cout << std::setw(5) << "Purchase Stocks" << std::endl << std::endl;
	Stocks s; //instantiate stock object
	Date d; //instantiate date onject
	
	//variables to hold input values
	double inPrice{ 0 }, inDividend{ 0 };
	int inQuant{ 0 }, inPar{ 0 };
	std::string inTick;
	char inType;

	//get the purchase date
	std::cout << "Purchase date";
	s.setPurchaseDate(d);

	//get total purchase price
	std::cout << "Total purchase price: ";
	std::cin >> inPrice;
	s.setPurchasePrice(inPrice);
	
	//get quantity purchased
	std::cout << "Quantity purchased: ";
	std::cin >> inQuant;
	s.setQuantityPurchased(inQuant);

	//clear buffer and prompt for Ticker
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Ticker symbol: ";
	std::getline(std::cin, inTick);
	s.setTicker(inTick);

	//get the par value
	std::cout << "Par value: ";
	std::cin >> inPar;
	s.setParValue(inPar);

	//get stock type
	std::cout << "Stock type (C for Common or P for Preferred): ";
	std::cin >> inType;
	s.setStockType(inType);


	//get the dividends per share
	std::cout << "Dividends per share: ";
	std::cin >> inDividend;
	s.setDividentPerShare(inDividend);

	std::cout << std::endl; //space for formatting

	portfolioStocks.push_back(s); //add stock to vector
}

void Portfolio::sortStocks() //sorts the stocks vector
{
	//sort stock vector
	sort(portfolioStocks.begin(), portfolioStocks.end());
}

void Portfolio::sortBonds() //sorts the Bonds vector
{
	//sort bond vector
	sort(portfolioBonds.begin(), portfolioBonds.end());
}

void Portfolio::printPortfolio() //prints all stocks and bonds in portfolio along with the needed info
{
	//sort stocks
	sortStocks();
	//prompt user
	std::cout << "These are the STOCKS in your " << getName() << " portfolio:" << std::endl << std::endl;
	for (int i = 0; i < portfolioStocks.size(); i++) //loop througl all of stocks
	{
		std::cout << portfolioStocks[i] << std::endl; //print stock information
	}

	//sort bonds
	sortBonds();
	//prompt user
	std::cout << "These are the BONDS in your " << getName() << " portfolio:" << std::endl << std::endl;
	for (int i = 0; i < portfolioBonds.size(); i++) //loop througl all of bonds
	{
		std::cout << portfolioBonds[i] << std::endl; //print bond information
	}

}