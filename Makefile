.PHONY: all clean install uninstall

OBJ      = build/chess.o build/main.o build/board_print_plain.o
LINKOBJ  = build/chess.o build/main.o build/board_print_plain.o

all : bin/shah

clean: 
	rm -rf $(BIN) *.o  
install:
	install ./$(BIN) /usr/local/bin
unistall:
	rm -rf /usr/local/bin/$(BIN)

bin/shah: $(OBJ)
	gcc $(LINKOBJ) -o bin/shah

build/chess.o: src/chess.c  
	gcc -Wall -c src/chess.c -o build/chess.o 

build/main.o: src/main.c
	gcc -Wall  -c src/main.c -o build/main.o 

build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall  -c src/board_print_plain.c -o build/board_print_plain.o
