#pragma once

#include "Animal.h"

class Fish : public Animal  //derived fish class from animal
{
public:

	Fish() : Animal() //fish default constructor
	{
		std::cout << "Invoking the Fish default constructor" << std::endl; //prompt user
	}

	Fish(std::string n, int a) : Animal(n, a)  //fish 2-arg constructor
	{
		std::cout << "Invoking the Fish 2-argument constructor" << std::endl;  //prompt user
	}

	~Fish()  //deconstructor 
	{
		std::cout << "Invoking the Fish deconstructor" << std::endl;  //prompt user
	}

	void move()  //fish move fucntion
	{
		std::cout << "I swim." << std::endl; //print i swim
	}
};