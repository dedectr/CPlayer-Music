CC = gcc
CFLAGS = -Wall -g $(shell sdl2-config --cflags)
LIBS = $(shell sdl2-config --libs) -lSDL2_mixer
SRC = src/main.c
TARGET = build/cplayer

all:
	mkdir -p build/
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

clear:
	rm -rf build/

run:
	./$(TARGET)