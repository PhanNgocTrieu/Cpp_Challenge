#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <filesystem>
#include <chrono>
#include <ctime>
#include "define.h"
#include <vector>
#include <dirent.h>
#include <string>


using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

class message
{
    public:
        
        typedef struct {
            uint32_t server_fd;
            uint32_t new_socket;
            uint32_t read_val;
            struct sockaddr_in addres;
            uint32_t addrlen;
            uint32_t PORT;
        } serverPackage;

        typedef struct {
            uint32_t sockfd;
            uint32_t portno;
            uint32_t readVal;
            uint32_t portNum;
            struct sockaddr_in serv_addr;
        } clientPackage;

        /**
         * @brief enum of detecting type of message
         * 
         */
        enum e_msg_class
        {
            e_msg_class_request,
            e_msg_class_response
        };
        
        /**
         * @brief enum of detecting type of command
         * 
         */
        enum e_msg_type
        {
            e_msg_type_ls = 0,
            e_msg_type_rm,
            e_msg_type_get
        };

        /**
         * @brief Struct of header
         * 
         */
        struct message_header
        {
            int preamble; //=0xAA55AA55
            e_msg_class msg_class;
            enum e_msg_type msg_type;
            long int timestamp; // epoch time in milisecond
            int length_of_data;
        };

        /**
         * @brief Struct of ls - message
         * 
         */
        struct message_ls
        {
            struct message_header header;
            // Data
            std::string file_path;
        };

        /**
         * @brief 
         * 
         */
        struct message_rm
        {
            struct message_header header;
            // Data
            std::string file_path;
        };

        /**
         * @brief 
         * 
         */
        struct message_get
        {
            struct message_header header;
            std::string file_path;
            std::string local_path;
        };

        /**
         * @brief 
         * 
         */
        typedef struct
        {
            struct message_header header;
            std::string file_path;
            std::string local_path;
            std::string message;
        } msgSending;

        typedef struct {
            struct message_header header;
            std::string file_path;
            std::string local_path;
            std::string message;
        } msgReading;

    public:

        /**
         * @brief Construct a new message object
         * 
         */
        message(bool isServer);

        /**
         * @brief Destroy the message object
         * 
         */
        ~message();

        /**
         * @brief 
         * 
         */
        void doInitialize(const int& argc, const char* argv[]);

        /**
         * @brief 
         * 
         */
        void runLoop();

    


    protected:
        void socketConnect(const uint32_t& PF_METHOD = AF_INET, const uint32_t& sockMode = SOCK_STREAM);
        std::string readFiles(std::string dirPath);
        std::string removeDirOrFile(const std::string &path);
        char *substr(char *arr, int begin, int len);
        std::vector<std::string> split(char *_string);
        std::string getString(char *const &_String, int size);


    private:
        msgSending* m_sendMessage;
        msgReading* m_readMessage;
        struct sockaddr_in address;
        socklen_t addrlen;
        int64_t millisec_since_epoch;
        uint32_t PORT;
        uint32_t PORTNo;
        uint32_t server_fd;
        uint32_t readVal;
        uint32_t opt;
        uint32_t new_socket;
        bool _isServer;
        bool _isInitialize;
        

        
};

#endif // MESSAGE_H