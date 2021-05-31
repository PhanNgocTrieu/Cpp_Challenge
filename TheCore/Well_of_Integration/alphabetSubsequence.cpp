/*
Check whether the given string is a subsequence of the plaintext alphabet.

Example

For s = "effg", the output should be
alphabetSubsequence(s) = false;
For s = "cdce", the output should be
alphabetSubsequence(s) = false;
For s = "ace", the output should be
alphabetSubsequence(s) = true;
For s = "bxz", the output should be
alphabetSubsequence(s) = true.

*/

bool alphabetSubsequence(string s) {
    
    char prev = 'a';
    for (char c : s)
    {
        if (s[0] == 'a')
            continue;
        
        if (c <= prev)
            return false;
        prev = c;
    }
    
    return true;
}
