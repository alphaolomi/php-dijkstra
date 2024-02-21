CC=g++
CFLAGS=-fPIC -Wall
LDFLAGS=-shared
TARGET_LIB=libdijkstra.so
SRCS=dijkstra.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
    $(CC) $(LDFLAGS) -o $@ $^

%.o: %.cpp
    $(CC) $(CFLAGS) -c $<

clean:
    rm -f $(OBJS) $(TARGET_LIB)

.PHONY: all clean
