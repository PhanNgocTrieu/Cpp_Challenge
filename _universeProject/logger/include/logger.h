#ifndef LOGGER_H
#define LOGGER_H

#include "log_common.h"

namespace logger{

    class loggerService {
        public:
            /**
             * @brief Get the Instance object
             * 
             * @param channel channel for logging - stderr or stdout
             * @return loggerService* logger object
             */
            static loggerService* getInstance(int channel);

            /**
             * @brief Get the Instance object
             * 
             * @param filePath path to logger file
             * @return loggerService* logger object
             */
            static loggerService* getInstance(const std::string& filePath);

            /**
             * @brief Get the Severity Level object
             * 
             * @return int level of severity
             */
            int getSeverityLevel() const;

            /**
             * @brief Set the Severity Level object
             * 
             * @param _severity 
             */
            void setSeverityLevel(const int& _severity);

            /**
             * @brief Abstract for log function
             * 
             * @param _severityLevelOfMessage level severity of Message
             * @param format format of printing
             * @param ... long argurment
             */
            virtual void log(int _severityLevelOfMessage, const char* format, ...) = 0;

        protected:
            /**
             * @brief Severity of object
             * 
             */
            int m_severityLevel;

            /**
             * @brief Construct a new logger Service object
             * 
             */
            loggerService() {};

            /**
             * @brief Locking of copying object
             * 
             */
            loggerService(const loggerService&) = delete;

            /**
             * @brief Locking assigning object
             * 
             * @return loggerService& 
             */
            loggerService &operator=(const loggerService&) = delete;
    };


    class loggerFile : public loggerService {
        
        friend loggerService* loggerService::getInstance(int channel);
        friend loggerService* loggerService::getInstance(const std::string& filePath);

        public:
            void log(int _severityLevelOfMessage, const char* format, ...) override;
        protected:
            /**
             * @brief Ouput of open/close file
             * 
             */
            FILE* outputHandle;

            /**
             * @brief Flag dedicate whether needing to close file or not!
             * 
             */
            bool m_isDeallocated;

            /**
             * @brief Flag dedicate whether logging on console or file
             * 
             */
            bool m_isConsole;

            /**
             * @brief 
             * 
             */
            bool m_initialize;

            /**
             * @brief Construct a new logger File object with the logger file
             * 
             * @param filePath 
             */
            loggerFile(const std::string& filePath);

            /**
             * @brief Construct a new logger File object with the created channel
             * 
             * @param alreadyHandle 
             */
            loggerFile(FILE* alreadyHandle);

            /**
             * @brief Construct a new logger File object
             * 
             */
            loggerFile();

            /**
             * @brief Locking construct a new logger File object
             * 
             */
            loggerFile(const loggerFile&) = delete;

            /**
             * @brief Locking assigning loggerFile object
             * 
             * @return loggerFile& 
             */
            loggerFile& operator=(const loggerFile&) = delete;

            /**
             * @brief Destroy the logger File object
             * 
             */
            ~loggerFile();

            /**
             * @brief 
             * 
             * @param _isNeeded 
             */
            void deallocated(bool _isNeeded);
    };
};


#endif // LOGGER_H