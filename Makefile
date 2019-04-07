

BIN      = Шахматы.exe
OBJ      = chess.o main.o board_print_plain.o
LINKOBJ  = chess.o main.o board_print_plain.o 

$(BIN): $(OBJ)
	gcc $(LINKOBJ) -o $(BIN)

chess.o: chess.c
	gcc -Wall -c chess.c -o chess.o 

main.o: main.c
	gcc -Wall -c main.c -o main.o 

board_print_plain.o: board_print_plain.c
	gcc -Wall -c board_print_plain.c -o board_print_plain.o

