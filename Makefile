outcsv: main.o cnt.o
	g++ -o outcsv main.o cnt.o
main.o: main.cpp
	g++ -I/usr/include/eigen3 -c main.cpp
cnt.o: cnt.cpp
	g++ -I/usr/include/eigen3 -c cnt.cpp
