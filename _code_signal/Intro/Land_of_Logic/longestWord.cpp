//Define a word as a sequence of consecutive English letters.Find the longest word from the given string.
//
//Example
//
//For text = "Ready, steady, go!", the output should be
//longestWord(text) = "steady".


#include <iostream>
#include <string>

std::string longestWord(std::string text) {

	std::string word = "";
	std::string longest = "";
	for (auto x : text)
	{
		if ( ((x < 65 || x > 90) && (x < 97 || x >122)) )
		{		
			word = "";
		}
		else
		{
			word += x;
		}

		if (word.length() > longest.length())
		{
			//std::cout << "word: " << word << std::endl;
			longest = word;
		}
	}
	std::cout << "longest word: " << longest << std::endl;
	return longest;
}


int main()
{
	std::string text = "ready, steady, go!";
	longestWord(text);
	return 0;
}
