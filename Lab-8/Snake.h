#pragma once

#include "Animal.h"

class Snake : public Animal  //derived snake class from animal
{
public:

	Snake() : Animal()  //default constructor
	{
		std::cout << "Invoking the Snake default constructor" << std::endl;  //prompt user
	}

	Snake(std::string n, int a) : Animal(n, a)  //2-arg constructor 
	{
		std::cout << "Invoking the Snake 2-argument constructor" << std::endl;//prompt user
	}

	~Snake() //deconstructor
	{
		std::cout << "Invoking the snake deconstructor" << std::endl; //prompt user
	}

	void move() //snake move func
	{
		std::cout << "I slither." << std::endl; //print i slither
	}
};