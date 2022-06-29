#ifndef __DEVELOPER_H__
#define __DEVELOPER_H__

#include "Employee.h"
#include "Manager.h"

namespace staffManagement {
    
    class _Developer : public _Employee {
        public:

            friend std::ostream& operator<<(std::ostream& os, const _Developer*& _dev) {
                
            }
            
            friend std::istream& operator>>(std::istream& is, _Developer*& _dev) {
                
            }

        public:
            _Developer();
            _Developer(const _Developer& _other);
            ~_Developer();
            _Developer& operator=(const _Developer& _other);
            _Developer(_Developer&& _other);

            void displayInfor() override;
            void updateSalary(const uint32_t& _factor) override;
            void updateInfor(const uint32_t& _idMember) override;

        public:
            _Developer(const std::string& _account,
                            const std::string& _name,
                            const std::string& _job,
                            const _typeJob& _typeOfJob = _typeJob::DEV,
                            const double& _salary = DEF_DEV_SAL
                            );

            bool isInit;
    };


}

#endif // __DEVELOPER_H__