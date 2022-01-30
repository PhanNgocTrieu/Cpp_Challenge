#include <boost/asio.hpp>
#include <iostream>


// Function object for handle
void print(const boost::system::error_code& )
{
    std::cout << "Hello world\n";
}

int main()
{
    boost::asio::io_context io;

    boost::asio::steady_timer t(io,boost::asio::chrono::seconds(5));

    auto y = [](int _first, int _second){
        return _first < _second ? "Less then" : "Larger";
    };

    //Using asio's asynchronous functionality means having a callback function that will be called when an asynchronous operation completes
    t.async_wait(&print);

    io.run();

    printf("%s \n", y(3,5));

    return 0;
}