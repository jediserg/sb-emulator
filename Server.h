//
// Created by serg on 8/29/16.
//

#ifndef SB_EMULATOR_SERVER_H
#define SB_EMULATOR_SERVER_H

#include <boost/asio.hpp>
#include <memory>
#include "Buffer.h"

class Server :public std::enable_shared_from_this<Server> {
public:
    Server(boost::asio::io_service& io_service, uint16_t port);

    virtual ~Server();

    bool sendCommand(Buffer::Ptr buffer);

private:
    boost::asio::ip::udp::socket _socket;
    boost::asio::ip::udp::endpoint _sender_endpoint;

    char* _buffer;

    void receive();
};


#endif //SB_EMULATOR_SERVER_H
