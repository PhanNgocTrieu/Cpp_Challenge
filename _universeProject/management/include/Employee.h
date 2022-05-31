#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "common.h"

namespace staffManagement {
    typedef enum {
        DEV     =   0,
        MAN,
        CEO
    } _typeJob;

    typedef struct {
        public:
            std::string _account;
            std::string _name;
            std::string _job;
            _typeJob _typeOfJob;
            double _salary;
    } _infoMember;

    class Employee {

        public:
            static Employee* addingMember(const std::string& _account,
                                            const std::string& _name,
                                            const std::string& _job,
                                            const _typeJob& _typeOfJob
            );

        public:
            virtual ~Employee() {}
            virtual void displayInfor() = 0;
            virtual void updateSalary(const uint32_t& _factor) = 0;
            virtual void updateInfor(const uint32_t& _idMember) = 0;
            virtual void doInitialize() = 0;

        public:
            std::string getAccount() const;
            std::string getName() const;
            std::string getJob() const;
            _typeJob getTypeJob() const;
            double getSalary() const;
            _infoMember* getInfor() const;

            void setAccount(const std::string&);
            void setName(const std::string&);
            void setJob(const std::string&);


        protected:
            _infoMember* m_infor;
            uint32_t genPrivKey;
            std::unordered_map<uint32_t, _infoMember*> listOfMember;
            std::unordered_map<uint32_t, _infoMember*> listOfDeveloper;
            std::unordered_map<uint32_t, _infoMember*> listOfManager;

    };

};
#endif