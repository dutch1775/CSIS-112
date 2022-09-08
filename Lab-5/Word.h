#pragma once

#include <vector>
#include <iostream> 

class Word
{
private:
	char* word; //char pointer to hold tokenized word from review
	int frequency; //int tracking frequncy of char token in review

public:
	Word(); //default contructor
	Word(char* tok); //contructor for class to intialize variables
	~Word(); //destructor to destroy class object
	void setWord(char* tok); //set tok to word
	char* getWord(); //return word
	void setFrequency(int f); //set frequncy of word
	void incFrequency(); //increment frequncy by one
	int getFrequency(); //return frequncy of word
	void convertToLower(); //converts token to lowercase
};