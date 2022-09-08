#pragma once

#include "Animal.h"

class Rabbit : public Animal  //derived class Rabbit from Animal
{
public:

	Rabbit() : Animal() //rabbit deafult constructor
	{
		std::cout << "Invoking the Rabbit default constructor" << std::endl; //prompt user
	}

	Rabbit(std::string n, int a) : Animal(n, a) //rabbit 2-arg constructor
	{
		std::cout << "Invoking the Rabbit 2-argument constructor" << std::endl; //prompt user
	}

	~Rabbit() //deconstructor
	{
		std::cout << "Invoking the Rabbit deconstructor" << std::endl; //prompt user
	}

	void move() //rabbit move function
	{
		std::cout << "I hop." << std::endl; //print I hop
	}
};