#pragma once
//include libraries needed for class files
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Temperature //create class
{
public:
	
	Temperature();//one arg constructor
	Temperature(std::string mm, int yyyy);//two arg constructor
	void setYear(int yyyy);//sets year to paramater input
	int getYear() const;//returns year value
	void setMonth(std::string mm);//sets month to paramater input
	std::string getMonth() const;//returns month value
	void addTemperature(int x);//add one temp at a time to vector
	void sortTemperatures();//sorts vector values from lowest to highest
	double averageTemperature()const;//calculates the average temperature for vector values
	int lowestTemperature() const;//finds the lowest temperature in the vector
	int highestTemperature() const;//finds highest temperature in the vector
	int getNumberOfTemperature() const; //returns number of elements in vector
	void displayData();//display all calculated data

private:

	std::vector<int> temperatures;//vector to hold temps
	std::string month;//month of temperature readings
	int year;//year of temperature readinds

};