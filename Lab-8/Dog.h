#pragma once

#include "Animal.h"

class Dog : public Animal  //derived class Dog from Animal
{
public:

	Dog() : Animal() //dog constructor
	{
		std::cout << "Invoking the Dog default constructor" << std::endl; //prompt user
	}

	Dog(std::string n, int a) : Animal(n, a) //dog 2-arg constructor
	{
		std::cout << "Invoking the Dog 2-argument constructor" << std::endl;  //prompt user
	}

	~Dog() //dog deconstructor
	{
		std::cout << "Invoking the Dog deconstructor" << std::endl;  ///prompt user
	}

	void move() //dog move function
	{
		std::cout << "I run." << std::endl; //prints I run
	}
};