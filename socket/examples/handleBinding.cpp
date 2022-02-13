#include <boost/asio.hpp>
#include <iostream>
#include <boost/bind/bind.hpp>

void sayingToTheWorld(const boost::system::error_code& /*e*/, boost::asio::steady_timer* _timer, int* count)
{
    if (*count < 5)
    {
        std::cout << *count << std::endl;
        ++(*count);

        _timer->expires_at(_timer->expiry() + boost::asio::chrono::seconds(1));
        _timer->async_wait(boost::bind(sayingToTheWorld,boost::asio::placeholders::error, _timer, count));
    }
}

int main(int argc, char * argv[])
{
    // io context
    boost::asio::io_context io;
    int _count = 0;
    boost::asio::steady_timer _timer(io,boost::asio::chrono::seconds(1));

    _timer.async_wait(boost::bind(sayingToTheWorld, boost::asio::placeholders::error, &_timer, &_count));


    io.run();

    std::cout << "Final count is " << _count << std::endl;
    
    return 0;
}