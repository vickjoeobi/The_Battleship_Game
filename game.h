#ifndef GAME
#define GAME

//Header File used
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Global Variables
#define BOX 10 //The Size of the game board is 10 x 10, this represents both the no of columns and no of rows

#define HORIZONTAL 1 //placing ships horizontally
#define VERTICAL 0   //placing  ships vertically

#define WATER '~'
#define HIT 'H'
#define MISS 'M'
#define SHIPSYMBOL 'U'

char BoardPlayer1[BOX][BOX]; //Main Game Board for Player1
char BoardPlayer2[BOX][BOX]; //Main Game Board for P2ayer1

char player1ShipsLocations[BOX][BOX];
char player2ShipsLocations[BOX][BOX];

//Struct
typedef struct coordinates //Structs  for X,Y coordinate for players play position
{
    int x;
    int y;
} coordinates;

//Function Prototypes
void initBoards(char Board[BOX][BOX], char playerShipsLocations[BOX][BOX]);
void printBoard(char Board[BOX][BOX]);
void placeShip(char playerShipsLocations[BOX][BOX], char Board[BOX][BOX], int shipSize);
void placeShipSinglePlayer(char playerShipsLocations[BOX][BOX], char Board[BOX][BOX], int shipSize);
void placeAllShipsRandomlly(void);
void placeAllShipsRandomllySinglePlayer();
coordinates getInput(void);
int playStatus(char playerShipsLocations[BOX][BOX], coordinates inputs);
coordinates RandomlyGeneratePlayPositionEasy(void);
int randomGenerator(int min, int max);

#endif