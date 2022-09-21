#ifndef __SUPPORT_H
#define __SUPPORT_H

#include "Core.h"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

namespace supportedFunctions
{
    struct runner{
        int mPos;
        int mV;
    };

    typedef enum {
        CornerOf0sAnd1s = 0,
        Eruption_of_Light
    } nameOfProblems;

    typedef enum {
        easy = 0,
        medium,
        hard,
        expert
    } problemsLevels;

    void seperate(int &sum, int n)
    {
        while(n > 0)
        {
            sum += n % 10;
            n = n / 10;
        }
    }

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
    
    void sumOfnInStack(stack<int> &s, int n){
        while (n != 0)
        {
            int temp = n % 2;
            s.push(temp);
            n = n / 2;
        }
    }

    int sumOfn(int n){
        int sum = 0;
        while (n != 0)
        {
            int temp = n % 2;
            sum += temp;
            n = n / 2;
        }
        return sum;
    }

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
};

#endif