FLAGS = -Wall -Wextra -Wpedantic
CC = g++

all: play

play: game.cpp card.cpp
	$(CC) $(FLAGS) game.cpp card.cpp -o play 

clean: 
	rm play
