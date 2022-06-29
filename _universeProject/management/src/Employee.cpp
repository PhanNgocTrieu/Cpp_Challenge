#include "Employee.h"
#include "Developer.h"

namespace staffManagement {

    std::string _Employee::getAccount() const {
        return this->m_infor->_account;
    }

    std::string _Employee::getName() const {
        return this->m_infor->_name;
    }

    std::string _Employee::getJob() const {
        return this->m_infor->_job;
    }

    double _Employee::getSalary() const {
        return this->m_infor->_salary;
    }

    _typeJob _Employee::getTypeJob() const {
        return this->m_infor->_typeOfJob;
    }


    void _Employee::setAccount(const std::string& _account) {
        this->m_infor->_account = _account;
    }

    void _Employee::setName(const std::string& _name) {
        this->m_infor->_name = _name;
    }

    void _Employee::setJob(const std::string& _job) {
        this->m_infor->_account = _job;
    }

    _infoMember* _Employee::getInfor() const {
        return this->m_infor;
    }
};