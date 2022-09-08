#include "Temperature.h"


	Temperature::Temperature() // 0 arg constructor
	{
		//initalize data members to zero
		month = "";
		year = 0;
	}
	Temperature::Temperature(std::string mm, int yyyy) //2 arg constructor
	{
		//initalize data members to paramter input
		month = mm;
		year = yyyy;
	}
	void Temperature::setYear(int yyyy) //sets year to paramater input
	{
		year = yyyy;
	}
	int Temperature::getYear() const //returns year value
	{
		return year;
	}
	void Temperature::setMonth(std::string mm) //sets month to paramater input
	{
		month = mm;
	}
	std::string Temperature::getMonth() const //returns month value
	{
		return month;
	}
	void Temperature::addTemperature(int x) //add one temp at a time to vector
	{
		temperatures.push_back(x);
	}
	void Temperature::sortTemperatures() //sorts vector values from lowest to highest
	{
		sort(temperatures.begin(), temperatures.end());
	}
	double Temperature::averageTemperature() const //calculates the average temperature for vector values
	{
		double sigmaX{ 0 }; //sigma of all temperature readings
		double averageTemp;//average temp value
		for (int i = 0; i < temperatures.size(); ++i)
		{
			sigmaX = temperatures[i] + sigmaX; //in loop add all temp values together
		}
		averageTemp = (sigmaX / getNumberOfTemperature()); //divide sigmaX by size of vector
		return averageTemp;
	}
	int Temperature::lowestTemperature() const //finds the lowest temperature in the vector
	{
		int min = temperatures[0];
		for (int i = 1; i < temperatures.size(); ++i) //loop through vector starting from fisrt element
		{
			if (temperatures[i] < min)//if new looped element smaller than last, make that the new min
			{
				min = temperatures[i];
			}
		}
		return min;
	}
	int Temperature::highestTemperature() const //finds highest temperature in the vector
	{
		int max = temperatures[0];
		for (int i = 1; i < temperatures.size(); ++i)  //loop through vector starting from fisrt element
		{
			if (temperatures[i] > max) //if new looped element larger than last, make that the new max
			{
				max = temperatures[i];
			}
		}
		return max;
	}
	int Temperature::getNumberOfTemperature() const  //returns number of elements in vector
	{
		return  temperatures.size();
	}
	void Temperature::displayData() //display all calculated data
	{
		sortTemperatures(); //sort vector
		std::cout << "Statistics" << std::endl; //prompt stats display
		std::cout << "Number of temperatures: " << getNumberOfTemperature() << std::endl; //print number of temperature
		std::cout << "Average: " << averageTemperature() << std::endl; //print average temp value
		std::cout << "Lowest Temperature: " << lowestTemperature() << std::endl; //print lowest temp
		std::cout << "Highest Temperature: " << highestTemperature() << std::endl << std::endl; //print highest temp
		std::cout << "The temperatures for " << getMonth() << " " << getYear() << " are: " << std::endl;
		//print all temps in specified month and year

		for (int i = 0; i < temperatures.size(); ++i) //loop through vector priting all values (sorted)
		{
			std::cout << temperatures[i] << std::endl;
		}
	}

