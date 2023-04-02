outcsv: main.o cnt.o timer_m.o
	g++ -O3 -o outcsv main.o cnt.o timer_m.o
main.o: main.cpp
	g++ -O3 -I/usr/include/eigen3 -c main.cpp
cnt.o: cnt.cpp
	g++ -O3 -I/usr/include/eigen3 -c cnt.cpp
timer_m.o: timer_m.cpp
	g++ -O3 -c timer_m.cpp
