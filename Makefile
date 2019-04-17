.PHONY: all clean install uninstall

BIN      = Шахматы.exe
OBJ      = chess.o main.o board_print_plain.o
LINKOBJ  = chess.o main.o board_print_plain.o

all : $(BIN)

clean: 
	rm -rf $(BIN) *.o  
install:
	install ./$(BIN) /usr/local/bin
unistall:
	rm -rf /usr/local/bin/$(BIN)

$(BIN): $(OBJ)
	gcc $(LINKOBJ) -o $(BIN)

chess.o: src/chess.c  
	gcc -Wall -MP -MMD -c src/chess.c -o src/chess.o 

main.o: src/main.c
	gcc -Wall -MP -MMD -c src/main.c -o src/main.o 

board_print_plain.o: src/board_print_plain.c
	gcc -Wall -MP -MMD -c src/board_print_plain.c -o src/board_print_plain.o
