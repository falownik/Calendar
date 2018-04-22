all:
	g++ -I ./lib -c Calendar.cpp
	g++ Calendar.o -o Calendar -L ./lib/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=./lib/lib
	rm -f *.o
	./Calendar
