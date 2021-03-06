.PHONY: all clean install uninstall

OBJ      = build/src/chess.o build/src/main.o build/src/board_print_plain.o
LINKOBJ  = build/src/chess.o build/src/main.o build/src/board_print_plain.o
FLAG = -Wall -Werror
all : bin/shah

test : bin/main-test

clean: 
	rm -rf $(BIN) build/src/*.o  
clean_test: 
	rm -rf $(BIN) build/test/*.o 
	rm -rf $(BIN) build/test/*.d  

bin/shah: $(OBJ)
	gcc -std=c99 $(LINKOBJ) -o bin/shah

build/src/chess.o: src/chess.c  
	gcc $(FLAG)  -std=c99 -c src/chess.c -o build/src/chess.o 

build/src/main.o: src/main.c
	gcc $(FLAG)   -std=c99  -c src/main.c -o build/src/main.o 
	
build/src/board_print_plain.o: src/board_print_plain.c
	gcc $(FLAG)   -std=c99  -c src/board_print_plain.c -o build/src/board_print_plain.o

-include build_test/*.d

bin/main-test: build/test/chess.o build/test/board_print_plain.o build/test/test.o build/test/main.o
	gcc  -std=c99 build/test/chess.o build/test/main.o build/test/board_print_plain.o build/test/test.o -o bin/main-test

build/test/chess.o: src/chess.c  
	gcc $(FLAG)   -I thirdparty -I src -std=c99 -c src/chess.c -MMD  -o build/test/chess.o 
build/test/main.o: test/main.c
	gcc $(FLAG)    -I thirdparty -I src -std=c99  -c test/main.c -MMD  -o build/test/main.o 
build/test/board_print_plain.o: src/board_print_plain.c
	gcc $(FLAG)   -I thirdparty -I src -std=c99 -c src/board_print_plain.c -MMD -o build/test/board_print_plain.o
build/test/test.o: test/test.c
	gcc $(FLAG)   -I thirdparty -I src -std=c99 -MMD  -c test/test.c -o build/test/test.o
