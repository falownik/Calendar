all:
	g++ -I ./lib/include -c grafics.cpp
	g++ grafics.o -o Calendar -L ./lib/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=./lib/lib
	rm -f *.o
	./Calendar
