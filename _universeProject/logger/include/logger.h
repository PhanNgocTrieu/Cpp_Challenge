#ifndef LOGGER_H
#define LOGGER_H

#include "log_common.h"

namespace logger{

    class logService {
        public:
            /**
             * @brief Get the Instance object
             * 
             * @param channel channel for logging - stderr or stdout
             * @return logger* logger object
             */
            static logService* getInstance(int channel);

            /**
             * @brief Get the Instance object
             * 
             * @param filePath path to logger file
             * @return logger* logger object
             */
            static logService* getInstance(const std::string& filePath);

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
             * @brief 
             * 
             */
            bool m_initialize;

            /**
             * @brief Construct a new logger Service object
             * 
             */
            logService() {};

            /**
             * @brief Locking of copying object
             * 
             */
            logService(const logService&) = delete;

            /**
             * @brief Locking assigning object
             * 
             * @return logger& 
             */
            logService &operator=(const logService&) = delete;
    };


    class logFile : public logService {
        
        friend logService* logService::getInstance(int channel);
        friend logService* logService::getInstance(const std::string& filePath);

        public:
            void log(int _severityLevelOfMessage, const char* format, ...) override;
        protected:


            /**
             * @brief Construct a new logger File object with the logger file
             * 
             * @param filePath 
             */
            logFile(const std::string& filePath);

            /**
             * @brief Construct a new logger File object
             * 
             */
            logFile();

            /**
             * @brief Locking construct a new logger File object
             * 
             */
            logFile(const logFile&) = delete;

            /**
             * @brief Locking assigning logFile object
             * 
             * @return logFile& 
             */
            logFile& operator=(const logFile&) = delete;

            /**
             * @brief Destroy the logger File object
             * 
             */
            ~logFile();

            /**
             * @brief 
             * 
             * @param _isNeeded 
             */
            void deallocated(bool _isNeeded);
    };


    class logConsole : logService {
        friend logService* logService::getInstance(int channel);
        friend logService* logService::getInstance(const std::string& filePath);

        public:
            void log(int _severityLevelOfMessage, const char* format, ...) override;

        protected:
            /**
             * @brief Construct a new logger File object with the created channel
             * 
             * @param alreadyHandle 
             */
            logConsole(FILE* alreadyHandle);

            /**
             * @brief Construct a new logger File object
             * 
             */
            logConsole();

            /**
             * @brief Locking construct a new logger File object
             * 
             */
            logConsole(const logConsole&) = delete;

            /**
             * @brief Locking assigning logFile object
             * 
             * @return logFile& 
             */
            logConsole& operator=(const logConsole&) = delete;

            /**
             * @brief Destroy the logger File object
             * 
             */
            ~logConsole();

            /**
             * @brief 
             * 
             * @param _isNeeded 
             */
            void deallocated(bool _isNeeded);
    };
};


#endif // LOGGER_H