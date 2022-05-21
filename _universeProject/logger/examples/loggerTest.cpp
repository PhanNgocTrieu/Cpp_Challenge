#include "logger.h"
#include "log_common.h"

using namespace logger;

int main() {
    int i = 3;
    int k = 5;
    int l = 10;

    do { // logger to stdout
        loggerService* logger = loggerService::getInstance(0);

        logger->setSeverityLevel(DEBUG_LEVEL);

        logger->log(WARN_LEVEL,"Hello world");

        logger->log(DEBUG_LEVEL,"Debug message .....");

        logger->log(INFO_LEVEL,"Infor message .....");

    }while(0);

    do { // logger to stderr
        loggerService* logger = loggerService::getInstance(1);

        logger->setSeverityLevel(DEBUG_LEVEL);

        logger->log(WARN_LEVEL,"Hello world");

        logger->log(DEBUG_LEVEL,"Debug message .....");

        logger->log(ERR_LEVEL,"Error message .....");

    }while(0);

    do { // logger to stderr
        loggerService* logger = loggerService::getInstance("/home/trieupn1/Documents/_work/_git/_universeProject/logger/data/logdata.log");

        logger->setSeverityLevel(DEBUG_LEVEL);

        logger->log(WARN_LEVEL,"Hello world"); //[2021-06-04 22:20:56.567][WARN] Hello world

        logger->log(INFO_LEVEL,"Infor message .....");

        logger->log(INFO_LEVEL,"Infor message %d - %d - %d.....", i,k,l);

        logger->log(DEBUG_LEVEL,"Debug message %d - %d - %d.....", i,k,l);

        logger->log(ERR_LEVEL,"Error message %d - %d - %d.....", i,k,l);
        //[2021-06-04 22:20:56.567][INFO] Debug message 5 - 6 - 7
    }while(0);


    return 0;
}