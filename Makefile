all:
	mkdir -p build/
	g++ src/main.cpp -o build/cplayer -Wall -g

clear:
	rm build/cplayer

run:
	./build/cplayer