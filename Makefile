CC = gcc
CFLAGS = -Wall -g $(shell sdl2-config --cflags)
LIBS = $(shell sdl2-config --libs) -lSDL2_mixer

SRC = src/main.c src/player.c
OBJ = $(SRC:.c=.o)
TARGET = build/cplayer

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build src/*.o

run: all
	./$(TARGET)
