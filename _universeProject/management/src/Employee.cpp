#include "Employee.h"
#include "Developer.h"

namespace staffManagement {

    Employee* Employee::addingMember(const std::string& _account,
                                            const std::string& _name,
                                            const std::string& _job,
                                            const _typeJob& _typeOfJob
                                            )
                                            {
                                                _Developer* newObj;
                                                if (_typeOfJob == _typeJob::DEV) {
                                                        newObj = new _Developer(_account, _name, _job, _typeOfJob);
                                                    }
                                                else if (_typeOfJob == _typeJob::MAN) {
                                                    
                                                }

                                                return newObj;
                                            }


    std::string Employee::getAccount() const {
        return this->m_infor->_account;
    }

    std::string Employee::getName() const {
        return this->m_infor->_name;
    }

    std::string Employee::getJob() const {
        return this->m_infor->_job;
    }

    double Employee::getSalary() const {
        return this->m_infor->_salary;
    }

    _typeJob Employee::getTypeJob() const {
        return this->m_infor->_typeOfJob;
    }


    void Employee::setAccount(const std::string& _account) {
        this->m_infor->_account = _account;
    }

    void Employee::setName(const std::string& _name) {
        this->m_infor->_name = _name;
    }

    void Employee::setJob(const std::string& _job) {
        this->m_infor->_account = _job;
    }

    _infoMember* Employee::getInfor() const {
        return this->m_infor;
    }
};