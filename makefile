all:
	g++ -I ./lib -c grafics.cpp
	g++ -o Calendar grafics.o
	rm -f *.o
	./Calendar
