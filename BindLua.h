//
// Created by serg on 9/2/16.
//

#ifndef SB_EMULATOR_BINDLUA_H
#define SB_EMULATOR_BINDLUA_H

class Registry;
class Server;

namespace sol {
    class state;
};

void luaBindAll(sol::state &state, Registry &reg, Server &server);

#endif //SB_EMULATOR_BINDLUA_H
