# Casino

A C++17 slot machine project with a terminal user interface built using [FTXUI](https://github.com/ArthurSonzogni/FTXUI). CMake manages the build, and vcpkg supplies the third-party dependencies.

## Features

- Terminal interface with a horizontal toolbar, login form, and footer
- Username and password lookup using the local `userData.json` file
- Wallet balance storage and saving on logout
- Slot machine engine with randomized symbols, configurable board dimensions, deposits, cashout, and wagers
- Recursive scoring for horizontal, diagonal, and zigzag symbol paths

The interface currently creates the login view alongside the toolbar and footer. Slot and logout views are part of the source tree; the slot view is not yet wired into the active application screen.

## Project Structure

```text
Backend/
  Game/                 Slot machine and symbol logic
  Player/               User and wallet logic
Frontend/
  Components/           Toolbar and footer
  Views/                Login, logout, and slot views
  app.cpp               FTXUI application layout
casino.cpp              Application entry point
CMakeLists.txt          CMake build configuration
vcpkg.json              vcpkg manifest and dependencies
userData.json           Local user data
```

## Requirements

- C++17 compiler
- CMake 3.16 or newer
- Git
- vcpkg

The vcpkg manifest installs FTXUI 7.0.3 or newer, nlohmann-json, and `vcpkg-tool-ninja`. CMake requires FTXUI 7.0.3 and nlohmann_json 3.12.0.

## Build

Set `VCPKG_ROOT` to your vcpkg checkout, then configure and build with the vcpkg toolchain file:

```bash
cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```

Run the application from the project directory so it can find `userData.json`:

```bash
./build/casino
```

## User Data

The application reads user records from `userData.json`. It expects a top-level `Users` array containing objects with `userName`, `password`, and `balance` fields. Logout writes the current wallet balance back to the matching record.

## Future Plans

- Connect the login form to user authentication and account creation
- Wire the toolbar to switch between the slot machine and profile views
- Connect the slot machine view to the game engine and wallet
- Improve wager validation, payouts, and balance handling
- Add tests for user data, board generation, and scoring
- Improve error handling for missing or invalid user data

## About

This project explores C++ classes, game logic, graph traversal, recursion, terminal UI development, and dependency management with CMake and vcpkg.

Codex was used only to format this README; it was not used to write the project code.
