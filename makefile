all:
	g++ -I C:/'Program Files'/SFML/include -c grafics.cpp
	g++ -o Calendar grafics.o SFML/Graphics.hpp
	rm -f *.o
	./Calendar
