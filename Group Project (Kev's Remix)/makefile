CC = g++
CFLAGS = -std=c++0x -g -Wall
OBJ = Ant.o Critter.o Doodlebug.o Game.o InputValidation.o main.o Menu.o
DEST = predatorPrey

$(DEST): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(DEST)

Ant.o: Ant.cpp
	$(CC) $(CFLAGS) -c Ant.cpp

Critter.o: Critter.cpp
	$(CC) $(CFLAGS) -c Critter.cpp

Doodlebug.o: Doodlebug.cpp
	$(CC) $(CFLAGS) -c Doodlebug.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

InputValidation.o: InputValidation.cpp
	$(CC) $(CFLAGS) -c InputValidation.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Menu.o: Menu.cpp
	$(CC) $(CFLAGS) -c Menu.cpp

clean:
	rm $(OBJ) $(DEST)
 
