checker.out : checker.o CheckerRunner.o Trie.o
	g++ -ansi -Wall -g -o checker.out checker.o CheckerRunner.o Trie.o

checker.o : checker.cpp CheckerRunner.h checker.h Trie.h
	g++ -ansi -Wall -g -c checker.cpp

CheckerRunner.o : CheckerRunner.cpp CheckerRunner.h checker.h CPUTimer.h
	g++ -ansi -Wall -g -c CheckerRunner.cpp

Trio.o : Trie.cpp Trie.h
	g++ -ansi -Wall -g -c Trie.cpp CheckerRunner.h

clean :
	rm -f checker.out checker.o  CheckerRunner.o Trie.o
