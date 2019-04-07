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

chess.o: chess.c  
	gcc -Wall -MP -MMD -c chess.c -o chess.o 

main.o: main.c
	gcc -Wall -MP -MMD -c main.c -o main.o 

board_print_plain.o: board_print_plain.c
	gcc -Wall -MP -MMD -c board_print_plain.c -o board_print_plain.o
