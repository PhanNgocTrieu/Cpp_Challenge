#ifndef SOCKET_H
#define SOCKET_H

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>


class Socket {
    public:
        const int PORT = 8080;
        Socket();
        Socket(const sockaddr_in _serverAddr, bool _isServer = false);
        void connect();
        void read();
        void send();
        void doRepeat();
    private:
        struct sockaddr_in serv_addr;
        char * buffer;
        int sock;
        int valRead;
        bool isServer;

};

#endif