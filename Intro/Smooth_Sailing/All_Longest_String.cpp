/*
Given an array of strings, return another array containing all of its longest strings.

Example

For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
allLongestStrings(inputArray) = ["aba", "vcd", "aba"].
*/
std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
    
    std::vector<std::string> outputArray;
	int longest_length = inputArray[0].length();
	for (int i = 1; i < inputArray.size(); i++)
	{
		if (inputArray[i].length() > longest_length)
		{
			longest_length = inputArray[i].length();
		}
	}

	for (int j = 0; j < inputArray.size(); j++)
	{
		if (inputArray[j].length() == longest_length)
		{
			outputArray.push_back(inputArray[j]);
		}
	}

	return outputArray;
    
}
