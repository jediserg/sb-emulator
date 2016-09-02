#include <iostream>
#include "Server.h"
#include <boost/asio.hpp>
#include <docopt.h>
#include <sol.hpp>
#include "BindLua.h"
#include "Registry.h"
int main() {
    try
    {
        Registry reg;
        sol::state state;

        boost::asio::io_service io_service;
        Server server(io_service, 2345);

        luaBindAll(state, reg, server);

        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}