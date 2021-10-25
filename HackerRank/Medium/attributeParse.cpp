/**
 * @file attributeParse.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
This challenge works with a custom-designed markup language HRML. 
In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. 
Only starting tags can have attributes. 
We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. 
The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

The closing tags follow the format:

</tag-name>

The attributes are referenced as:

tag1~value  
tag1.tag2~name
Given the source code in HRML format consisting of  lines, answer  queries. 
For each query, print the value of the attribute specified. Print "Not Found!" if the attribute does not exist.

Example

HRML listing
<tag1 value = "value">
<tag2 name = "name">
<tag3 another="another" final="final">
</tag3>
</tag2>
</tag1>

Queries
tag1~value
tag1.tag2.tag3~name
tag1.tag2~value
Here, tag2 is nested within tag1, so attributes of tag2 are accessed as tag1.tag2~<attribute>. Results of the queries are:

Query                 Value
tag1~value            "value"
tag1.tag2.tag3~name   "Not Found!"
tag1.tag2.tag3~final  "final"
Input Format

The first line consists of two space separated interger N and Q. N specifies the number of lines in the HRML source program.
Q specifies the number of queries.
The following N lines consist of either an opening tag with zero or more attributes or a closing tag.
There is s aspace after the tag-name, attribute-name, '=' and value. There is no space after the last value. 
If there are no attributes there is no space after tagname.

Q queries follow. Each query consists of sring that references an attribute in the source program.
More formally, each query is of the form tag(i1).tag(i2).tag(i3)...tag(in)~attr-name
where n >= 1 and tag(i1),tag(i2),...tag(in) are valid tags in the input

Constraints

* 1 <= N <= 20
* 1 <= Q <= 20
* Each line in the source program contains, at most,  characters.
* Every reference to the attributes in the  queries contains at most  characters.
* All tag names are unique and the HRML source program is logically correct, i.e. valid nesting.
* A tag can may have no attributes.

Output Format:
Print the value of the attribute for each query. Print "Not Found!" without quotes if the attribute does not exist.

Sample Input
4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

Sample Output:
Name1
Not Found!
HelloWorld
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct TQContainer{
    string tag;
    string attribute;
    string value;
    TQContainer(string _tag, string _attr, string _value) : tag(_tag), attribute(_attr), value(_value)
    {
    }
};

void getQueries(vector<string>& queryContainer, int _numOfQueries)
{
    for (int idex = 0; idex < _numOfQueries; idex++)
    {
        string query_content;
        cin >> query_content;
        queryContainer.push_back(query_content);
    }
}


void getTags(vector<string>& tagContainer, int _numOfTags)
{
    for (int idex = 0; idex < _numOfTags; idex++)
    {
        string tag_content;
        cin >> tag_content;
        tagContainer.push_back(tag_content);
    }
}

void solveAddingValueInTable(vector<string> tagContainer, vector<TQContainer>& valueContainerForQuery)
{
    // get size:
    int _sizeOfTags = tagContainer.size();
    // solve for tags - making string map
    for (int idex = 0; idex < _sizeOfTags; idex++)
    {
        string stringHandle = tagContainer[idex];
        string makingQueries = "";
        if (idex != 0)
        {
            // adding tag before adding more
            makingQueries += valueContainerForQuery.back().tag;
        }
        bool flagGetWord = true;
        bool doingChecking = false;
        bool end_flag = false;
        int _checkingFlag = 0;
        string getWord = "";
        int idex_elem = 0;
        do {
            if (stringHandle[idex_elem] == '/' || stringHandle[idex_elem] == '>')
            {
                end_flag = true;
            }
            else if (stringHandle[idex_elem] == ' ') {
                doingChecking = true;            
            }
            else {
                if (stringHandle[idex_elem] >= 'a' && stringHandle[idex_elem] <= 'z')
                {
                    getWord += stringHandle[idex_elem];
                }
                else {
                    flagGetWord = false;
                    doingChecking = true;
                }
            }        
            
            if (doingChecking)
            {
                // doing for tags
                if (_checkingFlag == 0)
                {
                    // not including value - just tag
                    // interconnected from last string if having
                    makingQueries += getWord;
                    valueContainerForQuery.push_back(TQContainer(makingQueries,"",""));
                    _checkingFlag++;
                    getWord = "";
                }
                else
                {
                    // handling seperate 
                    if (getWord[0] == )
                    // for adding last elem with value of that index
                    int getOfSize = valueContainerForQuery.size();
                    
                    valueContainerForQuery[getOfSize - 1].attributeValue = 
                
                    getWord = "";
                    _checkingFlag++;
                }
            }       
            
            idex_elem++;
        }while (end_flag == false);
        
    }
    
    
    
    
}

void solveComparisonQueries(vector<string> queryContainer, vector<TQContainer>& valueContainerForQuery)
{
    int _sizeOfQueries = queryContainer.size();

    for (int idex = 0; idex < _sizeOfQueries; idex++)
    {
        string getQuery = queryContainer[idex];
        vector<TQContainer>::iterator itr = std::find(valueContainerForQuery.begin(), valueContainerForQuery.end(),getQuery);

        if (itr != valueContainerForQuery.end())
        {
            std::cout << "Not Found!" << std::endl;
        }
        else
        {
            
        }
        
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int _queries;
    int _tags;
    vector<TQContainer> tagQueriesContainer;
    vector<string> tag_container;
    vector<string> query_container;
    map<string, std::pair<string, string>> valueContainerForQuery;
    
    // Enter tags
    cin >> _tags;
    // Enter queries;
    cin >> _queries;
    
    getTags(tag_container, _tags);
    getQueries(query_container, _queries);

    solveAddingValueInTable(tag_container, tagQueriesContainer);
    solveComparisonQueries(query_container, tagQueriesContainer);

    return 0;
}

