// Check if the given string is a correct time representation of the 24-hour clock.

// Example

// For time = "13:58", the output should be
// validTime(time) = true;
// For time = "25:51", the output should be
// validTime(time) = false;
// For time = "02:76", the output should be
// validTime(time) = false.
// For time = "24:00", the output should be
// validTime(time) = false.

#include <algorithm>
#include <iostream>
#include <string>
#include <regex>

bool validTime(std::string time) {
    // -------------- Not Using Algorithm
    // if(time[0] > '2' || time[3] > '6')
    // {
    //     std::cout << "Frist Run!" << std::endl;
    //     return false;
    // }
    // else    
    // {
    //     std::cout << "Second Run!" << std::endl;
    //     if(time[0] == 50)
    //     {
    //         if(time[1] >= 52)  // 24:01 -> false: (24) error
    //         {
    //             std::cout << "inside Second Run! \n";
    //             return false;
    //         }               
    //     }
    //     if(time[3] == 54)
    //     {
    //         if (time[4] > 47)  
    //         {
    //             return false;
    //         }
    //     }
    //     return true; 
    // }

    //------------Using Algorithm-------
    // Too Hard:  return std::regex_match(time, std::regex("(?:[01]\\d|2[0-3]):[0-5]\\d"));



   // ------------Another Way---------
   return stoi(time.substr(0,2)) < 24 && stoi(time.substr(3,2)) < 60;
}



int main()
{
    if(validTime("23:00") == true)
        std::cout << "True!" << std::endl;

    return 0;
}
