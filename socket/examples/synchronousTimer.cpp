#include <boost/asio.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    // All programs that use asio need to have at least one I/O execution contex
    boost::asio::io_context io;

    // timer
    boost::asio::steady_timer t(io,boost::asio::chrono::seconds(5));


    // the call to steady_timer::wait() will not return until the timer has expired, 5 seconds after it was created
    t.wait();

    // After waiting time -> print this below comment
    std::cout << "Hello world\n";
    
    return 0;
}