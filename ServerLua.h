//
// Created by serg on 9/2/16.
//

#ifndef SB_EMULATOR_SERVERLUA_H
#define SB_EMULATOR_SERVERLUA_H

namespace sol {
  class state;
};

class Server;

bool luaBindServer(sol::state& state, Server& server);

#endif //SB_EMULATOR_SERVERLUA_H
