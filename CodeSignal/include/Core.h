#ifndef __CORE_H
#define __CORE_H

#include "supportedFunction.h"

using namespace std;

namespace codeSignalProblems
{

    class Core
    {

    public:
        /**
         * @brief Construct a new Core object
         *
         */
        Core();

        /**
         * @brief Destroy the Core object
         *
         */
        ~Core();

        /**
         * @brief Struct for problems belongs to Corner Of 0s and 1s
         *
         */
        struct CornerOf0sAnd1s
        {
        public:
            /**
             * @brief
             * You are given an array of up to four non-negative integers, each less than 256.Your task is to pack these integers into one number M in the following way:
             *
             * The first element of the array occupies the first 8 bits of M;
             * The second element occupies next 8 bits, and so on.
             * Return the obtained integer M.
             *
             * Note: the phrase "first bits of M" refers to the least significant bits of M - the right-most bits of an integer. For further clarification see the following example.
             *
             * Example
             *
             *      For a = [24, 85, 0], the output should be arrayPacking(a) = 21784.
             *
             * An array [24, 85, 0] looks like [00011000, 01010101, 00000000] in binary.
             * After packing these into one number we get 00000000 01010101 00011000 (spaces are placed for convenience), which equals to 21784.
             *
             * @param a
             * @return int
             */
            int arrayPacking(vector<int> a);

            /**
             * @brief
             * Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
             * You're given two integers, n and m. Find position of the rightmost bit in which they differ in their binary representations (it is guaranteed that such a bit exists), counting from right to left.
             *
             * Return the value of 2^position_of_the_found_bit (0-based).
             *
             * Example
             *
             * For n = 11 and m = 13, the output should be
             * differentRightmostBit(n, m) = 2.
             *
             * 1110 = 10112, 1310 = 11012, the rightmost bit in which they differ is the bit at position 1 (0-based) from the right in the binary representations.
             * So the answer is 2^1 = 2.
             *
             * For n = 7 and m = 23, the output should be differentRightmostBit(n, m) = 16.
             *
             * 710 = 1112, 2310 = 101112, i.e.
             *
             * 00111
             * 10111
             * So the answer is 2^4 = 16.
             *
             * @param n
             * @param m
             * @return int
             */
            int differentRightmostBit(int n, int m);

            /**
             * @brief Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
             * You're given two integers, n and m. Find position of the rightmost pair of equal bits in their binary representations (it is guaranteed that such a pair exists), counting from right to left.
             *
             * Return the value of 2position_of_the_found_pair (0-based).
             *
             * Example
             *  For n = 10 and m = 11, the output should be
             *  equalPairOfBits(n, m) = 2.
             *
             * 1010 = 10102, 1110 = 10112, the position of the rightmost pair of equal bits is the bit at position 1 (0-based) from the right in the binary representations
             * So the answer is 2^1 = 2.
             *
             * @param n
             * @param m
             * @return int
             */
            int equalPairOfBits(int n, int m);

            /*

            */

            /**
            * @brief
            * Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
            * In order to stop the Mad Coder evil genius you need to decipher the encrypted message he sent to his minions.
            * The message contains several numbers that, when typed into a supercomputer,
            * will launch a missile into the sky blocking out the sun, and making all the people on Earth grumpy and sad.
            *
            * You figured out that some numbers have a modified single digit in their binary representation
            * More specifically, in the given number n the kth bit from the right was initially set to 0,
            * but its current value might be different. It's now up to you to write a function that will change the kth bit of n back to 0.
            *
            * Example
            *       For n = 37 and k = 3, the output should be
            *       killKthBit(n, k) = 33.
            *
            *       3710 = 1001012 ~> 1000012 = 3310.
            *
            *       For n = 37 and k = 4, the output should be
            *       killKthBit(n, k) = 37.
            *
            * The 4th bit is 0 already (looks like the Mad Coder forgot to encrypt this number), so the answer is still 37.
            *
            *
            *   Algorithm:
            *   - Example: we have n = 30 ==> n_bit = 11110 and k-th = 3
            *   - we have to put the position that we wanna change equal to 1 => 1 << (k-th - 1):
            *   1 = 00001 => 1 << (k-th - 1) = 2  == 00100
            *   - Reverse bit of (k_th - 1) => 00100-> 11011
            *   - Using AND logic to change value of k_th
                11110                     1 & 1 = 1   <==> 0 & 0 = 1
                &                         1 & 0 = 0   <==> 0 & 1 = 0
                11011
                -------
                11010
            *
            *
            *
            *
            * @param n
            * @param k
            * @return int
            */
            int killKthBit(int n, int k);

            /**
             * @brief
             * Reverse the order of the bits in a given integer.
             *
             * Example:
             *
             * For a = 97, the output should be
             * mirrorBits(a) = 67.
             *
             * 97 equals to 1100001 in binary, which is 1000011 after mirroring, and that is 67 in base 10.
             *
             * For a = 8, the output should be
             * mirrorBits(a) = 1.
             *
             * @param a
             * @return int
             */
            int mirrorBits(int a);

            /**
             * @brief
             *
             * @param a
             * @param b
             * @return int
             */
            int rangeBitCount(int a, int b);

            /**
             * @brief
             *
             * Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
             * Presented with the integer n,
             * find the 0-based position of the second rightmost zero bit in its binary representation (it is guaranteed that such a bit exists),
             * counting from right to left.
             *
             * Return the value of 2position_of_the_found_bit.
             *
             * Example
             *
             * For n = 37, the output should be
             * secondRightmostZeroBit(n) = 8.
             *
             * 3710 = 1001012. The second rightmost zero bit is at position 3 (0-based) from the right in the binary representation of n.
             * Thus, the answer is 23 = 8.
             *
             *
             * @param n
             * @return int
             */
            int secondRightmostZeroBit(int n);

            /**
             * @brief
             * Implement the missing code, denoted by ellipses. You may not modify the pre-existing code.
             * You're given an arbitrary 32-bit integer n. Take its binary representation,
             * split bits into it in pairs (bit number 0 and 1, bit number 2 and 3, etc.) and swap bits in each pair.
             * Then return the result as a decimal number.
             *
             *  Example
             *
             * For n = 13, the output should be
             * swapAdjacentBits(n) = 14.
             *
             * 1310 = 11012 ~> {11}{01}2 ~> 11102 = 1410.
             *
             * For n = 74, the output should be
             * swapAdjacentBits(n) = 133.
             *
             * 7410 = 010010102 ~> {01}{00}{10}{10}2 ~> 100001012 = 13310.
             *
             *  Note the preceding zero written in front of the initial number: since both numbers are 32-bit integers,
             * they have 32 bits in their binary representation. The preceding zeros in other cases don't matter,
             * so they are omitted. Here, however, it does make a difference.
             *
             * @param n
             * @return int
             */
            int swapAdjacentBits(int n);
        };

        /**
         * @brief Struct for problems belongs to beautiful String
         *
         */
        struct Eruption_of_Light
        {
            /**
             * @brief
             * A string is said to be beautiful
             * if each letter in the string appears at most as many times as the previous letter in the alphabet within the string;
             *
             * ie: b occurs no more times than a; c occurs no more times than b; etc.
             *
             * Given a string, check whether it is beautiful.
             *
             * Example
             *
             * For inputString = "bbbaacdafe", the output should be isBeautifulString(inputString) = true.
             *
             * This string contains 3 as, 3 bs, 1 c, 1 d, 1 e, and 1 f(and 0 of every other letter),
             * so since there aren't any letters that appear more frequently than the previous letter, this string qualifies as beautiful.
             *
             * For inputString = "aabbb", the output should be isBeautifulString(inputString) = false.
             *
             * Since there are more bs than as, this string is not beautiful.
             *
             * For inputString = "bbc", the output should be isBeautifulString(inputString) = false.
             *
             * Although there are more bs than cs, this string is not beautiful because there are no as, so therefore there are more bs than as.
             *
             * @param inputString
             * @return true
             * @return false
             */
            bool isBeautifulString(std::string inputString);

            /**
             * @brief
             *
             * @param st
             * @return std::string
             */
            std::string buildPalindrome(std::string st);

            /*
            Elections are in progress!
            Given an array of the numbers of votes given to each of the candidates so far,
            and an integer k equal to the number of voters who haven't cast their vote yet,
            find the number of candidates who still have a chance to win the election.

            The winner of the election must secure strictly more votes than any other candidate.
            If two or more candidates receive the same(maximum) number of votes, assume there is no winner at all.

            Example

            For votes = [2, 3, 5, 2] and k = 3, the output should be
            electionsWinners(votes, k) = 2.

            The first candidate got 2 votes.Even if all of the remaining 3 candidates vote for him,
            he will still have only 5 votes, i.e.the same number as the third candidate, so there will be no winner.
            The second candidate can win if all the remaining candidates vote for him(3 + 3 = 6 > 5).
            The third candidate can win even if none of the remaining candidates vote for him.For example,
            if each of the remaining voters cast their votes for each of his opponents,
            he will still be the winner(the votes array will thus be[3, 4, 5, 3]).
            The last candidate can't win no matter what (for the same reason as the first candidate).
            Thus, only 2 candidates can win(the second and the third), which is the answer.
            */
            int electionsWinners(std::vector<int> votes, int k);

            /**
             * @brief
             * An email address such as "John.Smith@example.com" is made up of a local part("John.Smith"),
             * an "@" symbol, then a domain part("example.com").
             * The domain name part of an email address may only consist of letters, digits, hyphensand dots.The local part,
             * however, also allows a lot of different special characters.
             * Here you can look at several examples of correctand incorrect email addresses.
             *
             * Given a valid email address, find its domain part.
             *
             * Example
             *
             * For address = "prettyandsimple@example.com", the output should be
             * findEmailDomain(address) = "example.com";
             * For address = "fully-qualified-domain@codesignal.com", the output should be
             * findEmailDomain(address) = "codesignal.com".
             *
             * @param address
             * @return std::string
             */
            std::string findEmailDomain(std::string address);

            /**
             * @brief
             * A media access control address(MAC address) is a unique identifier assigned to network interfaces
             * for communications on the physical network segment.
             *
             * The standard(IEEE 802) format for printing MAC - 48 addresses in human -
             * friendly form is six groups of two hexadecimal digits(0 to 9 or A to F), separated by hyphens(e.g. 01 - 23 - 45 - 67 - 89 - AB).
             *
             * Your task is to check by given string inputString whether it corresponds to MAC - 48 address or not.
             *
             * Example
             * For inputString = "00-1B-63-84-45-E6", the output should be
             * isMAC48Address(inputString) = true;
             * For inputString = "Z1-1B-63-84-45-E6", the output should be
             * isMAC48Address(inputString) = false;
             * For inputString = "not a MAC-48 address", the output should be
             * isMAC48Address(inputString) = false.
             *
             * @param inputString
             * @return true
             * @return false
             */
            bool isMAC48Address(std::string inputString);
        };

        struct IntroGates
        {
            /**
             * @brief
             * You are given a two-digit integer n. Return the sum of its digits.
             *
             * Example
             *
             * For n = 29, the output should be
             * addTwoDigits(n) = 11.
             *
             * @param n
             * @return int
             */
            int addTwoDigits(int n);

            /**
             * @brief
             * n children have got m pieces of candy.
             *
             * They want to eat as much candy as they can, but each child must eat exactly the same amount of candy as any other child.
             *
             * Determine how many pieces of candy will be eaten by all the children together. Individual pieces of candy cannot be split.
             *
             * Example
             *
             * For n = 3 and m = 10, the output should be
             * candies(n, m) = 9.
             *
             * Each child will eat 3 pieces. So the answer is 9.
             * @param n
             * @param m
             * @return int
             */
            int candies(int n, int m);

            /**
             * @brief
             * Consider integer numbers from 0 to n - 1 written down along the circle in such a way
             * That the distance between any two neighboring numbers is equal (note that 0 and n - 1 are neighboring, too).
             *
             * Given n and firstNumber, find the number which is written in the radially opposite position to firstNumber.
             *
             * Example:
             * For n = 10 and firstNumber = 2, the output should be
             * circleOfNumbers(n, firstNumber) = 7.
             *
             * @param n
             * @param firstNumber
             * @return int
             */
            int circleOfNumbers(int n, int firstNumber);

            /**
             * @brief
             * Given an integer n, return the largest number that contains exactly n digits.
             *
             * Example
             * For n = 2, the output should be
             * largestNumber(n) = 99.
             *
             * @param n
             * @return int
             */
            int largestNumber(int n);

            /**
             * @brief
             * One night you go for a ride on your motorcycle. At 00:00 you start your engine,
             * and the built-in timer automatically begins counting the length of your ride, in minutes. Off you go to explore the neighborhood.
             *
             * When you finally decide to head back, you realize there's a chance the bridges on your route home are up,
             * leaving you stranded! Unfortunately, you don't have your watch on you and don't know what time it is.
             *
             * All you know thanks to the bike's timer is that n minutes have passed since 00:00.
             *
             * Using the bike's timer, calculate the current time.
             * Return an answer as the sum of digits that the digital timer in the format hh:mm would show.
             *
             * Example
             *
             * For n = 240, the output should be
             * lateRide(n) = 4.
             *
             * Since 240 minutes have passed, the current time is 04:00.
             * The digits sum up to 0 + 4 + 0 + 0 = 4, which is the answer.
             *
             * For n = 808, the output should be
             * lateRide(n) = 14.
             *
             * 808 minutes mean that it's 13:28 now, so the answer should be 1 + 3 + 2 + 8 = 14.
             *
             * @param n
             * @return int
             */
            int lateRide(int n);

            /**
             * @brief
             * Given a divisor and a bound, find the largest integer N such that:
             *
             * N is divisible by divisor.
             * N is less than or equal to bound.
             * N is greater than 0.
             *
             * It is guaranteed that such a number exists.
             * Example
             *
             * For divisor = 3 and bound = 10, the output should be
             * maxMultiple(divisor, bound) = 9.
             *
             * The largest integer divisible by 3 and not larger than 10 is 9.
             *
             * @param divisor
             * @param bound
             * @return int
             */
            int maxMultiple(int divisor, int bound);

            /**
             * @brief
             * Some phone usage rate may be described as follows:
             *
             * first minute of a call costs min1 cents,
             * each minute from the 2nd up to 10th (inclusive) costs min2_10 cents
             * each minute after 10th costs min11 cents.
             *
             * You have s cents on your account before the call.
             * What is the duration of the longest call (in minutes rounded down to the nearest integer) you can have?
             *
             * Example
             *
             * For min1 = 3, min2_10 = 1, min11 = 2, and s = 20, the output should be
             * phoneCall(min1, min2_10, min11, s) = 14.
             *
             * Here's why:
             *
             * the first minute costs 3 cents, which leaves you with 20 - 3 = 17 cents;
             * the total cost of minutes 2 through 10 is 1 * 9 = 9, so you can talk 9 more minutes and still have 17 - 9 = 8 cents;
             * each next minute costs 2 cents, which means that you can talk 8 / 2 = 4 more minutes.
             * Thus, the longest call you can make is 1 + 9 + 4 = 14 minutes long.
             *
             * @param min1
             * @param min2_10
             * @param min11
             * @param s
             * @return int
             */
            int phoneCall(int min1, int min2_10, int min11, int s);

            /**
             * @brief
             * When a user asks a question on Quora,
             * the system automatically tries to improve the question's formatting before showing it to more users.
             * Given a question as an input string, perform formatting corrections according to the following rules:
             *
             * Strip excessive whitespaces:
             * Remove whitespaces at the start and end, as well as multiple spaces in a row
             *
             * Fix spacing around punctuation:
             * Each comma should have a trailing space, but no space preceding it
             * Questions should start with a capital letter
             * Questions should end with a single question mark (not 0 or more than one).
             *
             * Example
             * For question = " this isn't a relevant question , is it??? ", the output should be
             * questionCorrectionBot(question) = "This isn't a relevant question, is it?";
             * For question = "Is this answer correct?", the output should be
             * questionCorrectionBot(question) = "Is this answer correct?".
             *
             * @param question the input question
             * @return string the correct input question
             *
             *
             * testcases:
             *      cout << questionCorrectionBot("      this  isn't   a     relevant question , is it???          ") << "\n";
             *      cout << questionCorrectionBot("  Is,it    correct    ,    question") << "\n";
             *      cout << questionCorrectionBot("where is F.A.Q.?") << endl;
             *      cout << questionCorrectionBot("a,b,c,d,e ") << endl;
             *      cout << questionCorrectionBot("im,tti") << endl;
             *      cout << questionCorrectionBot("z") << endl;
             *      cout << questionCorrectionBot("questionword ,anotherquestionword,") << endl;
             */
            string questionCorrectionBot(string question);

            /**
             * @brief
             * Your friend advised you to see a new performance in the most popular theater in the city.
             * He knows a lot about art and his advice is usually good, but not this time:
             * the performance turned out to be awfully dull. It's so bad you want to sneak out,
             * which is quite simple, especially since the exit is located right behind your row to the left.
             * All you need to do is climb over your seat and make your way to the exit.
             *
             * The main problem is your shyness:
             * you're afraid that you'll end up blocking the view (even if only for a couple of seconds) of all the people
             * who sit behind you and in your column or the columns to your left. To gain some courage,
             * you decide to calculate the number of such people and see if you can possibly make it to the exit
             * without disturbing too many people.
             *
             * Given the total number of rows and columns in the theater (nRows and nCols, respectively),
             * and the row and column you're sitting in,
             * return the number of people who sit strictly behind you and in your column or to the left, assuming all seats are occupied.
             *
             * Example
             *      For nCols = 16, nRows = 11, col = 5, and row = 3, the output should be
             *      seatsInTheater(nCols, nRows, col, row) = 96.
             *
             * @param nCols
             * @param nRows
             * @param col
             * @param row
             * @return int
             */
            int seatsInTheater(int nCols, int nRows, int col, int row);
        };

        struct SpringOfIntegration
        {
            /**
             * @brief
             * Some people run along a straight line in the same direction.
             * They start simultaneously at pairwise distinct positions and run with constant speed (which may differ from person to person).
             * If two or more people are at the same point at some moment we call that a meeting.
             * The number of people gathered at the same point is called meeting cardinality.
             *
             * For the given starting positions and speeds of runners find the maximum meeting cardinality assuming that people run infinitely long.
             * If there will be no meetings, return -1 instead.
             *
             * @param startPosition array of startPos of participants
             * @param speed arr of speed mapping with participants by idex
             * @return int
             */
            int runnersMeeting(vector<int> startPosition, vector<int> speed);

            /*
                Given an array of 2k integers (for some integer k),
                perform the following operations until the array contains only one element:

                    On the 1st, 3rd, 5th, etc. iterations (1-based) replace each pair of consecutive elements with their sum;
                    On the 2nd, 4th, 6th, etc. iterations replace each pair of consecutive elements with their product.

                After the algorithm has finished, there will be a single element left in the array. Return that element.

                Example

                For inputArray = [1, 2, 3, 4, 5, 6, 7, 8], the output should be
                arrayConversion(inputArray) = 186.

                We have [1, 2, 3, 4, 5, 6, 7, 8] -> [3, 7, 11, 15] -> [21, 165] -> [186], so the answer is 186.
            */
            int arrayConversion(vector<int> inputArray);

            /*
                Given array of integers, for each position i,
                search among the previous positions for the last (from the left) position that contains a smaller value.
                Store this value at position i in the answer. If no such value can be found, store -1 instead.

                Example

                For items = [3, 5, 2, 4, 5], the output should be
                solution(items) = [-1, 3, -1, 2, 4].
            */
            vector<int> arrayPreviousLess(vector<int> items);

            /*
                Consider a string containing only letters and whitespaces.
                It is allowed to replace some (possibly, none) whitespaces with newline symbols
                to obtain a multiline text.

                Call a multiline text beautiful if and only if each of its lines
                (i.e. substrings delimited by a newline character) contains an equal number of characters
                (only letters and whitespaces should be taken into account when counting the total
                while newline characters shouldn't). Call the length of the line the text width.

                Given a string and some integers l and r (l ≤ r),
                check if it's possible to obtain a beautiful text from the string with a text width that's
                within the range [l, r].

                Example:

                For inputString = "Look at this example of a correct text", l = 5, and r = 15, the output should be
                beautifulText(inputString, l, r) = true.

                We can replace 13th and 26th characters with '\n', and obtain the following multiline text of width 12:

                Look at this example of a correct text
                For inputString = "abc def ghi", l = 4, and r = 10, the output should be
                beautifulText(inputString, l, r) = false.

                There are two ways to obtain a text with lines of equal length from this input,
                one has width = 3 and another has width = 11 (this is a one-liner).
                Both of these values are not within our bounds.
            */
            bool beautifulText(string inputString, int l, int r);

            /*
                Miss X has only two combs in her possession, both of which are old and miss a tooth or two.
                he also has many purses of different length, in which she carries the combs.
                The only way they fit is horizontally and without overlapping. Given teeth' positions on both combs,
                find the minimum length of the purse she needs to take them with her.

                It is guaranteed that there is at least one tooth at each end of the comb.
                It is also guaranteed that the total length of two strings is smaller than 32.
                Note, that the combs can not be rotated/reversed.

                Example

                For comb1 = "*..*" and comb2 = "*.*", the output should be
                combs(comb1, comb2) = 5.

                Although it is possible to place the combs like on the first picture, the best way to do this is either picture 2 or picture 3.



                For comb1 = "*...*" and comb2 = "*.*", the output should be
                combs(comb1,comb2) = 5;

                For comb1 = "*..*..*" and comb2 = "*.*", the output should be
                combs(comb1,comb2) = 5;
            */
            int combs(string comb1, string comb2);

            /*
                You're given a substring s of some cyclic string.
                What's the length of the smallest possible string that can be concatenated to itself many times to obtain this cyclic string?

                Example

                For s = "cabca", the output should be
                cyclicString(s) = 3.

                "cabca" is a substring of a cycle string "abcabcabcabc..." that can be obtained by concatenating "abc" to itself.
                Thus, the answer is 3.
            */
            int cyclicString(string s);

            /*
                Yesterday you found some shoes in the back of your closet. Each shoe is described by two values:

                    type indicates if it's a left or a right shoe;
                    size is the size of the shoe.

                Your task is to check whether it is possible to pair the shoes you found in such a way that
                each pair consists of a right and a left shoe of an equal size.

                Example

                    For

                    shoes = {0, 21},
                            {1, 23},
                            {1, 21},
                            {0, 23}}

                    the output should be
                    pairOfShoes(shoes) = true;

                    For

                    shoes = {{0, 21},
                            {1, 23},
                            {1, 21},
                            {1, 23}}

                    the output should be
                    pairOfShoes(shoes) = false
            */
            bool pairOfShoes(vector<vector<int>> shoes);

            /*
                Define crossover operation over two equal-length strings A and B as follows:

                the result of that operation is a string of the same length as the input strings
                result[i] is either A[i] or B[i], chosen at random
                Given array of strings inputArray and a string result,
                find for how many pairs of strings from inputArray the result of the crossover operation over them may be equal to result.

                Note that (A, B) and (B, A) are the same pair.
                Also note that the pair cannot include the same element of the array twice
                (however, if there are two equal elements in the array, they can form a pair).

                Example

                For inputArray = ["abc", "aaa", "aba", "bab"] and result = "bbb", the output should be
                stringsCrossover(inputArray, result) = 2.
            */
            int stringsCrossover(vector<string> inputArray, string result);
        };
    };
}

#endif