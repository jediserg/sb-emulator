//
// Created by serg on 8/31/16.
//

#ifndef SB_EMULATOR_REGISTRY_H
#define SB_EMULATOR_REGISTRY_H

#include <map>
#include <string>
#include "Buffer.h"

class Registry {
public:
    void addBuffer(std::string key, Buffer::Ptr buf);
    void addString(std::string key, std::string str);
    void addInt(std::string key, int i);

    Buffer::Ptr getBuffer(std::string key);
    std::string getString(std::string key);
    int getInt(std::string key);
private:
    std::map<std::string, Buffer::Ptr > _buf_map;
    std::map<std::string, std::string > _str_map;
    std::map<std::string, int > _int_map;
};

#endif //SB_EMULATOR_REGISTRY_H
