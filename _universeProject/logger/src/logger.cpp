#include "logger.h"

namespace logger
{
    logService *logService::getInstance(int channel)
    {
        if (channel == 0)
        {
            return new logConsole(stdout);
        }
        else
        {
            return new logConsole(stderr);
        }
    }

    logService *logService::getInstance(const std::string &filePath)
    {
        return new logFile(filePath);
    }

    void logService::setSeverityLevel(const int &severityLevel)
    {
        this->m_severityLevel = severityLevel;
    }

    int logService::getSeverityLevel() const
    {
        return this->m_severityLevel;
    }



    /**
     ************************************************************************
     *                       Log File module                                *
     ************************************************************************
     */
    void logFile::log(int serverityLevelOfMessage, const char *format, ...)
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
        }
    }

    logFile::logFile(const std::string &filePath)
    {
        if ((this->outputHandle = fopen(filePath.c_str(), "a")) != nullptr) {
            this->deallocated(true);
            m_initialize = true;
        }
        else
        {
            perror("Path to file is wrong -> Could not open file! ");
            m_initialize = false;
            return;
        }
    }

    logFile::~logFile()
    {
        if (this->m_isDeallocated)
        {
            fclose(outputHandle);
        }
    }

    void logFile::deallocated(bool _isNeeded)
    {
        this->m_isDeallocated = _isNeeded;
    }



    /**
     ************************************************************************
     *                       log Console module                             *
     ************************************************************************
     */
    logConsole::logConsole(FILE *alreadyHandle)
    {
        this->outputHandle = alreadyHandle;
        m_initialize = true;
    }

    void logConsole::log(int serverityLevelOfMessage, const char *format, ...)
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
            fprintf(stdout, "[%s][%s][%s]\n", strTime, severityLevel[serverityLevelOfMessage].c_str(), buffer);
        }
    }

    logConsole::logConsole()
    {
    }

    logConsole::~logConsole()
    {
        if (this->m_isDeallocated)
        {
            fclose(outputHandle);
            this->m_isDeallocated = false;
        }
    }

    void logConsole::deallocated(bool _isNeeded)
    {
        this->m_isDeallocated = _isNeeded;
    }

};
