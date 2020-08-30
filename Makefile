CC     = g++
CFLAGS = -Wall -Werror -g -I.
SRC    = $(wildcard alphabet.cpp colour.cpp image.cpp ppm.cpp)
BIN    = main

all : clean $(BIN)

main : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN) $(SRC)

clean :
	rm -f $(BIN)
