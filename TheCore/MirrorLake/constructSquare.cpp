/*Given a string consisting of lowercase English letters,
find the largest square number which can be obtained
by reordering the string's characters and replacing them with any digits you need (leading zeros are not allowed)
where same characters always map to the same digits and different characters always map to different digits.

If there is no solution, return -1.

Example

For s = "ab", the output should be
constructSquare(s) = 81.
The largest 2 - digit square number with different digits is 81.
For s = "zzz", the output should be
constructSquare(s) = -1.
There are no 3 - digit square numbers with identical digits.
For s = "aba", the output should be
constructSquare(s) = 900.
It can be obtained after reordering the initial string into "baa" and replacing "a" with 0 and "b" with 9.


Algorithm:


Take a look: 
1: 1 - 9                  {1 - 2 - 3} - {1, 4, 9}
2: 10 - 99                {4 - ... - 9} - {16 - ... - 81}
3: 100 - 999              {10 - ... - 31 }- {100 - ... - 961 }
4: 1000 - 9999		        {32 - ... - 99 } - { 1024 - ... - 9801 }
5: 10000 - 99999	        {100 - ... - 316 } - { 10000 - ... - 99856}
6: 100000 - 999999	      {317 - ... - 999 } - { 100489 - ... - 998001 }
7: 1000000 - 9999999      {1000 - ... - 3162 } - { 1000000 - .......... - 9998244}
8: 10000000 - 99999999	  {3163 - ... - 9999 } - { 10004569 - ......... - 99980001}
9: 100000000 - 999999999  {10000 - ... - 31622 } - { 100000000 - ........ - 999950884}

example:
s = "aaaabbcde" => sort(s) = "11124" (sorting by numbers of letter)
digits of string = 9
=> top_limit = 31622 
=> bottom_limit = 9999

finding square_number from top to bottom (because we find largest square number)
loop
{
  square_number = top_limit*top_limit;
  string sq_number = to_string(square_number);
  sort(sq_number)
  if (sort(s) == sort(sq_number)
  {
    return square_number;
  }
}

return -1;

*/


std::vector<int> format(std::string s) {
	map<char, int> mapping;
	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];
		if (mapping.find(ch) == mapping.end()) {
			mapping[ch] = 0;
		}
		mapping[ch]++;
	}
	vector<int> res;
	for (auto it : mapping) {
		res.push_back(it.second);
	}
	sort(res.begin(), res.end());

	for (auto it : res)
	{
		cout << res[it] << " ";
	}
	cout << "\n";
	return res;
}

int constructSquare(std::string s) {

	if (s.length() == 1)
		return 9;

	
	int square_upper_limit = ceil(sqrt(pow(10, s.length()))); // 10
	int square_below_limit = floor(sqrt(pow(10, s.length() - 1) - 1)); // 99
	vector<int> vs = format(s);


	
	std::cout << "upper_limit: " << square_upper_limit << "\n";
	std::cout << "bottom_limit: " << square_below_limit << "\n";



	for (int num = square_upper_limit; num >= square_below_limit; num--) {
		long long res = num;
		res *= res;
		stringstream ss;
		ss << res;
		string t = ss.str();
		vector<int> vt = format(t);
		if (vs.size() == vt.size()) {
			bool equal = true;
			for (int i = 0; i < vs.size(); i++) {
				if (vs[i] != vt[i]) {
					equal = false;
					break;
				}
			}
			if (equal)
				return res;
		}
	}
	return -1;	
}
