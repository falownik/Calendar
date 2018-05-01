all:
	g++ -std=c++14 -I ./lib -I ./lib/include -c Calendar.cpp grafics.cpp
	g++ Calendar.o grafics.o -o Calendar -L ./lib/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=./lib/lib
	rm -f *.o
	./Calendar
