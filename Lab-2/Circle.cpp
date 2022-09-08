#include "Circle.h"

	circle::circle() //zero arg constructor
	{
		radius = 0.0; //initialize private data member
	}
	void circle::setRadius(double x) //set radius value
	{
		radius = x; //set radius to argument pass through
	}
	void circle::showData() //display all data and calculations
	{
		std::cout << "Circle radius: " << circle::getRadius() << std::endl;
		std::cout << "Circle circumference: " << circle::calcCircumference() << std::endl;
		std::cout << "Circle area: " << circle::calcArea() << std::endl;
		std::cout << "************************" << std::endl;
	}
	double circle::getRadius() const //return radius value
	{
		return radius;
	}
	double circle::calcCircumference() const //calculate the circumference using radius
	{
		double circumference{ 0 };
		circumference = (2 * 3.14 * radius);
		return circumference;
	}
	double circle::calcArea() const //calculate the area using the radius
	{
		double area{ 0 };
		area = (3.14 * pow(radius, 2));
		return area;
	}