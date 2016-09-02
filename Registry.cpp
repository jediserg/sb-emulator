//
// Created by serg on 8/31/16.
//

#include "Registry.h"

void Registry::addBuffer(std::string key, Buffer::Ptr buf) {
    _buf_map[key] = buf;
}

void Registry::addString(std::string key, std::string str) {
    _str_map[key] = str;
}

void Registry::addInt(std::string key, int i) {
    _int_map[key] = i;
}

Buffer::Ptr Registry::getBuffer(std::string key) {
    auto it = _buf_map.find(key);

    if(it == _buf_map.end())
        return nullptr;

    return it->second;
}

std::string Registry::getString(std::string key) {
    auto it = _str_map.find(key);

    if(it == _str_map.end())
        return std::string{};

    return it->second;
}

int Registry::getInt(std::string key) {
    auto it = _int_map.find(key);

    if(it == _int_map.end())
        return 0;

    return it->second;
}
