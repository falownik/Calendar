all:
	g++ -I ./lib/SFML/include -c grafics.cpp
	g++ -o Calendar grafics.o -L ./lib/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
	rm -f *.o
	export LD_LIBRARY_PATH=./lib/SFML/lib && ./Calendar
