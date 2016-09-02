//
// Created by serg on 8/31/16.
//
#include "RegistryLua.h"
#include "Registry.h"

//
// Created by serg on 8/31/16.
//

#include <sol.hpp>
#include "Registry.h"

bool luaBindRegistry(sol::state &state, Registry &registry) {

    // make usertype metatable
    state.new_usertype<Registry>( "Registry",
                                sol::constructors<sol::types<> >(),
                                "addBuffer", &Registry::addBuffer,
                                "addInt", &Registry::addInt,
                                "addString", &Registry::addString,
                                "getBuffer", &Registry::getBuffer,
                                "getInt", &Registry::getInt,
                                "getString", &Registry::getString
    );

    state["Registry"] = &registry;
}

