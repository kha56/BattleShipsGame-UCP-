CC=gcc
CFLAGS=-Wall -g
OBJ=FileReading.c LinkedList.c Game.c Menu.c
EXEC=BattleShip


$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

FileReading.o: FileReading.c FileReading.h LinkedList.h
	$(CC) $(CFLAGS) -c FileReading.c

Game.o: Game.c FileReading.h LinkedList.h
	$(CC) $(CFLAGS) -c Game.c


LinkedList.o: LinkedList.c LinkedList.h 
	$(CC) $(CFLAGS) -c LinkedList.c


Menu.o: Menu.c FileReading.h LinkedList.h Game.h
	$(CC) $(CFLAGS) -c Menu.c

clean:
	rm -f $(EXEC) $(OBJ)