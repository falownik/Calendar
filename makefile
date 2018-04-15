all:
	g++ -I ./lib C:/'Program Files'/SFML/include -c grafics.cpp
	g++ -o Calendar grafics.o
	rm -f *.o
	./Calendar
