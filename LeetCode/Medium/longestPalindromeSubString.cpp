/*

Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

*/

int pallindromeLength(int &l, int &r, string &s) {
    while(l >= 0 && r < s.size() && s[l] == s[r]) {
        l--; r++;
    }
    l++; r--;
    return (r-l+1);
}

string longestPalindrome(string s) {
    string ans = "";
    int len = 0, maxLen = 0, idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        int left = i-1, right = i+1;
        len = pallindromeLength(left, right, s);
        idx = (len > maxLen) ? left : idx;
        maxLen = max(len, maxLen);
        
        left = i; right = i+1;
        len = pallindromeLength(left, right, s);
        idx = (len > maxLen) ? left : idx;
        maxLen = max(len, maxLen);
    }
    
    if (maxLen)
        ans = s.substr(idx, maxLen);
    return ans;
}