#include "Developer.h"

namespace staffManagement {
    
    _Developer::_Developer() : isInit(false)
    {
        m_infor = nullptr;
    }

    _Developer::_Developer(const std::string& _account,
                        const std::string& _name,
                        const std::string& _job,
                        const _typeJob& _typeOfJob
                        ) : isInit(false)
    {
        this->m_infor = new _infoMember();
        this->m_infor->_account = _account;
        this->m_infor->_name = _name;
        this->m_infor->_job = _job;
        this->m_infor->_typeOfJob = _typeOfJob;
        this->m_infor->_salary = DEF_DEV_SAL;
    }

    _Developer::_Developer(const _Developer& _other) 
    {
        this->m_infor = _other.m_infor;
    }

    _Developer::_Developer(_Developer&& _other){
        *this = std::move(_other);
    }


    _Developer::~_Developer() {
        if (this->m_infor != nullptr) {
            delete this->m_infor;
            this->m_infor = nullptr;
        }

        isInit = false;
    }
    
    void _Developer::doInitialize() {
        if (!isInit)
        {
            srand (time(NULL));
            isInit = true;
        }
    }

    void _Developer::displayInfor() {
        std::cout << *this;
    }


    _Developer& _Developer::operator=(const _Developer& _other) {
        this->m_infor = _other.m_infor;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, _Developer& _dev) {
        os << "Information of Developer - with ID: " << _dev.getInfor()->_account << std::endl;
        os << "Name: " << _dev.getName() << std::endl;
        os << "Specific Job: " << _dev.getJob() << std::endl;
        os << "Mothly Salary: " << _dev.getSalary() << std::endl;
        return os;
    }

    std::istream& operator>>(std::istream& is, _Developer& _dev) {
        std::cout << "Enter Information of Developer - with ID: " << _dev.getInfor()->_account << std::endl;
        std::cout << "Name: ", is >> _dev.getInfor()->_name;
        std::cout << "Specific Job: ", is >> _dev.getInfor()->_job;
        std::cout << "Mothly Salary: ", is >> _dev.getInfor()->_salary;
        return is;
    }
}