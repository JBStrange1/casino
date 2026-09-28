# C++ Slot Machine

A configurable terminal-based slot machine written in C++. The project started as a small casino script and is growing into a reusable game-engine experiment.

## Current Features

- Configurable board dimensions
- Randomized symbols on each spin
- `Machine` class for game state, deposits, cashout, and spinning
- `Symbol` objects connected into traversable scoring paths
- Recursive scoring for horizontal, diagonal, and zigzag patterns
- Wager and balance handling
- C++ header/source organization
- Makefile-based builds with generated files kept in `build/`

## Project Structure

```text
Game/
  Machine.cpp
  Machine.h
  Symbol.cpp
  Symbol.h
Player/
  Wallet.cpp
  Wallet.h
casino.cpp
makefile
build/          # generated build files, ignored by git
```

The machine creates a board of symbols and connects each symbol to valid neighboring positions. The scoring functions recursively follow those connections while counting consecutive matching symbols.

## Building and Running

Build the project with:

```bash
make
```

Run the executable with:

```bash
./build/casino
```

Remove generated build files with:

```bash
make clean
```

## Future Plans

- Add more configurable winning patterns
- Improve wager, wallet, and payout handling
- Add tests for board generation and scoring
- Build a graphical interface with Node.js and Electron
- Connect the Electron UI to the C++ machine engine, potentially through a child process or native Node.js bridge

The long-term goal is to keep the C++ code responsible for the game engine while using JavaScript, HTML, and CSS for the user interface.

## About

This project is primarily an experiment in C++ classes, pointers, recursion, graph traversal, dynamic board sizes, and game logic.
