#include "shell.h"

message::message(bool isServer) {
    this->millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

message::~message() {}

std::string message::readFiles(std::string dirPath)
{
    if (dirPath[dirPath.length() - 1] != '/')
    {
        char c = '/';
        dirPath.push_back(c);
    }
    std::string res = "";
    DIR *dir;
    struct dirent *ent;
    dir = opendir(dirPath.c_str());
    if (dir)
    {
        while ((ent = readdir(dir)) != nullptr)
        {
            res += ent->d_name;
            res += " ";
        }
        std::cout << std::endl;
    }
    else
    {
        res = "Could not find the path!";
    }

    return res;
}

std::string message::removeDirOrFile(const std::string &path)
{
    int status;
    status = remove(path.c_str());
    if (status == 0)
    {
        return std::string("File deleted successfully\n");
    }
    return std::string("Error deleting!\n");
}

char *message::substr(char *arr, int begin, int len)
{
    char *res = new char[len + 1];
    for (int i = 0; i < len; i++)
        res[i] = *(arr + begin + i);
    res[len] = 0;
    return res;
}

std::vector<std::string> message::split(char *_string)
{
    std::vector<std::string> res;
    std::string s = "";
    char *pStr = _string;
    int limit = strlen(_string);
    while (pStr != nullptr && limit > 0)
    {
        if (*pStr == ' ')
        {
            res.push_back(s);
            s = "";
        }
        else
        {
            s += *pStr;
        }
        pStr++;
        limit--;
    }
    if (s != "")
    {
        res.push_back(s);
    }
    return res;
}

void message::doInitialize(const int &argc, const char *argv[])
{
    if (_isInitialize == true)
    {
        return;
    }

    if (this->_isServer == true)
    {
        if (argc < 2)
        {
            PORT = htons(DEFAULT_PORT);
            return;
        }
        else {
            PORT = atoi(argv[1]);
        }

        addrlen = sizeof(address);

        this->socketConnect();
        this->address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // Forcefully attaching socket to the port 1234
        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }

        if (listen(server_fd, 10) < 0)
        {
            perror("listen failed");
            exit(EXIT_FAILURE);
        }

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
    }
}

void message::socketConnect(const uint32_t &PF_METHOD = AF_INET, const uint32_t &sockMode = SOCK_STREAM)
{

    if (this->_isServer == true)
    {
        // Creating socket file descriptor
        if ((this->server_fd = socket(PF_METHOD, sockMode, 0)) == 0)
        {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        /**
         * @brief This helps in manipulating options for the socket referred by the file descriptor sockfd. Prevents error such as: “address already in use”.
         * 
         */
        if (setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &this->opt, sizeof(this->opt)))
        {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
    }
}

std::string message::getString(char *const &_String, int size)
{
    std::string s = "";
    for (int idex = 0; idex < size; idex++)
    {
        s += _String[idex];
    }
    return s;
}

void message::runLoop()
{
    if (_isInitialize == false)
    {
        return;
    }

    if (_isServer)
    {
        while (1)
        {
            printf("\n\nServer is listening....\n");

            char *data_to_send;
            int size_of_header_not_padding = sizeof(message_header::preamble) + sizeof(message_header::msg_class) +
                                             sizeof(message_header::msg_type) + sizeof(message_header::timestamp) + sizeof(message_header::length_of_data);
            char *buff = (char *)malloc(1024);
            e_msg_type typeOfMessage;

            this->readVal = read(new_socket, buff, 1024);

            if (this->readVal <= 0)
            {
                perror("Error: could not read fom client!\n");
                exit(EXIT_FAILURE);
            }

            memcpy(&typeOfMessage, buff + sizeof(message_header::preamble) + sizeof(message_header::msg_class), sizeof(message_header::msg_type));
            // std::cout << "\nTYPE OF MESSAGE: " << typeOfMessage << std::endl;

            if (typeOfMessage == e_msg_type_ls)
            {
                if (m_readMessage == nullptr) {
                    m_readMessage = new msgReading();
                }

                message_ls recmsg;

                char msgFromClient[100];
                // *********** RECEIVING REQUEST FROM CLIENT ************
                int index = 0;
                memcpy(&m_readMessage->header.preamble, buff + index, sizeof(m_readMessage->header.preamble));
                index += sizeof(m_readMessage->header.preamble);
                memcpy(&m_readMessage->header.msg_class, buff + index, sizeof(m_readMessage->header.msg_class));
                index += sizeof(m_readMessage->header.msg_class);
                memcpy(&m_readMessage->header.msg_type, buff + index, sizeof(m_readMessage->header.msg_type));
                index += sizeof(m_readMessage->header.msg_type); // xem phan address
                memcpy(&m_readMessage->header.timestamp, buff + index, sizeof(m_readMessage->header.timestamp));
                index += sizeof(m_readMessage->header.timestamp);
                memcpy(&m_readMessage->header.length_of_data, buff + index, sizeof(m_readMessage->header.length_of_data));
                index += sizeof(m_readMessage->header.length_of_data);
                memcpy(&msgFromClient, buff + index, m_readMessage->header.length_of_data);
                m_readMessage->message = getString(msgFromClient, m_readMessage->header.length_of_data);

                // **** CONVERT TO STRING ****
                std::string listString = getString(msgFromClient, m_readMessage->header.length_of_data);

                // ************* SENDING RESPONSE MESSAGE TO CLIENT *********
                message_ls msgForClient;

                if (m_sendMessage == nullptr) {
                    m_sendMessage = new msgSending();
                }

                // **** HANDLING WITH LISTING ALL OF FILES ****
                std::string listOfFolder = readFiles(m_readMessage->message);

                // **** SETUP MEMORY FOR SENDING ****
                m_sendMessage->header.preamble = PREAMBLE_LS;
                m_sendMessage->header.msg_class = e_msg_class_response;
                m_sendMessage->header.msg_type = e_msg_type_ls;
                m_sendMessage->header.timestamp = millisec_since_epoch;
                m_sendMessage->header.length_of_data = listOfFolder.length();
                m_sendMessage->message = listOfFolder;

                // **** SETUP MEMORY SPACE FOR SENDING ****

                data_to_send = (char *)malloc(size_of_header_not_padding + m_sendMessage->header.length_of_data);
                int idex = 0;
                memcpy(data_to_send + idex, &m_sendMessage->header.preamble, sizeof(m_sendMessage->header.preamble));
                idex += sizeof(msgForClient.header.preamble);
                memcpy(data_to_send + idex, &m_sendMessage->header.msg_class, sizeof(m_sendMessage->header.msg_class));
                idex += sizeof(msgForClient.header.msg_class);
                memcpy(data_to_send + idex, &m_sendMessage->header.msg_type, sizeof(m_sendMessage->header.msg_type));
                idex += sizeof(msgForClient.header.msg_type);
                memcpy(data_to_send + idex, &m_sendMessage->header.timestamp, sizeof(m_sendMessage->header.timestamp));
                idex += sizeof(msgForClient.header.timestamp);
                memcpy(data_to_send + idex, &m_sendMessage->header.length_of_data, sizeof(m_sendMessage->header.length_of_data));
                idex += sizeof(msgForClient.header.length_of_data);
                memcpy(data_to_send + idex, (char *)m_sendMessage->message.c_str(), m_sendMessage->header.length_of_data);

                // ****** ALL OF BYTES THAT WE HAVE TO SEND ****
                printf("\nTotal data to send: %d bytes", size_of_header_not_padding + m_sendMessage->header.length_of_data);

                // **** SENDING RESPOSE MESSAGE ****
                int statusSend = send(new_socket, data_to_send, size_of_header_not_padding + m_sendMessage->header.length_of_data, 0);
                if (statusSend < 0)
                {
                    perror("Error: Sending failed");
                }
                else
                {
                    // cout << "Already send!" << endl;
                    printf("\nClient send %d bytes\n", statusSend);
                }

                // **** DEALLOCATED MEMORY THAT WAS ALLOCATED ****
                free(data_to_send);
                data_to_send = nullptr;

                if (m_sendMessage) {
                    delete m_sendMessage;
                    m_sendMessage = nullptr;
                }
            }

            // **** Handling with rm type
            if (typeOfMessage == e_msg_type_rm)
            {
                message_rm recmsg;
                
                char msgFromClient[1024];
                // *********** RECEIVING REQUEST FROM CLIENT ************
                int index = 0;
                memcpy(&recmsg.header.preamble, buff + index, sizeof(recmsg.header.preamble));
                index += sizeof(recmsg.header.preamble);
                memcpy(&recmsg.header.msg_class, buff + index, sizeof(recmsg.header.msg_class));
                index += sizeof(recmsg.header.msg_class);
                memcpy(&recmsg.header.msg_type, buff + index, sizeof(recmsg.header.msg_type));
                index += sizeof(recmsg.header.msg_type); // xem phan address
                memcpy(&recmsg.header.timestamp, buff + index, sizeof(recmsg.header.timestamp));
                index += sizeof(recmsg.header.timestamp);
                memcpy(&recmsg.header.length_of_data, buff + index, sizeof(recmsg.header.length_of_data));
                index += sizeof(recmsg.header.length_of_data);
                memcpy(&msgFromClient, buff + index, recmsg.header.length_of_data);
                m_message->message = getString(msgFromClient, recmsg.header.length_of_data);

                // **** CONVERT TO STRING ****
                std::string filePath = getString(msgFromClient, recmsg.header.length_of_data);

                // **** HANDLING REMOVING FILE ****
                std::string message = removeDirOrFile(filePath);

                // **** CHECKING MESSAGE BEFORE SENDING ****
                std::cout << "\nIs it successful? --> " << message << std::endl
                     << std::endl;

                // **** FULLFILLING DATA TO HEADER
                message_rm sendmsg;
                sendmsg.header.preamble = PREAMBLE_RM;
                sendmsg.header.msg_class = e_msg_class_response;
                sendmsg.header.msg_type = e_msg_type_rm;
                sendmsg.header.timestamp = millisec_since_epoch;
                sendmsg.header.length_of_data = message.length();
                sendmsg.announce = message;

                // **** SETUP MEMORY FOR SENDING ****
                data_to_send = (char *)malloc(size_of_header_not_padding + sendmsg.header.length_of_data);
                int idex = 0;
                memcpy(data_to_send + idex, &sendmsg.header.preamble, sizeof(sendmsg.header.preamble));
                idex += sizeof(sendmsg.header.preamble);
                memcpy(data_to_send + idex, &sendmsg.header.msg_class, sizeof(sendmsg.header.msg_class));
                idex += sizeof(sendmsg.header.msg_class);
                memcpy(data_to_send + idex, &sendmsg.header.msg_type, sizeof(sendmsg.header.msg_type));
                idex += sizeof(sendmsg.header.msg_type);
                memcpy(data_to_send + idex, &sendmsg.header.timestamp, sizeof(sendmsg.header.timestamp));
                idex += sizeof(sendmsg.header.timestamp);
                memcpy(data_to_send + idex, &sendmsg.header.length_of_data, sizeof(sendmsg.header.length_of_data));
                idex += sizeof(sendmsg.header.length_of_data);
                memcpy(data_to_send + idex, (char *)sendmsg.announce.c_str(), sendmsg.header.length_of_data);

                // ****** ALL OF BYTES THAT WE HAVE TO SEND ****
                printf("\nTotal data to send: %d bytes", size_of_header_not_padding + sendmsg.header.length_of_data);

                // **** SENDING RESPOSE MESSAGE ****
                int statusSend = send(new_socket, data_to_send, size_of_header_not_padding + sendmsg.header.length_of_data, 0);
                if (statusSend < 0)
                {
                    perror("Error: Sending failed");
                }
                else
                {
                    // cout << "Already send!" << endl;
                    printf("\nClient send %d bytes\n", statusSend);
                }

                // **** DEALLOCATED MEMORY THAT WAS ALLOCATED ****
                free(data_to_send);
                data_to_send = nullptr;
            }

            // // **** HANDLING WITH DOWNLOAD FILE
            if (typeOfMessage == e_msg_type_get)
            {
                message_get recmsg;
                char msgFromClient[100];
                // **** RECEIVING FILENAME FROM CLIENT
                int index = 0;
                memcpy(&recmsg.header.preamble, buff + index, sizeof(recmsg.header.preamble));
                index += sizeof(recmsg.header.preamble);
                memcpy(&recmsg.header.msg_class, buff + index, sizeof(recmsg.header.msg_class));
                index += sizeof(recmsg.header.msg_class);
                memcpy(&recmsg.header.msg_type, buff + index, sizeof(recmsg.header.msg_type));
                index += sizeof(recmsg.header.msg_type); // xem phan address
                memcpy(&recmsg.header.timestamp, buff + index, sizeof(recmsg.header.timestamp));
                index += sizeof(recmsg.header.timestamp);
                memcpy(&recmsg.header.length_of_data, buff + index, sizeof(recmsg.header.length_of_data));
                index += sizeof(recmsg.header.length_of_data);
                memcpy(&msgFromClient, buff + index, recmsg.header.length_of_data);
                recmsg.fileName = getString(msgFromClient, recmsg.header.length_of_data);

                // ****** SENDING RESPONSE TO CLIENT *****
                char *filepath = (char *)malloc(recmsg.header.length_of_data);
                strcpy(filepath, msgFromClient);

                printf("\nFilepath       = %s", filepath);

                FILE *fp = fopen(filepath, "r");
                if (fp != NULL)
                {
                    printf("\nFile exits");
                    fseek(fp, 0, SEEK_END);
                    long fileSize = ftell(fp);
                    printf("\nFilesize          = %ld bytes", fileSize);
                    fseek(fp, 0, SEEK_SET); // reset the pointer t	o the start of the file
                    long totalSend = 0;
                    char *pBuf = (char *)malloc(fileSize);
                    int Read = fread(pBuf, 1, fileSize, fp);
                    printf("\nCopy %d bytes to buffer\n", Read);
                    totalSend = send(new_socket, pBuf, fileSize, 0);

                    printf("\nServer send total %ld bytes\n", totalSend);
                    fflush(fp);
                    fclose(fp);
                }
                else
                {
                    printf("\nFile does not exit!");
                    const char *receive = "File does not exist!";
                    send(new_socket, receive, strlen(receive), 0);
                }
            }
            free(buff);
            buff = nullptr;
        }
    }
}
