#include "logger.h"

namespace logger
{
    loggerService *loggerService::getInstance(int channel)
    {
        if (channel == 0)
        {
            return new loggerFile(stdout);
        }
        else
        {
            return new loggerFile(stderr);
        }
    }

    loggerService *loggerService::getInstance(const std::string &filePath)
    {
        return new loggerFile(filePath);
    }

    void loggerFile::log(int serverityLevelOfMessage, const char *format, ...)
    {
        if (!m_initialize) {
            return;
        }

        time_t t = time(nullptr);
        struct tm *_time = localtime(&t);
        char *strTime = new char[256];
        strftime(strTime, 256, "%c", _time);

        char *buffer = new char[256];
        va_list arguments;
        va_start(arguments, format);
        vsprintf(buffer, format, arguments);
        va_end(arguments);

        if (serverityLevelOfMessage > 0 || serverityLevelOfMessage < 3)
        {
            std::string severityLevel[] = {"ERR", "WRN", "INF", "DBG"};
            fprintf(outputHandle, "[%s][%s][%s]\n", strTime, severityLevel[serverityLevelOfMessage].c_str(), buffer);

            if (!m_isConsole) {
                fprintf(stdout, "[%s][%s][%s]\n", strTime, severityLevel[serverityLevelOfMessage].c_str(), buffer);
            }
        }
    }

    void loggerService::setSeverityLevel(const int &severityLevel)
    {
        this->m_severityLevel = severityLevel;
    }

    int loggerService::getSeverityLevel() const
    {
        return this->m_severityLevel;
    }


    /**
     ************************************************************************
     *                       Logger File module                             *
     ************************************************************************
     */
    loggerFile::loggerFile(const std::string &filePath)
    {
        if ((this->outputHandle = fopen(filePath.c_str(), "a")) != nullptr) {
            this->deallocated(true);
            m_isConsole = false;
            m_initialize = true;
        }
        else
        {
            perror("Error! Could not open file! ");
            m_initialize = false;
            return;
        }
    }

    loggerFile::loggerFile(FILE *alreadyHandle)
    {
        this->outputHandle = alreadyHandle;
        m_isConsole = true;
        m_initialize = true;
    }

    loggerFile::~loggerFile()
    {
        if (this->m_isDeallocated)
        {
            fclose(outputHandle);
        }
    }

    void loggerFile::deallocated(bool _isNeeded)
    {
        this->m_isDeallocated = _isNeeded;
    }

};
