#ifndef __Employee_H_
#define __Employee_H_

#include "common.h"

namespace staffManagement
{
    typedef enum
    {
        DEV = 0,
        MAN,
        CEO
    } _typeJob;

    typedef struct
    {
    public:
        std::string _account;
        std::string _name;
        std::string _job;
        _typeJob _typeOfJob;
        double _salary;
    } _infoMember;

    class _Employee
    {

    public:
        virtual ~_Employee() {}
        virtual void displayInfor() = 0;
        virtual void updateSalary(const uint32_t &_factor) = 0;
        virtual void updateInfor(const uint32_t &_idMember) = 0;

    public:
        std::string getAccount() const;
        std::string getName() const;
        std::string getJob() const;
        _typeJob getTypeJob() const;
        double getSalary() const;
        _infoMember *getInfor() const;

        void setAccount(const std::string &);
        void setName(const std::string &);
        void setJob(const std::string &);

        friend std::istream &operator>>(std::istream &_is, _Employee *&_member);
        friend std::ostream &operator<<(std::ostream &_os, const _Employee *&_member);

    protected:
        _infoMember *m_infor;
        uint32_t genPrivKey;
    };

#if 0
    std::istream &operator>>(std::istream &_is, _Employee *&_member)
    {
        if (nullptr == _member)
        {
            perror("The object is null!");
            return _is;
        }

        std::cout << "Enter name: ";
        _is >> _member->m_infor->_name;
        std::cout << "Enter job: ";
        _is >> _member->m_infor->_job;

        return _is;
    }
    std::ostream &operator<<(std::ostream &_os, const _Employee *&_member)
    {
        if (_member == nullptr)
        {
            return _os;
        }
        _os << _os.left << _member->m_infor->_account << "|\t" << _member->m_infor->_name << _member->m_infor->_job << "|\t"
            << "|\t" << _member->m_infor->_salary << "|\n";
        return _os;
    }
#endif

};
#endif