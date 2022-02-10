#include <iostream>
#include <limits>

struct Student
{
    std::string name;
    std::string sex;
};

void enter(Student *&_sv,const int& _size)
{
    if (_sv == nullptr)
    {
        _sv = new Student[_size];
    }

    for (int i = 0; i < _size; i++)
    {
        std::cout << "Enter name: ";
        std::cin.getline((char*)((_sv + i)->name).c_str(),20);
        std::cout << "Input Name: " << (_sv + i)->name << std:: endl;
    }

}

int main()
{
    int _size;
    Student * svlist; 
    std::cin >> _size;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    enter(svlist, _size);


    return 0;
}