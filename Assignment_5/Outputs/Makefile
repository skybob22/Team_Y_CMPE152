#==============================C++ Compilter Settings==============================#
CXX := g++
CFLAGS += -Wall -MP
CXXFLAGS += -std=c++11
LDFLAGS += -static-libgcc -static-libstdc++ -pthread


#==============================Get Target==============================#

#==============================Build Rules==============================#
all: release

#Target specific variable for includes, No debug flags
release: $(FILE_NAME).a

#Target specific variable for enabling debugging required for GDB
debug: CXXFLAGS += -g
debug: release

$(FILE_NAME).a: $(FILE_NAME).cpp
	$(strip $(CXX) $(CFLAGS) $(CXXFLAGS) $(EXTRACXXFLAGS) $(INCLUDES) -o $@ $<)
