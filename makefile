all:
	g++ -I C:/'Program Files'/SFML/include -c grafics.cpp
	g++ -o Calendar grafics.o -L C:/'Program Files'/SFML//lib -lsfml-graphics -lsfml-window -lsfml-system
	rm -f *.o
	./Calendar
