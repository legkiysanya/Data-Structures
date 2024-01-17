FC=clang++
FFLAGS=-Wall -std=c++20 -g
FOPT=-Os  

all:
	$(FC) $(FFLAGS) $(FOPT) -c src/deque.cpp -o obj/deque.o
	$(FC) $(FFLAGS) $(FOPT) -c src/queue.cpp -o obj/queue.o
	$(FC) $(FFLAGS) $(FOPT) -c src/main.cpp -I obj/ -o obj/main.o
	$(FC) $(FFLAGS) $(FOPT) -o bin/app ./obj/deque.o ./obj/queue.o ./obj/main.o

clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;
