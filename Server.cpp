//
// Created by serg on 8/29/16.
//

#include <memory>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

#include "Buffer.h"
#include "Server.h"
#include "ScriptManager.h"


//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//



using boost::asio::ip::udp;

const unsigned MAX_PACKET_LENGTH = 10000;



Server::Server(boost::asio::io_service &io_service, uint16_t port)
: _socket(io_service, udp::endpoint(udp::v4(), port)){
    _buffer = new char[MAX_PACKET_LENGTH];
    _script_manager = nullptr;
    receive();
}

void Server::receive() {
    auto self = shared_from_this();

    _socket.async_receive_from(
            boost::asio::buffer(_buffer, MAX_PACKET_LENGTH), _sender_endpoint,
            [self, this](boost::system::error_code ec, std::size_t bytes_recvd)
            {
                assert(_script_manager);
                if (!ec && bytes_recvd > 1)
                {
                    Buffer::Ptr buf = std::make_shared<Buffer>(*((uint16_t*)_buffer), &_buffer[2], bytes_recvd - 2);
                    _script_manager->loadScript(Buffer::Ptr());
                }
                else
                {
                    receive();
                }
            });
}

bool Server::sendCommand(Buffer::Ptr buffer) {
    auto self = shared_from_this();

    std::vector<char> data(buffer->m_buffer.size() + 2);
    *(reinterpret_cast<uint16_t*>(data.data())) = buffer->getKop();

    std::copy(buffer->m_buffer.begin(), buffer->m_buffer.end(), data.begin());

    _socket.async_send_to(boost::asio::buffer(data), _sender_endpoint,
                          [self, this] (boost::system::error_code ec, std::size_t bytes_transfered)
                          {
                              if (!ec && bytes_transfered > 0)
                              {
                              }
                              else
                              {
                              }
                          });
    return true;
}

Server::~Server() {
    delete[] _buffer;
}

void Server::setScriptManager(ScriptManager *sc)
{
    _script_manager = sc;
}

