all : testcase main
CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
SFML=SFML-2.5.1
#SRC= $(wildcard ../*.cc)
#OBJ= $(SRC:.cc=.o)
#TST= $(wildcard *.cc)
#OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o)

main : 
	$(CC) $(CCFLAGS) -I$(SFML)/include/ -Iproject_lib/ -c main.cpp
	$(CC) main.o -o main -L$(SFML)/lib/ -lsfml-window -lsfml-system -lsfml-graphics

testcase :  
	$(CC) $(CCFLAGS) -I$(SFML)/include/ -Iproject_lib/ -c tests/TestCase.cc -o tests/TestCase.o
	$(CC) tests/TestCase.o -o tests/testcase -L$(SFML)/lib/ -lsfml-window -lsfml-system -lsfml-graphics

%.o: %.cc 
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f tests/testcase tests/TestCase.o main main.o