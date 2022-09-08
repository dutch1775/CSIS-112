#pragma once

#include "Word.h"

class Review
{
private:
	std::vector<Word> words;

public:
	Review(); //constructor two initialize variables
	~Review(); //destructor to destory class object
	void addWord(char* token); //adds tokenized word to vector
	void printWords(); //prints all words in vector and frequency
};