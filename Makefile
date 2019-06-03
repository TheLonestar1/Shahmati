.PHONY: all clean


OBJ      = build/chess.o build/main.o build/board_print_plain.o
LINKOBJ  = build/chess.o build/main.o build/board_print_plain.o
clean-bin :
	rm -rf $(BIN) build/*

all : bin/shah

clean: 
	rm -rf $(BIN) build/*.o

bin/shah: $(OBJ)
	gcc $(LINKOBJ) -o bin/shah

build/chess.o: src/chess.c  
	gcc -Wall -Werror -MP -MMD -c src/chess.c -o build/chess.o 

build/main.o: src/main.c
	gcc -Wall -Werror  -MP -MMD -c src/main.c -o build/main.o 

build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall  -Werror  -MP -MMD -c src/board_print_plain.c -o build/board_print_plain.o
