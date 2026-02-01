all:
	mkdir -p build/
	g++ src/main.cpp -o build/test

clear:
	rm build/test

run:
	/build/test