#include "Pets.h"

Pet::Pet() //constructor that initializes the pet
{
	//initialize null values to members and tell user pet creation
	name = "";
	type = "";
	weight = 0;
	std::cout << "Creating a new pet" << std::endl;
}

void Pet::setName(std::string n) //sets the name of the pet
{
	name = n; 
}

void Pet::setType(std::string t) //sets the type of the pet
{
	type = t;
}

void Pet::setWeight(int w) //sets the weight of the pet
{
	weight = w;
}

std::string Pet::getName() //returns the name of the pet
{
	return name;
}

std::string Pet::getType() //returns the type of the pet
{
	return type;
}

int Pet::getWeight() //returns the weight of the pet
{
	return weight;
}

Pet::~Pet() //destroys call object
{
	//notify user of object destruction
	std::cout << "In the pet destructor" << std::endl;
}