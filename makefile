#Kompilacja warunkowa zalezna od wprowadzonych zmian
CC = g++
CFLAGS = -std=c++14 -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: Calendar.o grafics.o
	$(CC) Calendar.o grafics.o -o Calendar -L ./lib/lib $(LIBS) 
	export LD_LIBRARY_PATH=./lib/lib
	./Calendar

grafics.o: grafics.cpp
	$(CC) $(CFLAGS) -I ./lib -I ./lib/include -c grafics.cpp

Calendar.o: Calendar.cpp
	$(CC) $(CFLAGS) -I ./lib -I ./lib/include -c Calendar.cpp

clean:		
	rm -f *.o

