//Given a string, find the shortest possible string which can be achieved 
//by adding characters to the end of initial string to make it a palindrome.
//
//Example
//
//For st = "abcdc", the output should be
//buildPalindrome(st) = "abcdcba".


#include <iostream>
#include <string>

bool Palindrome(std::string st)
{
	int len = st.length();
	for (int i = 0; i < len; i++) {
		int j = len - i - 1;
		if (st[i] != st[j]) {
			return false;
		}
	}
	return true;
}

std::string buildPalindrome(std::string st) {
	
	
	int len = st.length(); // Origional length
  
	std::string temp = st;
	std::reverse(temp.begin(), temp.end());
	st += temp; // connect 2 string -> palindrome already
  
  // length of st after connect 2 strs
	int len_af = st.length();

	//string for output
	std::string res = st;

	// make sortest palindrome
	while (len_af > len)
	{
		st.erase(st.begin()+len);
		if (Palindrome(st) == true)
		{
			res = st;
		}
		len_af--;
	}
	std::cout << "res: " << res << "\n";
	return res;
}


int main()
{
	std::string st = "aaaba";
	buildPalindrome(st);
	return 0;
}
