CPPC=clang++
CPPFLAGS=-Wall -std=c++20 -g -fsanitize=address 
#CPPOPT=-O2 

all:
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -c src/source_files/queue.cpp -I obj/ -o obj/queue.o
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -c src/source_files/deque.cpp -I obj/ -o obj/deque.o
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -c src/source_files/sorted_list.cpp -I obj/ -o obj/sorted_list.o
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -c src/source_files/stack.cpp -I obj/ -o obj/stack.o
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -c src/source_files/bst.cpp -I obj/ -o obj/bst.o
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -c src/main.cpp -I obj/ -o obj/main.o
	$(CPPC) $(CPPFLAGS) $(CPPOPT) -o bin/app ./obj/deque.o ./obj/queue.o ./obj/sorted_list.o ./obj/stack.o ./obj/bst.o ./obj/main.o

clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;
	cat bin/output.txt
