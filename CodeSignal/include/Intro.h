#include "supportedFunction.h"

namespace codeSignalProblems
{
    class Intro {
        public:        
            
            /**
             * @brief Construct a new Intro object
             * 
             */
            Intro() {}
            
            /**
             * @brief Destroy the Intro object
             * 
             */
            ~Intro() {}

            struct Dark_Wilderness {
                /**
                 * @brief 
                 * Given the positions of a white bishopand a black pawn on the standard chess board, 
                 * determine whether the bishop can capture the pawn in one move.
                 * The bishop has no restrictions in distance for each move, 
                 * but is limited to diagonal movement.Check out the example below to see how it can move :
                 * 
                 * @param bishop 
                 * @param pawn 
                 * @return true 
                 * @return false 
                 */
                bool bishopAndPawn(std::string bishop, std::string pawn) {
                
                    int Pos_Bishop = (int)(bishop[0] + (int)bishop[1]);
                    int Pos_Pawn = (int)(pawn[0] + pawn[1]);
                    // in the main Diagonal
                    if (Pos_Bishop == Pos_Pawn)
                    {
                        return true;
                    }
                    // in the sub-Diagonal

                    Pos_Bishop = (int)(bishop[0] - bishop[1]);
                    Pos_Pawn = (int)(pawn[0] - pawn[1]);
                    if (Pos_Bishop == Pos_Pawn)
                        return true;
                    return false;
                }

                /**
                 * @brief 
                 * Caring for a plant can be hard work, but since you tend to it regularly, you have a plant that grows consistently.
                 * Each day, its height increases by a fixed amount represented by the integer upSpeed.But due to lack of sunlight, 
                 * the plant decreases in height every night, by an amount represented by downSpeed.
                 * 
                 * Since you grew the plant from a seed, it started at height 0 initially.
                 * Given an integer desiredHeight, your task is to find how many days it'll take for the plant to reach this height.
                 * 
                 * Example: 
                 * For upSpeed = 100, downSpeed = 10, and desiredHeight = 910, the output should be
                 * growingPlant(upSpeed, downSpeed, desiredHeight) = 10.
                 * 
                 * #		Day	Night
                 * 1		100	90
                 * 2		190	180
                 * 3		280	270
                 * 4		370	360
                 * 5		460	450
                 * 6		550	540
                 * 7		640	630
                 * 8		730	720
                 * 9		820	810
                 * 10	    910	900
                 * The plant first reaches a height of 910 on day 10.
                 * 
                 * @param upSpeed 
                 * @param downSpeed 
                 * @param desiredHeight 
                 * @return int 
                 */
                int growingPlant(int upSpeed, int downSpeed, int desiredHeight) {
                    int day = 0;
                    int _Day_value = 0;
                    int _Night_value = 0;
                    
                    do
                    {
                        day++;
                        _Day_value = upSpeed + _Night_value;
                        _Night_value = _Day_value - downSpeed;
                        std::cout << "Day: " << day << " -> _Day_value: " << _Day_value << " -> _Night_value: " << _Night_value << std::endl;
                    } while (_Day_value < desiredHeight);

                    return day;
                }

                /**
                 * @brief 
                 * Let's define digit degree of some positive integer as the number of times 
                 * we need to replace this number with the sum of its digits until we get to a one digit number.
                 * 
                 * Given an integer, find its digit degree.
                 * 
                 * For n = 5, the output should be
                 * digitDegree(n) = 0;
                 * For n = 100, the output should be
                 * digitDegree(n) = 1.
                 * 1 + 0 + 0 = 1.
                 * For n = 91, the output should be
                 * digitDegree(n) = 2.
                 * 9 + 1 = 10 -> 1 + 0 = 1.
                 * 
                 * 
                 * @param n 
                 * @return int 
                 */
                int digitDegree(int n) {
                    int count = 0;
                    int sum = n;
                    if (n < 10)
                    {
                        return 0;
                    }
                    while (sum >= 10)
                    {
                        int temp_sum = 0;
                        int div = sum;
                        while (div > 0)
                        {
                            int temp = div % 10;
                            temp_sum = temp_sum + temp;
                            div = div / 10;
                        }

                        count++;
                        sum = temp_sum;

                    }

                    return count;
                }

                /**
                 * @brief 
                 * You found two items in a treasure chest!The first item weighs weight1and is worth value1, 
                 * and the second item weighs weight2and is worth value2.What is the total maximum value of the items you can take with you, 
                 * assuming that your max weight capacity is maxWand you can't come back for the items later?
                 * 
                 * 
                 * Note that there are only two items and you can't bring more than one item of each type, 
                 * i.e. you can't take two first items or two second items.
                 * ----------------------------------------------------------------
                 * Example:
                 * For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4, and maxW = 8, the output should be
                 * knapsackLight(value1, weight1, value2, weight2, maxW) = 10.
                 * 
                 * You can only carry the first item.
                 * ----------------------------------------------------------------
                 * For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4, and maxW = 9, the output should be
                 * knapsackLight(value1, weight1, value2, weight2, maxW) = 16.
                 * 
                 * You're strong enough to take both of the items with you.
                 * ----------------------------------------------------------------
                 * For value1 = 5, weight1 = 3, value2 = 7, weight2 = 4, and maxW = 6, the output should be
                 * knapsackLight(value1, weight1, value2, weight2, maxW) = 7.
                 * 
                 * You can't take both items, but you can take any of them.
                 * 
                 * @param value1 
                 * @param weight1 
                 * @param value2 
                 * @param weight2 
                 * @param maxW 
                 * @return int 
                 */
                int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) { 	
                    if (maxW < weight1 && maxW < weight2)
                        return 0;

                    if (maxW < (weight1 + weight2))
                    {
                        if (maxW >= weight1 && maxW < weight2)
                        {
                            return value1;
                        }
                        else
                        {
                            if (maxW >= weight2 && maxW < weight1)
                            {
                                return value2;
                            }
                            else
                            {
                                return value1 > value2 ? value1 : value2;
                            }
                        }
                    }

                    if (maxW >= (weight1 + weight2))
                        return value1 + value2;
                }

                
                /**
                 * @brief 
                 * Given a string, output its longest prefix which contains only digits.
                 *
                 * Example:
                 * For inputString = "123aa1", the output should be
                 * longestDigitsPrefix(inputString) = "123"
                 * 
                 * @param inputString 
                 * @return std::string 
                 */
                std::string longestDigitsPrefix(std::string inputString) {
                    std::string res;
                    if (inputString[0] < 48 && inputString[0] > 57)
                    {
                        return res;
                    }

                    int i = 0;
                    while (inputString[i] >= 48 && inputString[i] <= 57)
                    {
                        res.push_back(inputString[i]);
                        i++;
                    }

                    return res;
                }
            };
            

            struct Diving_Deep {

            };

        private:
            int m_problemsID;
    };
};