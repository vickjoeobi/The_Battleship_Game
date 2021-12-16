#include "game.h"

//Functions

/**
 * @brief initBoards: The function Initializes the gameBoard for the players. 
 *                    It loads the game board and initializes it with the initial value of water '~'
 * @param Board 
 * @param playerShipsLocations 
 */
void initBoards(char Board[BOX][BOX], char playerShipsLocations[BOX][BOX])
{

    for (int i = 0; i < BOX; i++)
    { //rows
        for (int j = 0; j < BOX; j++)
        {                        //columns
            Board[i][j] = WATER; //Initializing all the Boxes as water
            playerShipsLocations[i][j] = WATER;
        }
    }
}

/**
 * @brief The functions prints the gameBoard in accordance with the program specification.
 * 
 * @param Board 
 */
void printBoard(char Board[BOX][BOX])
{
    int i = 0, j = 0;
    char row[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Array of Digits to print in the Top Columns

    printf("  1 2 3 4 5 6 7 8 9 10\n"); //Printing numbers in the top Rows

    for (i = 0; i < BOX; i++) //rows letters
    {
        printf("%c ", row[i]);    //Printing Characters in the Top Columns
        for (j = 0; j < BOX; j++) //columnx
        {
            switch (Board[i][j])
            {
            case HIT:
                printf("%c ", HIT);
                break;
            case MISS:
                printf("%c ", MISS);
                break;
            case WATER:
            default:
                printf("%c ", Board[i][j]);
                break;
            }
        }

        putchar('\n');
    }
}

/**
 * @brief Places the ships according to the specification. All ships are marked 'U'. 
 * 
 * @param playerShipsLocations 
 * @param Board 
 * @param shipSize 
 */
void placeShip(char playerShipsLocations[BOX][BOX], char Board[BOX][BOX], int shipSize)
{
    int direction = -1; //not defined
    int x, y;
    int checked;
    int counter;
    do
    {
        counter = 0;
        direction = rand() % 2; //generate 0 HORIZONTAL  , 1 VERTICAL

        if (direction == HORIZONTAL) //Placing the ships Horizontal
        {
            x = rand() % (BOX); //value from  0-10
            y = rand() % (BOX - shipSize);
        }
        if (direction == VERTICAL) //Placing the ships Vertical
        {
            x = rand() % (BOX - shipSize);
            y = rand() % (BOX);
        }

        if (direction == HORIZONTAL) //check if we are able to place the ships in this poistion or not based on the requirements
        {
            int i = shipSize - 1;
            for (i = 0; i < shipSize; i++)
            {
                if (playerShipsLocations[y + i][x] != SHIPSYMBOL && playerShipsLocations[y + i][x + 1] != SHIPSYMBOL &&
                    playerShipsLocations[y + i][x - 1] != SHIPSYMBOL && playerShipsLocations[y + i + 1][x] != SHIPSYMBOL &&
                    playerShipsLocations[y + i - 1][x] != SHIPSYMBOL && y + i < BOX)

                {
                    counter++;
                }
                else
                    checked = 0;
            }

            if (counter == shipSize)
                checked = 1;
        }

        if (direction == VERTICAL) //check if we are able to place the ships in this poistion or not based on the requirements
        {
            int i = shipSize - 1;
            for (i = 0; i < shipSize; i++)
            {
                if (playerShipsLocations[y][x + i] != SHIPSYMBOL && playerShipsLocations[y][x + 1 + i] != SHIPSYMBOL &&
                    playerShipsLocations[y][x - 1 + i] != SHIPSYMBOL && playerShipsLocations[y + 1][x + i] != SHIPSYMBOL &&
                    playerShipsLocations[y - 1][x + i] != SHIPSYMBOL && (x + i) < BOX)
                {
                    counter++;
                }
                else
                    checked = 0;
            }
            if (counter == shipSize)
                checked = 1;
        }
    } while (checked == 0);

    //placing ships if "check = 1"
    int i = shipSize - 1;
    for (i = 0; i < shipSize; i++)
    {
        if (direction == VERTICAL)
        {
            playerShipsLocations[y][x + i] = SHIPSYMBOL;
            // Board[y][x + i] = SHIPSYMBOL; //Comment this for Ships not to show
        }
        else
        {
            playerShipsLocations[y + i][x] = SHIPSYMBOL;
            // Board[y+i][x] = SHIPSYMBOL; //Comment this for Ships not to show
        }
    }
}

/**
 * @brief This function is the same as above, but it is used to place the ships for single game players. 
 * 
 * @param playerShipsLocations 
 * @param Board 
 * @param shipSize 
 */
void placeShipSinglePlayer(char playerShipsLocations[BOX][BOX], char Board[BOX][BOX], int shipSize)
{
    int direction = -1; //not defined
    int x, y;
    int checked;
    int counter;
    do
    {
        counter = 0;
        direction = rand() % 2; //generate 0 HORIZONTAL  , 1 VERTICAL
        //printf("the direction generated is %d\n  ",direction);

        //generate random value

        if (direction == HORIZONTAL)
        {
            x = rand() % (BOX); //value from  0-10
            y = rand() % (BOX - shipSize);
            //	printf("the value generated is x:  %d ,y: %d \n ",x,y );
        }
        if (direction == VERTICAL)
        {
            x = rand() % (BOX - shipSize);
            y = rand() % (BOX);
            //	printf("the value generated isx:  %d ,y: %d \n ",x,y );
        }

        //check if we are able to place the ships in this poistion or not

        if (direction == HORIZONTAL)
        {
            int i = shipSize - 1;
            for (i = 0; i < shipSize; i++)
            {
                if (playerShipsLocations[y + i][x] != SHIPSYMBOL && playerShipsLocations[y + i][x + 1] != SHIPSYMBOL &&
                    playerShipsLocations[y + i][x - 1] != SHIPSYMBOL && playerShipsLocations[y + i + 1][x] != SHIPSYMBOL &&
                    playerShipsLocations[y + i - 1][x] != SHIPSYMBOL && y + i < BOX)

                {
                    counter++;
                }
                else
                    checked = 0;
            }

            if (counter == shipSize)
                checked = 1;
        }

        if (direction == VERTICAL)
        {
            int i = shipSize - 1;
            for (i = 0; i < shipSize; i++)
            {
                if (playerShipsLocations[y][x + i] != SHIPSYMBOL && playerShipsLocations[y][x + 1 + i] != SHIPSYMBOL &&
                    playerShipsLocations[y][x - 1 + i] != SHIPSYMBOL && playerShipsLocations[y + 1][x + i] != SHIPSYMBOL &&
                    playerShipsLocations[y - 1][x + i] != SHIPSYMBOL && (x + i) < BOX)
                {
                    counter++;
                }
                else
                    checked = 0;
            }
            if (counter == shipSize)
                checked = 1;
        }
    } while (checked == 0);

    //placing ships if check =1
    int i = shipSize - 1;

    for (i = 0; i < shipSize; i++)
    {
        if (direction == VERTICAL)
        {
            playerShipsLocations[y][x + i] = SHIPSYMBOL;
            Board[y][x + i] = SHIPSYMBOL; //Comment this for Ships not to show
        }

        else
        {
            playerShipsLocations[y + i][x] = SHIPSYMBOL;
            Board[y + i][x] = SHIPSYMBOL; //Comment this for Ships not to show
        }
    }
}

/**
 * @brief This function takes no input. 
 *        It help place the ships according to the given specifications. 
 * 
 */
void placeAllShipsRandomlly()
{
    //place ships randomly ,total =10 ships ....boxes =30
    //player 1 ships
    //1 ship over 5 boxes

    int ar[BOX] = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2};
    for (int i = 0; i < BOX; i++)
    {
        placeShip(player1ShipsLocations, BoardPlayer1, ar[i]);
    }

    printf("\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
    printf("|			Player 1 ships placed Randomlly							 |\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
    printf("\n");

    sleep(1);

    //player 2 ships
    for (int i = 0; i < BOX; i++)
    {
        placeShip(player2ShipsLocations, BoardPlayer2, ar[i]);
    }

    printf("\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
    printf("|			Player 2 ships placed Randomlly							 |\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
    printf("\n");

    sleep(1);
}

/**
 * @brief This player acts as the same as the previous function, but is used specifically for the single players. 
 * 
 */
void placeAllShipsRandomllySinglePlayer()
{
    //place ships randomly ,total =10 ships ....boxes =30
    //player 1 ships
    //1 ship over 5 boxes

    int ar[BOX] = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2};
    for (int i = 0; i < BOX; i++)
    {
        placeShipSinglePlayer(player1ShipsLocations, BoardPlayer1, ar[i]);
    }

    printf("\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
    printf("|			Player 1 ships placed Randomlly							 |\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
    printf("\n");
    sleep(1);

    //player AI ships
    for (int i = 0; i < BOX; i++)
    {
        placeShip(player2ShipsLocations, BoardPlayer2, ar[i]);
    }

    printf("\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
    printf("|			AI ships placed Randomlly							 |\n");
    printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
    printf("\n");
    sleep(1);
}

/**
 * @brief This function is used to get input from the user, and return it as a coordinate. 
 * 
 * @return coordinates 
 */
coordinates getInput(void)
{
    coordinates target; //Return variable
    int initialX, swap; //Used in swapping for letter entry
    char targetChar;
    target.x = -1;
    target.y = -1;

    fflush(stdin);

    do
    {
        //Collect input from user, convert the character string to interger
        printf("> Enter Target (ex. > B 3):\n");
        printf(">>>");
        scanf("%c %d", &targetChar, &initialX);
        if (targetChar == 'A' || targetChar == 'a')
            target.y = 0;
        else if (targetChar == 'B' || targetChar == 'b')
            target.y = 1;
        else if (targetChar == 'C' || targetChar == 'c')
            target.y = 2;
        else if (targetChar == 'D' || targetChar == 'd')
            target.y = 3;
        else if (targetChar == 'E' || targetChar == 'e')
            target.y = 4;
        else if (targetChar == 'F' || targetChar == 'f')
            target.y = 5;
        else if (targetChar == 'G' || targetChar == 'g')
            target.y = 6;
        else if (targetChar == 'H' || targetChar == 'h')
            target.y = 7;
        else if (targetChar == 'I' || targetChar == 'i')
            target.y = 8;
        else if (targetChar == 'J' || targetChar == 'j')
            target.y = 9;
        else
            target.y = 100;

        target.x = initialX - 1;

        //Checking if the input is correct, else asking the user for another input
        if ((target.y < 0 || target.y > 9) || (target.x < 0 || target.x > 9))
        {
            printf("\n");
            printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
            printf("| Wrong Input please Play again										 |\n");
            printf("| HINT: Enter number from A - J and Letter from 1 - 10 (example C 3) |\n");
            printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
            printf("\n");
        }

    } while (target.y < 0 || target.y > 9 || target.x < 0 || target.x > 9);
    swap = target.x;
    target.x = target.y;
    target.y = swap;

    return target;
}

/**
 * @brief This is player is used to determine the game status.  
 *        It checks if it is a HIT, MISS or wrong play. 
 * @param Board 
 * @param inputs 
 * @return int 
 */
int playStatus(char playerShipsLocations[BOX][BOX], coordinates inputs)
{
    int status; //1 = Hit, 2 = Miss, 3 = Hiting wrong place
    switch (playerShipsLocations[inputs.x][inputs.y])
    {
    case SHIPSYMBOL:
        status = 1; //HIT
        break;
    case WATER:
        status = 2; //MISS
        break;
    case HIT:
    case MISS:
    default:
        status = 3; //Wrong HIT or MISS
        break;
    }
    return status;
}

/**
 * @brief It helps to randomly generate number for the easy mode. It is also used in the HARD MODE to generate numbers. 
 * 
 * @return coordinates 
 */
coordinates RandomlyGeneratePlayPositionEasy(void)
{
    coordinates inputs;

    // Generates number from 0 - 9 for both x and Y;
    inputs.x = (rand() % 10);
    inputs.y = (rand() % 10);

    return inputs;
}