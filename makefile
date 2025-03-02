CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
OBJ=main.o in_out.o graphic.o game.o

sudoku: $(OBJ)
	$(CC) -o sudoku $(OBJ) $(CFLAGS) -lMLV

main.o: main.c graphic.h
	$(CC) -c main.c $(CFLAGS)

in_out.o: in_out.c in_out.h
	$(CC) -c in_out.c $(CFLAGS)

graphic.o: graphic.c graphic.h
	$(CC) -c graphic.c $(CFLAGS) -lMLV

game.o: game.c game.h
	$(CC) -c game.c $(CFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f sudoku
