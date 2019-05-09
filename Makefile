.PHONY: all clean install uninstall

OBJ      = build/chess.o build/main.o build/board_print_plain.o
LINKOBJ  = build/chess.o build/main.o build/board_print_plain.o

all : bin/shah

test : bin/main-test

clean: 
	rm -rf $(BIN) build/*.o  

bin/shah: $(OBJ)
	gcc -std=c99 $(LINKOBJ) -o bin/shah

build/chess.o: src/chess.c  
	gcc -Wall -std=c99 -c src/chess.c -o build/chess.o 

build/main.o: src/main.c
	gcc -Wall -std=c99  -c src/main.c -o build/main.o 


bin/main-test: build_test/chess.o build_test/main.o build_test/board_print_plain.o build_test/test.o
	gcc -std=c99 build_test/chess.o build_test/main.o build_test/board_print_plain.o build_test/test.o -o bin/main-test
build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -std=c99  -c src/board_print_plain.c -o build/board_print_plain.o
build_test/chess.o: src/chess.c  
	gcc -Wall -std=c99 -c src/chess.c -o build/chess.o 

build_test/main.o: src/main.c
	gcc -Wall -std=c99  -c src/main.c -o build/main.o 

build_test/board_print_plain.o: src/board_print_plain.c
	gcc -Wall  -std=c99 -c src/board_print_plain.c -o build/board_print_plain.o
build_test/test.o: test/test.c
	gcc -Wall -std=c99 -c test/test.c -o build_test/test.o
