//
// Created by serg on 9/2/16.
//
#include "BindLua.h"
#include "Registry.h"
#include "Server.h"

#include "RegistryLua.h"
#include "ServerLua.h"
#include "BufferLua.h"

#include <sol.hpp>

void luaBindAll(sol::state &state, Registry &reg, Server &server)
{
    luaBindRegistry(state, reg);
    luaBindServer(state, server);
    luaBindBuffer(state);
}

