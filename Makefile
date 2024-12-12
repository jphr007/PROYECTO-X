CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SOURCES = main.cpp Game.cpp SlotMachine.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = slot_machine

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean