#pragma once

//included libraries
#include <string>
#include <iostream>

class Animal  //create base class
{

private:

	std::string name;  //name of the animal
	int age;  //age of the animal
	 
public:

	Animal()  //default constructor
	{
		name = " ";  //set name to null
		age = 0;  //set age to zero
		std::cout << "Invoking the Animal default constructor" << std::endl; //prompt user about constructor
	}

	Animal(std::string n, int a) //2-arg constructor
	{
		name = n; //sets name to parameter
		age = a;  //sets age to paramter
		std::cout << "Invoking the Animal 2-argument constructor" << std::endl;  //prompt user about constrcutor
	}

	virtual ~Animal()  //virtual deconstructor
	{
		std::cout << "Invoking the Animal destructor" << std::endl;  //prompt user about deconstructor
	}

	void setName(std::string n)  //set name to parameter
	{
		name = n;
	}

	void setAge(int a)  //set age to parameter
	{
		age = a;
	}

	std::string getName() const//return name
	{
		return name;
	}

	double getAge() const //return age
	{
		return age;
	}

	virtual void move() = 0; //pure virtual function move

};
