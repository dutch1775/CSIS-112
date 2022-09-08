#include "Word.h"

Word::Word() //default constrcutor
{
	word = nullptr;
	frequency = 0;

}
Word::Word(char* tok) //contructor for class to intialize variables
{
	setWord(tok); //set parameter to word 
	setFrequency(1); //set frequency for new word to 1
}

Word::~Word() //destructor to destroy class object
{
	//no output, destorys class object
}
void Word::setWord(char* tok) //set tok to word
{
	word = tok; //set pointer token to word
}

char* Word::getWord() //return word
{
	return word; //return word
}

void  Word::setFrequency(int f) //set frequncy of word
{
	frequency = f; //set paramter to frequency
}

void Word::incFrequency() //increment frequncy by one
{
	frequency++; //increment frequency by one
}

int  Word::getFrequency() //return frequncy of word
{
	return frequency; //return value of frequency
}

void Word::convertToLower() //converts token to lowercase
{	
	*word = tolower(*word); //sets word data member to lowercase
}