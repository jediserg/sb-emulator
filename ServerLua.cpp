//
// Created by serg on 9/2/16.
//
#include <sol.hpp>
#include "ServerLua.h"
#include "Server.h"


bool luaBindServer(sol::state& state, Server& server) {

    state.new_usertype<Server>( "Server",

                                  "sendCommand", &Server::sendCommand
    );

    state["Server"] = &server;
}
