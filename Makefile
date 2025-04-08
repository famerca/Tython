CXX = g++
FLEX = flex
BISON = bison -Wcounterexamples --defines=token.h

all: validator

validator: parser.o scanner.o main.o ast.o
	$(CXX) scanner.o parser.o ast.o main.o -o validator.out

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

.PHONY:
clean:
	$(RM) *.o parser.c parser.output token.h scanner.c validator