//
// Created by serg on 9/3/16.
//

#ifndef SB_EMULATOR_SCRIPTMANAGER_H
#define SB_EMULATOR_SCRIPTMANAGER_H


#include <string>
#include "Buffer.h"

class Server;
class Registry;

class ScriptManager
{
public:
    ScriptManager(Registry& registry, Server& server);
    bool loadScript(Buffer::Ptr buffer);
private:
    Server& _server;
    Registry& _registry;
};


#endif //SB_EMULATOR_SCRIPTMANAGER_H
