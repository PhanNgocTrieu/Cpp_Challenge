// You are given an array of desired filenames in the order of their creation. Since two files cannot have equal names, 
// the one which comes later will have an addition to its name in a form of (k), 
// where k is the smallest positive integer such that the obtained name is not used yet.
// Return an array of names that will be given to the files.
// Example
// For names = ["doc", "doc", "image", "doc(1)", "doc"], the output should be
// fileNaming(names) = ["doc", "doc(1)", "image", "doc(1)(1)", "doc(2)"].



/*
Algorithm:

1. we put a elemen of file names into a track(vector)
2. if track.empty() == true => put element right away!
   if track.empty() != true => we need to check
3. check for how many elements has the same file_name in track
   if they exist in track k = k + n (time exists)
   => string = names[i] + (k)
   continuing to check string = names[i] + (k), if exist => string = "names[i] + (k) + (g)";

4. return str_res;
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> fileNaming(vector<string> names) {
    vector<string> res {}; // initializing a vector
    for (string s : names) // take element one by one
    {
        // if vector of res is empty put string_element into vector right away!
        if (res.empty())
        {
            res.push_back(s);
        }
        else
        {
            string temp_str;
            int i = 0;
            int k = 0;
            while (i < res.size())
            {
                if (s == res[i])
                {
                    k++;
                }
                i++;
            }


            if (find(res.begin(),res.end(),s) == res.end())
            {
                res.push_back(s);
            }
            else
            {
                do
                {
                    string str = "(" + to_string(k) +")";
                    temp_str = s + str;
                    k++;
                } while (find(res.begin(),res.end(),temp_str) != res.end());
                
                res.push_back(temp_str);
                                
            }
         
        }
    }
    return res;
}

void print(vector<string> names)
{
    for (string i : names)
    {
        std::cout << i << " ";
    }
    
}
int main()
{
    vector<string> names {"doc", "doc", "image", "doc(1)", "doc"};
    print(fileNaming(names));
    return 0;
}