// When a user asks a question on Quora, 
// the system automatically tries to improve the question's formatting before showing it to more users. 
// Given a question as an input string, perform formatting corrections according to the following rules:

// Strip excessive whitespaces:
//      Remove whitespaces at the start and end, as well as multiple spaces in a row
// Fix spacing around punctuation:
//      Each comma should have a trailing space, but no space preceding it
// Questions should start with a capital letter
// Questions should end with a single question mark (not 0 or more than one).
// Example

// For question = " this isn't a relevant question , is it??? ", the output should be
// questionCorrectionBot(question) = "This isn't a relevant question, is it?";
// For question = "Is this answer correct?", the output should be
// questionCorrectionBot(question) = "Is this answer correct?".

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

void __deleteLetter(string &question, int pos)
{
    int last_element = question.length() - 1;
    for (int i = pos; i <= last_element; i++)
    {
        int j = i + 1;
        question[i] = question[j];
    }
    question.pop_back();
    //return question;
}


void __addingLetter(string &question, int pos)
{
    int max = question.length() - 1;
    question.push_back(question[max]);
    for (int i = max; i >= pos; --i)
    {
        int j = i - 1;
        if (i == pos)
        {
            question[i] = ' ';
        }
        else
        {
            question[i] = question[j];
        }
    }
}

string questionCorrectionBot(string question) {
   
    int first_pos = 0;
    // remove all of the white space:
    int i = 0;
    // * at Start!
    while (question[i] == ' ')
    {
        __deleteLetter(question,i);
    }
    
    // * at End
    int last_pos = question.length() - 1;
    while (question[last_pos] == ' ')
    {
        __deleteLetter(question,last_pos);
        last_pos--;
    }

    i = 0;
    while (i < question.length())
    {
        if (question[i] == ',')
        {
            int pre_i = i - 1;
            int aft_i = i + 1;
            if (aft_i > question.length() - 1)
            {
                question.push_back(' ');
            }
            else
            {
                while (question[aft_i] != ' ')
                {
                    __addingLetter(question,aft_i);
                }
            }
            while (question[pre_i] == ' ')
            {
                __deleteLetter(question,pre_i);
                i--;
                pre_i--;
            }
        }

        if (i == question.length() - 1)
        {
            if (question[i] != '?')
            {
                question += '?';
            }
            else
            {
                int pre_i = i - 1;
                while (question[pre_i] == '?')
                {
                    question.pop_back();
                    i--;
                    pre_i--;
                }
            } 
        }
        i++;
    }
    
    i = 1;
    while (i < question.length())
    {
        if (question[i] == ' ')
        {
            int aft_i = i + 1;
            while (question[aft_i] == ' ')
            {
                __deleteLetter(question,aft_i);
            }
        }
        i++;
    }
    
    question[0] = toupper(question[0]);
    return question;
}


int main()
{
    cout << questionCorrectionBot("      this  isn't   a     relevant question , is it???          ") << "\n";
    cout << questionCorrectionBot("  Is,it    correct    ,    question") << "\n";
    cout << questionCorrectionBot("where is F.A.Q.?") << endl;
    cout << questionCorrectionBot("a,b,c,d,e ") << endl;
    cout << questionCorrectionBot("im,tti") << endl;
    cout << questionCorrectionBot("z") << endl;
    cout << questionCorrectionBot("questionword ,anotherquestionword,") << endl;
    return 0;
}