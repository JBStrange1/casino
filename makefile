SOURCES := $(shell find . -name "*.cpp" -not -path "./build/*")
OBJECTS := $(patsubst ./%.cpp,build/%.o,$(SOURCES))
CXXFLAGS := -Wall -Wextra -std=c++17 -IGame -IPlayer

.DEFAULT_GOAL := build/casino

build/casino: $(OBJECTS)
	g++ $(OBJECTS) -o build/casino

build/%.o: %.cpp
	mkdir -p $(dir $@)
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build
