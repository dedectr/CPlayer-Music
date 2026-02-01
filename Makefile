# Variáveis para facilitar mudanças
CXX = g++
CXXFLAGS = -Wall -g -std=c++17
LIBS = -lsfml-audio -lsfml-system
SRC = src/main.cpp
TARGET = build/cplayer

all:
	mkdir -p build/
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LIBS)

clear:
	rm -rf build/

run:
	ALSOFT_DRIVERS=pulse ./$(TARGET)