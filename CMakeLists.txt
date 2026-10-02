cmake_minimum_required(VERSION 3.16)
project(Casino LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(casino
    casino.cpp
    Backend/Player/User.cpp
    Backend/Player/Wallet.cpp
    Backend/Game/Machine.cpp
    Backend/Game/Symbol.cpp
)

target_include_directories(casino PRIVATE
    Backend/Player
    Backend/Game
)
find_package(nlohmann_json 3.12.0 REQUIRED)

target_link_libraries(casino PRIVATE nlohmann_json::nlohmann_json)