//
// Created by serg on 9/3/16.
//

#include "ScriptManager.h"
#include "BindLua.h"
#include <sol.hpp>
#include <sstream>
#include "Registry.h"
#include "Server.h"

ScriptManager::ScriptManager(Registry &registry, Server &server)
    : _registry(registry), _server(server)
{

}

bool ScriptManager::loadScript(Buffer::Ptr buffer)
{
    sol::state state;

    std::stringstream full_name;
    full_name << _registry.getString("path") << "/" << _registry.getString("device") << "/" << buffer->getKop() << ".lua";

    state.open_libraries(sol::lib::base, sol::lib::package);

    luaBindAll(state, _registry, _server);
    state["buffer"] = buffer;

    return state.script_file(full_name.str()) ? true : false;

}
