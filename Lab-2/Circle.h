#pragma once
#include <iostream>

class circle
{
private:
	double radius; //radius for circle basis of all calculations (floating point type)
public:
	circle(); //zero arg constrcutor
	void setRadius(double radius); //sets radius for that iteration
	void showData(); //displays all calculated data
	double getRadius() const; //returns radius
	double calcCircumference() const; //calculates and returns circumference
	double calcArea() const; //calculates and returns circumferences
};