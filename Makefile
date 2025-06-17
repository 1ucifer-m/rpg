# SFML path (update if needed)
SFML_PATH = /opt/homebrew/Cellar/sfml@2/2.6.2_1

# Compiler and flags
CXX = g++
CXXFLAGS = -I$(SFML_PATH)/include
LDFLAGS = -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

# Default target
run:
	mkdir -p bin
	$(CXX) ./src/$(FILE).cpp $(CXXFLAGS) $(LDFLAGS) -o bin/$(FILE)
	./bin/$(FILE)

# Clean build
clean:
	rm -rf bin
