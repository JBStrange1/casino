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
    Frontend/Components/Footer/Footer.cpp
    Frontend/Components/Toolbar/Toolbar.cpp
    Frontend/Views/Login/Login.cpp
    Frontend/Views/Logout/Logout.cpp
    Frontend/Views/Slot/Slot.cpp
    Frontend/app.cpp
)

target_include_directories(casino PRIVATE
    Backend/Player
    Backend/Game
    Frontend/Views/Logout/
    Frontend/Views/Slot/
    Frontend/Views/Login/
    Frontend/Components/Toolbar/
    Frontend/Components/Footer/
    Frontend/
)
find_package(nlohmann_json 3.12.0 REQUIRED)
find_package(ftxui 7.0.3 REQUIRED)

target_link_libraries(casino PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(casino PRIVATE ftxui::ftxui)