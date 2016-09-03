//
// Created by serg on 8/31/16.
//

#include "BufferLua.h"
#include <sol.hpp>
#include "Buffer.h"
#include <docopt.h>

bool luaBindBuffer(sol::state& state) {

    // make usertype metatable
    state.new_usertype<Buffer>( "Buffer",
          sol::constructors<sol::types<>, sol::types<uint16_t, const char*, size_t>>(),
                                "kop",  sol::property(&Buffer::getKop, &Buffer::setKop),
                                "byte", &Buffer::operator[],
                                "getWord", &Buffer::getWord,
                                "setWord", &Buffer::setWord,
                                "getDword", &Buffer::getDword,
                                "setDword", &Buffer::setDword,
                                "pushByte", &Buffer::pushByte,
                                "pushWord", &Buffer::pushWord,
                                "pushDword", &Buffer::pushDword,
                                "pushString", &Buffer::pushStr

    );

}
