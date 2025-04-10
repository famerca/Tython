CXX = g++
FLEX = flex
BISON = bison -Wcounterexamples --defines=token.h

all: parser

parser: parser.o scanner.o main.o ast.o error.o
	$(CXX) scanner.o parser.o ast.o main.o error.o -o parser.out

parser.o: parser.c
	$(CXX) -c parser.c

parser.c: parser.bison
	$(BISON) -v --output parser.c parser.bison

scanner.o: token.h scanner.c
	$(CXX) -c scanner.c

scanner.c: scanner.flex
	$(FLEX) -o scanner.c scanner.flex

main.o: token.h main.cpp
	$(CXX) -c main.cpp

ast.o: ast.cpp
	$(CXX) -c ast.cpp

error.o: error.cpp
	$(CXX) -c error.cpp

.PHONY:
clean:
	$(RM) *.o parser.c parser.output token.h scanner.c parser.out 