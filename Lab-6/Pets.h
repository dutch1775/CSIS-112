#pragma once
#include <string>
#include <iostream>

class Pet
{
private:
	std::string name, type; //string varibales storing pet name, and type of the test
	int weight; //int var holding weight of the pet

public:
	Pet(); //constructor that initializes the pet
	void setName(std::string n); //sets the name of the pet
	void setType(std::string t); //sets the type of the pet
	void setWeight(int w); //sets the weight of the pet
	std::string getName(); //returns the name of the pet
	std::string getType(); //returns the type of the pet
	int getWeight(); //returns the weight of the pet
	~Pet(); //destroys call object

};
