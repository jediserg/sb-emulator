//
// Created by serg on 8/31/16.
//

#ifndef SB_EMULATOR_REGISTRYLUA_H
#define SB_EMULATOR_REGISTRYLUA_H

#include "Registry.h"

namespace sol {
  class state;
};

bool luaBindRegistry(sol::state &state, Registry &registry);

#endif //SB_EMULATOR_REGISTRYLUA_H
