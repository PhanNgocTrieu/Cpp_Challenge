#include "Developer.h"

namespace staffManagement {
    
    _Developer::_Developer() : isInit(false)
    {
        m_infor = nullptr;
    }

    _Developer::_Developer(const std::string& _account,
                        const std::string& _name,
                        const std::string& _job,
                        const _typeJob& _typeOfJob,
                        const double& _salary
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

    void _Developer::displayInfor() {
        std::cout << this;
    }


    _Developer& _Developer::operator=(const _Developer& _other) {
        this->m_infor = _other.m_infor;
        return *this;
    }
}