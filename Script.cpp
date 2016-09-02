//
// Created by serg on 8/29/16.
//

#include <iostream>
#include <sstream>
#include "Script.h"

Script::Ptr Script::load(const std::string &name, const std::string path) {
    Script::Ptr script = std::make_shared<Script>();

    if(script->load(name, path))
        return script;
    else
        return nullptr;
}

Script::~Script() {

}

bool Script::_load(const std::string &name, const std::string path) {
    std::stringstream full_name;
    full_name << path << "/" << name;

    _lua.open_libraries(sol::lib::base, sol::lib::package);
    if(_lua.script_file(full_name.str()))
        return true;
    else
        return false;

    return true;
}

Script::Script()
{

}
