/*
Given a rectangular matrix of characters, add a border of asterisks(*) to it.

Example

For

picture = ["abc",
           "ded"]
the output should be

addBorder(picture) = ["*****",
                      "*abc*",
                      "*ded*",
                      "*****"]
*/

vector<string> addBorder(vector<string> picture) {
    vector<string> res;
    int size = picture.size() + 2; // 2
    int len_max = picture[0].length() + 2;

    for (int index = 0; index < size; index++)
    {
        cout << index << endl;
        if (index == 0 || index == size - 1)
        {
            string s = "";
            for (int rlen = 0; rlen < len_max ; rlen++)
            {
                s += "*";
            }
            res.push_back(s);
        }
        else
        {
            string s = "*";
            s += picture[index - 1];
            s += "*";
            res.push_back(s);
        }
        
    }
    return res;
}
