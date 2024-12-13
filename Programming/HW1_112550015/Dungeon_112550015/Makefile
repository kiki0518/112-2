# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target file
TARGET = dungeon_game

# Source files
SRCS = main.cpp Dungeon.cpp Object.cpp Item.cpp Room.cpp Poison.cpp GameCharacter.cpp Player.cpp Monster.cpp NPC.cpp Swamp.cpp Forest.cpp Desert.cpp 

# Header file directories
INC_DIRS = -I.

# Generated object files
OBJS = $(SRCS:.cpp=.o)

# Linking to generate the executable file
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -o $@ $^

# Generating object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c -o $@ $<

# Cleaning intermediate files and executable
clean:
	rm -f $(OBJS) $(TARGET)
