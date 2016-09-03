#include <iostream>
#include "Server.h"
#include <boost/asio.hpp>
#include <docopt.h>
#include "BindLua.h"
#include "Registry.h"
#include "ScriptManager.h"
#include <map>

static const char USAGE[] =
        R"(Usage:
      sb_emulator --port=<port> --device=<device>
      sb_emulator (-h | --help)
      sb_emulator --version

    Options:
      -h --help     Show this screen.
      --version     Show version.
      --port=<port>  Set  port
      --device=<device>  Set  device to emulate
      --path=<path> Specify scripts root dir [default: ./]
)";

int main(int argc, char** argv) {
    std::map<std::string, docopt::value> args = docopt::docopt(USAGE, {argv + 1, argv + argc}, true, "SB emulator 0.1");

    if(args.count("--port") == 0)
    {
        std::cout << "Port is missing";
        exit(1);
    }

    if(args.count("--device") == 0)
    {
        std::cout << "Device is missing";
        exit(1);
    }

    long port = args.at("--port").asLong();
    std::string device = args.at("--device").asString();

    try
    {
        Registry reg;

        reg.addString("device", device);
        reg.addString("path", args.at("--path").asString());

        boost::asio::io_service io_service;
        Server server(io_service, port);

        ScriptManager script_manager(reg, server);

        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}