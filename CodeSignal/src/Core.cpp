#include "Core.h"

namespace codeSignalProblems
{
    /************************************
     * @brief Prolems of IntroGates     *
     *                                  *
     ************************************/
    int Core::IntroGates::addTwoDigits(int n) 
    {
        int temp=0;
        int sum=0;
        temp=n%10;
        n=n/10;
        sum=temp+n;

        return sum;
    }


    int Core::IntroGates::candies(int n, int m) 
    {
        return n*(m/n);
    }

    int Core::IntroGates::circleOfNumbers(int n, int firstNumber) {
        int haf = n / 2;
        if (firstNumber < haf)
            return firstNumber + haf;
        return firstNumber - haf;
    }

    int Core::IntroGates::largestNumber(int n) 
    {
        int output = 9;
        int i = 2;
        if (n == 1)
        {
            return output;
        }
        while (i <= n)
        {
            output = output * 10 + 9;
            i++;
        }

        return output;
    }

    int Core::IntroGates::lateRide(int n) 
    {
        int hours = n/60;
        int minutes = n % 60; 
        
        int sum = 0;
        supportedFunctions::seperate(sum,hours);
        supportedFunctions::seperate(sum,minutes);
        return sum;
    }


    int Core::IntroGates::maxMultiple(int divisor, int bound) 
    {
        int i = 2;
        int mul = divisor;
        while (mul < bound)
        {
            mul = divisor*i;
            i++;
        }
        if (mul == bound)
            return mul;
        return mul - divisor;
    }

    int Core::IntroGates::phoneCall(int min1, int min2_10, int min11, int s) 
    {
        // first min
        int res = 0;
        if (s < min1)
        {
            return res;
        }
        s = s - min1;
        res++;

        // second to tenth min
        if (s < min2_10)
        {
            return res;
        }
        int i = 2;
        while (i <= 10 && s > min2_10)
        {
            s = s - min2_10;
            res++;
            i++;
            if (s < min2_10)
                return res;
        }

        //std::cout << res;
        // after 11-th min
        if (s < min11)
        {
            return res;
        }
        int temp = s / min11;
        res += temp;

        return res;
    }

    string Core::IntroGates::questionCorrectionBot(string question) 
    {   
        int first_pos = 0;
        // remove all of the white space:
        int i = 0;
        // * at Start!
        while (question[i] == ' ')
        {
            supportedFunctions::__deleteLetter(question,i);
        }
        
        // * at End
        int last_pos = question.length() - 1;
        while (question[last_pos] == ' ')
        {
            supportedFunctions::__deleteLetter(question,last_pos);
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
                        supportedFunctions::__addingLetter(question,aft_i);
                    }
                }
                while (question[pre_i] == ' ')
                {
                    supportedFunctions::__deleteLetter(question,pre_i);
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
                    supportedFunctions::__deleteLetter(question,aft_i);
                }
            }
            i++;
        }
        
        question[0] = toupper(question[0]);
        return question;
    }

    int Core::IntroGates::seatsInTheater(int nCols, int nRows, int col, int row) 
    {
        int behind_rows = nRows - row;
        int left_cols = nCols - col + 1;

        return behind_rows*left_cols;
    }

    /*************************************************
     * @brief Prolems of The Cornor Of 0s and 1s     *
     *                                               *
     *************************************************/
    int Core::CornerOf0sAnd1s::arrayPacking(vector<int> a) {
        int res = a.back();
        a.pop_back();
        while (!a.empty())
        {
            res = res << 8;
            res = res | a.back();
            cout << res << "\n";
            a.pop_back();
        }
        return res;
    }

    int Core::CornerOf0sAnd1s::differentRightmostBit(int n, int m) 
    {
        return pow(2,log2((m^n) & -(m^n)));
    }

    int Core::CornerOf0sAnd1s::equalPairOfBits(int n, int m) {
        return ~(n ^ m) & ((n ^ m) + 1); // ~(n ^ m) & -(~(n ^ m));
    }

    int Core::CornerOf0sAnd1s::killKthBit(int n, int k) 
    {
        return n & ~(1 << (k - 1));
    }

    int Core::CornerOf0sAnd1s::mirrorBits(int a) 
    {
        int res = 0;
        stack<int> s;
        supportedFunctions::sumOfnInStack(s,a);
        int i = 0;
        while (!s.empty())
        {
            int temp = s.top();
            res += temp*pow(2,i);
            i++;
            s.pop();
        }
        
        return res;
    }


    int Core::CornerOf0sAnd1s::rangeBitCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; i++) {
            res += supportedFunctions::sumOfn(i);
        }
        return res;
    }

    /*
        You have to get rid of the rightmost 0
        To fill in the rightmost 0 with 1 using x | (x + 1)
            10111100  (x)
        |   
            10111101  (x + 1)
            --------
            10111101
        Isolate the new rightmost 0
        To isolate it use ~x & (x + 1)
        // now x is the value after step 1

            10111101  (x)
            --------
            01000010  (~x)
        &   
            10111110  (x + 1)
            --------
            00000010
        in short 
        return ~(n|(n+1)) & ((n|(n+1))+1) ;
    */
    int Core::CornerOf0sAnd1s::secondRightmostZeroBit(int n) 
    {
        return ~(n|(n+1)) & ((n|(n+1))+1);
    }

    /*
    Solution:
        ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1)

        Explanation

        Let’s take n = 13, for example.
        1310 = 11012

        (11012 & 10102) >> 1 extracts the higher bits and shifts to the lower bit position.

        11012 & 10102 = 10002
        10002 >> 1 = 01002
        (11012 & 01012) << 1 extracts the lower bits and shifts to the higher bit position.

        11012 & 01012 = 01012
        01012 << 1 = 10102
        So, we combine the two, and we get our swapped bits.
        01002 | 10102 = 11102

    */
    int Core::CornerOf0sAnd1s::swapAdjacentBits(int n) 
    {
        return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    }




    /*******************************************
     * @brief Prolems of Eruption Of Light     *
     *                                         *
     *******************************************/
    bool Core::Eruption_of_Light::isBeautifulString(std::string inputString) 
    {
        char c = 97;
        std::vector<int> count_char;
        while (c <= 122)
        {
            int count = std::count(inputString.begin(), inputString.end(), c);
            count_char.push_back(count);
            c++;
        }
        
        int _sizeOfChar = count_char.size() - 1;
        for (int i = 0; i < _sizeOfChar ; i++)
        {
            int j = i + 1;
            if (count_char[i] < count_char[j])
            {
                return false;
            }
        }

        return true;
    }


    std::string Core::Eruption_of_Light::buildPalindrome(std::string st) 
    {
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
            if (supportedFunctions::Palindrome(st) == true)
            {
                res = st;
            }
            len_af--;
        }
        std::cout << "res: " << res << "\n";
        return res;
    }


    int Core::Eruption_of_Light::electionsWinners(std::vector<int> votes, int k) 
    {

        int size = votes.size();
        int winners = 1;
        int max = *max_element(votes.begin(), votes.end());	

        //---------------finding the position of max -------------
        auto it = std::find(votes.begin(),
            votes.end(), max);
        // If element was found 
        int index = std::distance(votes.begin(),it);
        std::cout << index << std::endl;


        //---------------- Finding Winners --------------------
        if (k == 0)
        {
            int count = 0;
            for (int i = 0; i < size; i++)
            {
                // if no candidates more and we have 2 or more the same votes -> no one would be winner
                // return 0;
                if (votes[i] == max)
                {
                    count++;
                }
                if (count == 2)
                {
                    return 0;
                }
            }

            // if no one equal to element of max -> just himself be winners
            return 1;
        }


        // -------------- k != 0 ------------------- 
        for (int i = 0; i < size; i++)
        {
            if (i == index)
            {
                continue;
            }
            else
            {
                int temp = votes[i] + k;
                if (temp > max)
                {
                    winners++;
                }
            }
        }
        return winners;
    }

    std::string Core::Eruption_of_Light::findEmailDomain(std::string address) 
    {    
        // Frist way:
        /*
        int Pos = address.find_last_of("@") + 1;
        int Len = address.length() - Pos;
        char buffer[20];
        std::size_t length = address.copy(buffer, Len, Pos);
        buffer[length] = '\0';
        std::cout << "buffer contains: " << buffer << '\n';
        return buffer;
        */
        
        // the second way: more power
        int Pos = address.find_last_of("@") + 1;
        // int Len = address.length() - Pos;
        int Len = address.length() - Pos;
        std::string res = "";
        
        for (int i = Pos; i < Len; i++)
        {
            res += address[i];
        }
        std::cout << res;

        return res;
    }


    bool Core::Eruption_of_Light::isMAC48Address(std::string inputString) 
    {
        int len = inputString.length();
        int count_hyphens = 0;
        int count_letter = 0;
        for (int i = 0; i < len; i++)
        {
            int c = inputString[i];
            if (c == 45)
            {
                count_hyphens++;
                count_letter++;
                if (count_hyphens > 5)
                {
                    return false;
                }
            }
            else
            {
                if ((c < 48 || c > 57) && (c < 65 || c > 70))
                {
                    return false;
                }
                count_letter++;
            }
        }
        std::cout << count_hyphens << "\n";
        std::cout << count_letter << "\n";
        if (count_hyphens < 5)
        {
            return false;
        }
        if ((count_letter < 17) || (count_letter > 17))
        {
            return false;
        }

        return true;
    }



        
    /*************************************************
     * @brief Prolems of The Spring Of Integration   *
     *                                               *
     *************************************************/
    int Core::SpringOfIntegration::runnersMeeting(vector<int> startPosition, vector<int> speed) 
    {
        
        return 0;
    }
};