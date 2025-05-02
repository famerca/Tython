CXX = g++ -std=c++17 -g -O0
FLEX = flex
BISON = bison -Wcounterexamples --defines=token.h

all: parser

parser: parser.o scanner.o main.o ast.o analysis.o symbolTable.o context.o
	$(CXX) scanner.o parser.o ast.o main.o analysis.o context.o symbolTable.o -o parser.out

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

analysis.o: analysis.cpp
	$(CXX) -c analysis.cpp

symbolTable.o: symbolTable.cpp
	$(CXX) -c symbolTable.cpp

context.o: context.cpp
	$(CXX) -c context.cpp

.PHONY:
clean:
	$(RM) *.o parser.c parser.output token.h scanner.c parser.out 