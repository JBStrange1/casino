cmake_minimum_required(VERSION 3.16)
project(Casino LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(casino
    casino.cpp
    Player/User.cpp
    Player/Wallet.cpp
    Game/Machine.cpp
    Game/Symbol.cpp
)

target_include_directories(casino PRIVATE
    Player
    Game
)
find_package(nlohmann_json 3.12.0 REQUIRED)

target_link_libraries(casino PRIVATE nlohmann_json::nlohmann_json)