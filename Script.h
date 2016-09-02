//
// Created by serg on 8/29/16.
//

#ifndef SB_EMULATOR_SCRIPT_H
#define SB_EMULATOR_SCRIPT_H

#include <memory>
#include <sol.hpp>

class Script {
public:
    Script();

    using Ptr = std::shared_ptr<Script>;

    Script& operator=(const Script&) = delete;

    ~Script();

    static Ptr load(const std::string& name, const std::string path);

private:

    bool _load(const std::string &name, const std::string path);
    sol::state _lua;
};


#endif //SB_EMULATOR_SCRIPT_H
