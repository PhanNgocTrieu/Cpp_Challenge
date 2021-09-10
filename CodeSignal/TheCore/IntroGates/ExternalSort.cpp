#include <iostream>
#include <algorithm>



int main(int argc, char * __argv[])
{
    std::cout << "Have " << argc << " argurments:" << std::endl;

    for (int i = 0; i < argc; ++i)
    {
        /* code */
        std::cout << __argv[i] << std::endl;
    }
    

    return 0;
}