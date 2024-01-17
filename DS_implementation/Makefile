CPPC=clang++
CPPFLAGS=-Wall -std=c++20 -g
CPPOPT=-Os  

all:
	$(CPPC) $(PPFLAGS) $(CPPOPT) -c src/main.cpp -I obj/ -o obj/main.o
	$(CPPC) $(PPFLAGS) $(CPPOPT) -o bin/app ./obj/main.o

clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;
