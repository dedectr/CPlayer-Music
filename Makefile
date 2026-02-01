all:
	mkdir -p build/
	g++ src/main.cpp -o build/test

clear:
	rm build/cplayer

run:
	./build/test