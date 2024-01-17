FC=clang++
FFLAGS=-Wall -std=c++20 -g
FOPT=-Os  

all:
	$(FC) $(FFLAGS) $(FOPT) -c src/main.cpp -I obj/ -o obj/main.o
	$(FC) $(FFLAGS) $(FOPT) -o bin/app ./obj/main.o

	#$(FC) $(FFLAGS) $(FOPT) -c src/deque.hpp -o obj/deque.so
	#$(FC) $(FFLAGS) $(FOPT) -c src/queue.cpp -o obj/queue.o
	#$(FC) $(FFLAGS) $(FOPT) -c src/stack.cpp -I obj/ -o obj/stack.o
	#$(FC) $(FFLAGS) $(FOPT) -c src/main.cpp -I obj/ -o obj/main.o
	#$(FC) $(FFLAGS) $(FOPT) -o bin/app ./obj/deque.so ./obj/queue.o ./obj/stack.o ./obj/main.o


clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;






#FC=clang++
#FFLAGS=-Wall -std=c++20 -g
#FOPT=-Os  
#
#all:
#	$(FC) $(FFLAGS) $(FOPT) -c src/stack.cpp -o obj/stack.o
#	$(FC) $(FFLAGS) $(FOPT) -o bin/app ./obj/stack.o 
#
#clean:
#	rm -rf obj/*
#	rm -rf bin/*
#
#run:
#	cd ./bin; ./app;
