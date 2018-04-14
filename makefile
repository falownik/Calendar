all:
	g++ -I ./lib -c Vector.cpp Test.cpp
	g++ -o Vector Vector.o Test.o
	rm -f *.o
	./Vector
