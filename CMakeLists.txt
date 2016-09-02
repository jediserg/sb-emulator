cmake_minimum_required(VERSION 3.6)
project(sb_emulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(../../dev/lua/include)
include_directories(../../dev/docopt)

link_directories(../../dev/lua/)
link_directories(../../dev/docopt/)

set(SOURCE_FILES main.cpp Script.cpp Script.h Server.cpp Server.h Buffer.cpp Buffer.h BufferLua.h BufferLua.cpp Registry.cpp Registry.h RegistryLua.h RegistryLua.cpp ServerLua.h ServerLua.cpp BindLua.h BindLua.cpp)
add_executable(sb_emulator ${SOURCE_FILES})
target_link_libraries(sb_emulator lua53 dl boost_system)