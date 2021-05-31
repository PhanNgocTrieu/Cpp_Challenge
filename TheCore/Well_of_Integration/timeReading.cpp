/*
Timed Reading is an educational tool used in many schools to improve and advance reading skills. 
A young elementary student has just finished his very first timed reading exercise. 
Unfortunately he's not a very good reader yet, so whenever he encountered a word longer than maxLength, he simply skipped it and read on.

Help the teacher figure out how many words the boy has read by calculating the number of words in the text he has read, no longer than maxLength.
Formally, a word is a substring consisting of English letters, 
such that characters to the left of the leftmost letter and to the right of the rightmost letter are not letters.

Example

For maxLength = 4 and
text = "The Fox asked the stork, 'How is the soup?'",
the output should be
timedReading(maxLength, text) = 7.

The boy has read the following words: "The", "Fox", "the", "How", "is", "the", "soup".
*/

void rmFirst(string& s)
{
    if (s.length() == 0)
        return;
    while (s[0] < 65 || (s[0] > 90 && s[0] < 97) || s[0] > 122)
    {
        if (s.length() != 0)
            s.erase(0, 1);
        else
            return;
    }
}

void rmLast(string& s)
{
    if (s.length() == 0)
        return;
    int len = s.length() - 1;
    while (s[len] < 65 || (s[len] > 90 && s[len] < 97) || s[len] > 122)
    {
        if (s.length() != 0)
        {
            s.pop_back();
            len = s.length() - 1;
        }
        else
            return;
    }
}

// function code:
int timedReading(int maxLength, string text) {
    if (maxLength == 1)
        return 0;

    int count = 0;
    vector<string> strVec;
    stringstream ss(text);
    string word;
    while (ss >> word) {
        strVec.push_back(word);
    }

    for (string s : strVec)
    {
        rmFirst(s);
        rmLast(s);
        if (s.length() <= maxLength)
            count++;
    }
    return count;

}
