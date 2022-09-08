#pragma once

//necessary libraries
#include <iostream>
#include <cstdlib>
#include <cctype>

class Date 
{
	//overload << operator to cout date
	friend std::ostream& operator<<(std::ostream&, Date);

public:

	//constructor 
	Date(int d = 0, int m = 0, int yyyy = 0) //if no paramters set default
	{
		setDate(d, m, yyyy); //calls set date function for passed in values
	}

	//destructor to delete date object
	~Date()
	{
	
	}

	//sets the date by passing in day, month, and year
	void setDate(int  d, int m, int yyyy) 
	{
		day = d;
		month = m;
		year = yyyy;
	}

	void getDate() //get user input date
	{
		int m, d, y; //variables for day, month, and year
		char charDate[20]; //holds the date the user entered in char array
		std::cout << "\nEnter a date (mm/dd/yyyy): ";  //prompt for date entry
		std::cin >> charDate;

		tokenizeDate(charDate, m, d, y); //separates char array into month, day, and year

		if ((m < 1 || m > 12) || (d < 1 || d > 31) || (y < 1775 || y > 3000) || (!std::cin))//verify valid date
		{
			while ((m < 1 || m > 12) || (d < 1 || d > 31) || (y < 1775 || y > 3000) || (!std::cin))// if not clear buffer and reprompt
			{
				std::cout << "You must enter a valid Enter a date(mm / dd / yyyy). Please try again. " << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> charDate;
				tokenizeDate(charDate, m, d, y); //separates char array into month, day, and year
			}
		}
		this->setDate(d, m, y); //sets the date of the object using the parsed values
	}

	void tokenizeDate(char* cDate, int& month, int& day, int& year)//tokenizes date
	{
		char seps[] = "/";
		char* token = NULL;
		char* next_token = NULL;

		token = NULL;
		next_token = NULL;
		// Establish string and get the tokens:  
		token = strtok_s(cDate, seps, &next_token);
		month = atoi(token);
		token = strtok_s(NULL, seps, &next_token);
		day = atoi(token);
		token = strtok_s(NULL, seps, &next_token);
		year = atoi(token);
	}

private:

	int day;
	int month;
	int year;

};

//overloaded << for date output
inline std::ostream& operator<<(std::ostream& output, Date d)
{
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}
