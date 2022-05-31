#ifndef __DEVELOPER_H__
#define __DEVELOPER_H__

#include "Employee.h"
#include "Manager.h"

namespace staffManagement {
    class _Developer : public Employee {
        public:
            friend Employee* Employee::addingMember(const std::string& _account,
                                            const std::string& _name,
                                            const std::string& _job,
                                            const _typeJob& _typeOfJob
                                            );
            friend class Manager;
            friend std::ostream& operator<<(std::ostream& os, _Developer& _dev);
        public:
            _Developer();
            _Developer(const _Developer& _other);
            ~_Developer();
            _Developer& operator=(const _Developer& _other);
            _Developer(_Developer&& _other);

            void displayInfor() override;
            void updateSalary(const uint32_t& _factor) override;
            void updateInfor(const uint32_t& _idMember) override;
            void doInitialize() override;

        private:
            _Developer(const std::string& _account,
                            const std::string& _name,
                            const std::string& _job,
                            const _typeJob& _typeOfJob
                            );
            bool isInit;
    };
}

#endif // __DEVELOPER_H__