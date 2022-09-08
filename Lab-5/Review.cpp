#include "Review.h"
#include "Word.h"
#include <iomanip>

Review::Review() //constructor to initialize variables
{
	//no input or output, vector requires no intialization
}

Review::~Review() //destructor to destory class object
{
	//no output, destorys class object
}

void Review::addWord(char* token) //adds tokenized word to vector
{
	Word w(token); //instantiate word object with token
	bool duplicate{ false }; //var to hold if duplicate word
	w.convertToLower(); //convert token to lowercase

	for (int i = 0; i < words.size(); ++i) //loop through vector
	{
		int ret; //temp var to hold result of strcmp
		ret = strcmp(token, words[i].getWord()); //compare tokens, if word already in vector then up frequency of that token word
		if (ret == 0)
		{
			words[i].incFrequency();
			duplicate = true; //set that word is duplicate
		}
	}

	if (!duplicate) //verify if word token is not in vector and if original word
	{
		words.push_back(token); //add new word object to vector for review
	}
}

void Review::printWords() //prints all words in vector and frequency
{
	for (int i = 0; i < words.size(); ++i) //loop thorugh all cholesterol readings
	{
		//print word in review and frequency of that word
		std::cout << std::setw(30) << std::setfill(' ') << words[i].getWord() << std::setw(6) << words[i].getFrequency() << std::endl;
	}
}