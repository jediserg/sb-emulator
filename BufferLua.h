//
// Created by serg on 8/31/16.
//

#ifndef SB_EMULATOR_BUFFERLUA_H
#define SB_EMULATOR_BUFFERLUA_H

namespace sol {
  class state;
};

bool luaBindBuffer(sol::state& state);

#endif //SB_EMULATOR_BUFFERLUA_H
