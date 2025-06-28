# SFML path (update if needed)
SFML_PATH = /opt/homebrew/Cellar/sfml@2/2.6.2_1

# Compiler and flags
CXX = g++
CXXFLAGS = -I$(SFML_PATH)/include -std=c++17
LDFLAGS = -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

# Get all .cpp files in ./src
SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard src/*.h)  # Added to track headers

EXECUTABLE := bin/game

# Default target
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Build target
$(EXECUTABLE): $(SOURCES) $(HEADERS)  # Added $(HEADERS) here
	mkdir -p bin
	$(CXX) $(SOURCES) $(CXXFLAGS) $(LDFLAGS) -o $(EXECUTABLE)

# Clean build
clean:
	rm -rf bin
