all:
	g++ -I C:/'Program Files'/SFML/include -c grafics.cpp
	g++ -o Calendar grafics.o Graphics.o
	rm -f *.o
	./Calendar
