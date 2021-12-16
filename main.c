#include "game.h"

int main(void)
{
	srand(time(NULL));														 //Usede for the randomGenerator Function
	coordinates player1Points;												 //Used to save the players play position for player1
	coordinates player2Points;												 //Used to save the players play position for player2
	int player1Gamestatus;													 //Used to determine HIT, MISS, or Wrong Move for player1
	int player2GameStatus;													 //Used to determine HIT, MISS, or Wrong Move for player1
	int shipCounterPlayer1 = 30;											 //Initialized the ships to determine when all ships are sunk player 1
	int shipCounterPlayer2 = 30;											 //Initialized the ships to determine when all ships are sunk player 1
	int select;																 //Used for players to select their choice in starting of the game
	int select1;															 //Same as above
	int run1 = 0;															 //Used as a flag
	int run = 0;															 //Same as above
	int player = rand() % 2;												 //get random no 0 or 1 & Choose who comes first
	int isHitting = 0;														 //Acting as a flag to determine when the battelship is been hit
	coordinates initialPlayPoint, upwards, downwards, rightwards, leftwards; //Used for placing and returning of Coordinates.
	int initial = 0;														 //Used as a flag to determine if this is the first point for HARD
	int isDownward = 0, isLeftward = 0, isRightward = 0, moveUpwards = 1;	 //Used in the HardScenerio

	//Battleship Welcome Page
	printf("                                _______                         \n");
	printf("                                 _|:|         ____              \n");
	printf("                               _|:::|       ::    ::            \n");
	printf("                         _ /|  |::::|       ::    ::            \n");
	printf("                         |::|  |::::|        \\____/            \n");
	printf("                         |::|  |:::::)__    _______             \n");
	printf("                       /:|:::: |::::::::|  ||     ||            \n");
	printf("                      :::|::::_|::::::::|  ||     ||            \n");
	printf("                ____(:::::::::::::::::::|___ _______         __ \n");
	printf("               (::::::::::::::::::::::::|:::|::::::|  ______|::)\n");
	printf("     ___OOOO___\\:::::::::::::::::::::::::::|:::|___|:::::::::|\n");
	printf("     \\:::::::::::::BATTLESHIP GAME OPCODERS......:::::::::::::|\n");
	printf("      |:::::::::::::::::::::::::::::::::::::::::::::::::::::::| \n");
	sleep(1);

	do
	{ //User is expected to choose if he wants to start the game or read the instruction
		printf("+===================================================================================|\n");
		printf("|     Please PRESS                                                                  |\n");
		printf("|                            ___________________________                            |\n");
		printf("|                            | ==> 1 [START GAME]      |                            |\n");
		printf("|                            | ==> 2 [INSTRUCTION]     |                            |\n");
		printf("|                            |_________________________|                            |\n");
		printf("|                                                                                   |\n");
		printf("+===================================================================================|\n");
		printf(">>>");

		scanf("%d", &select);
		getchar();

		switch (select) //First Switch Case to choose the Game Mode the user want to play
		{
		case 1:
			do
			{
				printf("+===================================================================================|\n");
				printf("|                                 SELECT GAME MODE                                  |\n");
				printf("+-----------------------------------------------------------------------------------|\n");
				printf("|     Please PRESS                                                                  |\n");
				printf("|                            ______________________________                         |\n");
				printf("|                            | ==> 1 [SINGLE PLAYER EASY]  |                        |\n");
				printf("|                            | ==> 2 [SINGLE PLAYER HARD]  |                        |\n");
				printf("|                            | ==> 3 [MULTIPLE PLAYER]     |                        |\n");
				printf("|                            |_____________________________|                        |\n");
				printf("|                                                                                   |\n");
				printf("+===================================================================================|\n");
				printf("\n");
				printf(">>>");
				scanf("%d", &select1);
				getchar();

				switch (select1)
				{
				case 1: //Easy Mode Chosen by the user
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|				 EASY MODE.											 |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");
					sleep(1);

					//Game setup
					//initialize player's board

					//player 1 Game Board Initialization
					initBoards(BoardPlayer1, player1ShipsLocations);
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|			Player 1 board is initialized							 |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");
					sleep(1);

					//AI Game Board Initialization
					initBoards(BoardPlayer2, player2ShipsLocations);
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|			AI board is initialized							 |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");
					sleep(1);

					//Place All ships randomly in the GameBoard and selecting the player to play first
					placeAllShipsRandomllySinglePlayer();

					//Switch Case to determine the returned player and write the appropraite message.
					switch (player)
					{
					case 0:
						printf("\n");
						printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
						printf("| Player 1 has been selected to go first.							 |\n");
						printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
						printf("\n");
						break;
					case 1:
						printf("\n");
						printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
						printf("| AI has been selected to go first.									 |\n");
						printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
						printf("\n");
						break;
					default:
						break;
					}

					while (1)
					{
						switch (player)
						{
						case 0: //Player 1
							do
							{
								printf("Player 1 Turn\n");
								printf("\n");
								printf("|=-=-=-=-=-=-=-=-=-=---|\n");
								printf("| AI GAME BOARD 	   |\n");
								printf("|=-=-=-=-=-=-=-=-=-=-=-|\n");
								printf("\n");
								printBoard(BoardPlayer2);									 //Printing gameBoard for player 1 to see his HIT or MISS
								player1Points = getInput();									 //Get input from player 1
								player1Gamestatus = playStatus(player2ShipsLocations, player1Points); //Determine the attack status
								if (player1Gamestatus == 1)									 //HIT
								{

									BoardPlayer2[player1Points.x][player1Points.y] = HIT;
									shipCounterPlayer2--;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| AI Ship was HIT by Player 1	 Bal: %d Box						 |\n", shipCounterPlayer2);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED AI GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer2);
									isHitting = 1;
									sleep(1);

									if (shipCounterPlayer2 == 0) //Used to determine if the ship is = 0 and therefore gameOver
									{
										printf("\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("| 				All AI's Ship was HIT by Player 1					 |\n");
										printf("| 							SUNK									 |\n");
										printf("| 				  		  GameOver								 |\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("\n");
										isHitting = 0;
										sleep(2);
										exit(0);
									}
								}
								else if (player1Gamestatus == 2) //MISS
								{
									BoardPlayer2[player1Points.x][player1Points.y] = MISS;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 2 Ship was MISSED by Player 1	 Bal: %d BOX				 |\n", shipCounterPlayer2);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 2 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer2);
									isHitting = 0;
									sleep(1);
								}
								else if (player1Gamestatus == 3) //Playing in the wrong position or previous Position
								{
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| You played in your previous position, Play again!!!				 |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									isHitting = 1;
								}
							} while (isHitting == 1);
							player = 1;
							break;
						case 1: //AI Turn
							do
							{
								printf("AI Turn\n");
								printf("\n");
								printf("|=-=-=-=-=-=-=-=-=-=---|\n");
								printf("| Player 1 GAME BOARD  |\n");
								printf("|=-=-=-=-=-=-=-=-=-=-=-|\n");
								printf("\n");
								printBoard(BoardPlayer1); //Printing gameBoard for all to see his HIT or MISS

								player2Points = RandomlyGeneratePlayPositionEasy(); //Randomly Generating play Position
								player2GameStatus = playStatus(player1ShipsLocations, player2Points);
								if (player2GameStatus == 1) //HIT
								{

									BoardPlayer1[player2Points.x][player2Points.y] = HIT;
									shipCounterPlayer1--;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 1 Ship was HIT by AI	 Bal: %d BOX					 |\n", shipCounterPlayer1);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 1 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer1);
									isHitting = 1;
									sleep(1);

									if (shipCounterPlayer1 == 0) //Used to determine if the ship is = 0 and therefore gameOver
									{
										printf("\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("| 				All Player 1's Ship was HIT by AI				 |\n");
										printf("| 							SUNK									 |\n");
										printf("| 				  		  GAME OVER								 |\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("\n");
										isHitting = 0;
										exit(1);
									}
								}
								else if (player2GameStatus == 2) //MISS
								{
									BoardPlayer1[player2Points.x][player2Points.y] = MISS;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 1 Ship was MISSED	 Bal: %d ships							 |\n", shipCounterPlayer1);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 1 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer1);
									isHitting = 0;
									sleep(1);
								}
								else if (player2GameStatus == 3)
								{
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| You played in your previous position, Play again!!!				 |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									isHitting = 1;
								}
							} while (isHitting == 1);
							player = 0;

						default:
							break;
						}
					}
					run1 = 1;
					break; //EASY End
				case 2:
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|				 HARD MODE											 |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");

					//Game setup
					//initialize player's board

					//player 1 Game Board Initialization

					initBoards(BoardPlayer1, player1ShipsLocations);
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|			Player 1 board is initialized							 |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");
					sleep(1);

					//AI Game Board Initialization
					initBoards(BoardPlayer2, player2ShipsLocations);
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|			AI board is initialized							         |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");
					sleep(1);

					//Place All ships randomly in the GameBoard and selecting the player to play first
					placeAllShipsRandomllySinglePlayer();

					//Switch Case to determine the returned player and write the appropraite message.
					switch (player)
					{
					case 0:
						printf("\n");
						printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
						printf("| Player 1 has been selected to go first.							 |\n");
						printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
						printf("\n");
						break;
					case 1:
						printf("\n");
						printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
						printf("| AI has been selected to go first.									 |\n");
						printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
						printf("\n");
						break;
					default:
						break;
					}

					while (1)
					{
						switch (player)
						{
						case 0: //Player 1
							do
							{
								printf("\n");
								printf("|=-=-=-=-=-=-=-=-=-=---|\n");
								printf("| AI GAME BOARD 	   |\n");
								printf("|=-=-=-=-=-=-=-=-=-=-=-|\n");
								printf("\n");
								printBoard(BoardPlayer2);									 //Printing gameBoard for player 1 to see his HIT or MISS
								player1Points = getInput();									 //Get input from player 1
								player1Gamestatus = playStatus(player2ShipsLocations, player1Points); //Attack Status
								if (player1Gamestatus == 1)									 //HIT
								{

									BoardPlayer2[player1Points.x][player1Points.y] = HIT;
									shipCounterPlayer2--;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| AI Ship was HIT by Player 1	 Bal: %d Box					 	 |\n", shipCounterPlayer2);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED AI GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer2);
									isHitting = 1;

									if (shipCounterPlayer2 == 0)
									{
										printf("\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("| 				All AI's Ship was HIT by Player 1				 	 |\n");
										printf("| 							SUNK									 |\n");
										printf("| 				  			GameOver								 |\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("\n");
										isHitting = 0;
										exit(0);
									}
								}
								else if (player1Gamestatus == 2) //MISS
								{
									BoardPlayer2[player1Points.x][player1Points.y] = MISS;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| AI Ship was MISSED by Player 1	 Bal: %d BOX					 |\n", shipCounterPlayer2);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED AI GAME BOARD  	  	 |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer2);
									isHitting = 0;
								}
								else if (player1Gamestatus == 3)
								{
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| You played in your previous position, Play again!!!				 |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									isHitting = 1;
								}
							} while (isHitting == 1);
							player = 1;
							break;
						case 1: //AI
							do
							{
								printf("\n");
								printf("|=-=-=-=-=-=-=-=-=-=---|\n");
								printf("| Player 1 GAME BOARD  |\n");
								printf("|=-=-=-=-=-=-=-=-=-=-=-|\n");
								printf("\n");
								printBoard(BoardPlayer1);

								//player2Points = RandomlyGeneratePlayPositionEasy(player2Points);

								if (initial == 0) //Verifies if this is the first time the function is evaluating
								{
									player2Points = RandomlyGeneratePlayPositionEasy();
									initial = 1; //Reinitializes the initial counter
									initialPlayPoint = player2Points;
									upwards = initialPlayPoint;
									downwards = initialPlayPoint;
									rightwards = initialPlayPoint;
									leftwards = initialPlayPoint;
									moveUpwards = 1;
								}
								else //confirms that this is not the first time the program ran.
								{
									if ((BoardPlayer1[player2Points.x][player2Points.y] == HIT || BoardPlayer1[initialPlayPoint.x][initialPlayPoint.y] == HIT) || (BoardPlayer1[player2Points.x][player2Points.y] == MISS && BoardPlayer1[initialPlayPoint.x][initialPlayPoint.y] == HIT)) //Checking if the last play was HIT
									{
										if ((BoardPlayer1[initialPlayPoint.x][initialPlayPoint.y] == HIT && BoardPlayer1[player2Points.x][player2Points.y] == HIT) && upwards.x > 0 && moveUpwards == 1) //Moving Upwards
										{
											upwards.x = upwards.x - 1;
											upwards.y = upwards.y;
											player2Points = upwards;
											downwards = initialPlayPoint;
										}

										else if (((BoardPlayer1[upwards.x][upwards.y] != HIT && BoardPlayer1[initialPlayPoint.x][initialPlayPoint.y] == HIT) || isDownward == 1) && downwards.x < 9 && (BoardPlayer1[downwards.x][downwards.y] != MISS)) //Moving Downwards
										{
											downwards.x = downwards.x + 1;
											downwards.y = downwards.y;
											player2Points = downwards;
											rightwards = initialPlayPoint;
											moveUpwards = 0;
										}

										else if (((BoardPlayer1[downwards.x][downwards.y] != HIT && BoardPlayer1[initialPlayPoint.x][initialPlayPoint.y] == HIT) || isRightward == 1) && rightwards.y < 9 && BoardPlayer1[rightwards.x][rightwards.y] != MISS) //Moving right
										{

											rightwards.x = rightwards.x;
											rightwards.y = rightwards.y + 1;
											player2Points = rightwards;
											leftwards = initialPlayPoint;
											moveUpwards = 0;
										}

										else if (((BoardPlayer1[rightwards.x][rightwards.y] != HIT && BoardPlayer1[initialPlayPoint.x][initialPlayPoint.y] == HIT) || isLeftward == 1) && leftwards.y > 0 && BoardPlayer1[leftwards.x][leftwards.y] != MISS) //Moving left
										{

											leftwards.x = leftwards.x;
											leftwards.y = leftwards.y - 1;
											player2Points = leftwards;
											moveUpwards = 0;
										}

										else //If no condition is satisfied
										{
											player2Points = RandomlyGeneratePlayPositionEasy();
											initialPlayPoint = player2Points;
											upwards = initialPlayPoint;
											downwards = initialPlayPoint;
											rightwards = initialPlayPoint;
											leftwards = initialPlayPoint;
											moveUpwards = 1;
											initial = 1;
										}
									}
									else //Generate fresh numbers and Initialize
									{
										player2Points = RandomlyGeneratePlayPositionEasy();
										initialPlayPoint = player2Points;
										upwards = initialPlayPoint;
										downwards = initialPlayPoint;
										rightwards = initialPlayPoint;
										leftwards = initialPlayPoint;
										moveUpwards = 1;
										initial = 1;
									}
								}

								player2GameStatus = playStatus(player1ShipsLocations, player2Points);
								if (player2GameStatus == 1) //HIT
								{

									BoardPlayer1[player2Points.x][player2Points.y] = HIT;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 1 Ship was HIT by AI	 Remaining: %d BOX					 |\n", shipCounterPlayer1 - 1);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 1 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer1);
									isHitting = 1;
									shipCounterPlayer1--;

									if (shipCounterPlayer1 == 0)
									{
										printf("\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("| 				All Player 1 Ship was HIT by AI						 |\n");
										printf("| 							SUNK									 |\n");
										printf("| 				  			GAME OVER								 |\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("\n");
										isHitting = 0;
										exit(1);
									}
								}
								else if (player2GameStatus == 2) //MISS
								{
									BoardPlayer1[player2Points.x][player2Points.y] = MISS;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 1 Ship was MISSED	 Remaining: %d BOX						 |\n", shipCounterPlayer1);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 1 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer1);
									isHitting = 0;
								}
								else if (player2GameStatus == 3) //Previous Position Played
								{
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| You played in your previous position, Play again!!!				 |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									isHitting = 1;
								}
							} while (isHitting == 1);
							player = 0;

						default:
							break;
						}
					}
					run1 = 1;
					break; //HARD End
				case 3:

					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|				 TWO Player MODE									 |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");
					sleep(2);

					//Game setup
					//initialize player's board

					//player 1
					initBoards(BoardPlayer1, player1ShipsLocations);
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|			Player 1 board is initialized							 |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");
					sleep(2);
					//player 2
					initBoards(BoardPlayer2, player2ShipsLocations);
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("|			Player 2 Board is initialized									 |\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");
					sleep(2);

					placeAllShipsRandomlly();

					//Choose who starts first
					int player = rand() % 2; //get random no 0 or 1
					int isHitting = 0;
					printf("\n");
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("| Player %d has selected to go first.								 |\n", player + 1);
					printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
					printf("\n");

					while (1)
					{
						switch (player)
						{
						case 0: //Player 1
							do
							{
								printf("\n");
								printf("|=-=-=-=-=-=-=-=-=-=---|\n");
								printf("| Player 2 GAME BOARD  |\n");
								printf("|=-=-=-=-=-=-=-=-=-=-=-|\n");
								printf("\n");
								printBoard(BoardPlayer2);
								player1Points = getInput();
								player1Gamestatus = playStatus(player2ShipsLocations, player1Points);
								if (player1Gamestatus == 1) //HIT
								{

									BoardPlayer2[player1Points.x][player1Points.y] = HIT;
									shipCounterPlayer2--;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 2 Ship was HIT by Player 1	 Remaining: %d Box					 |\n", shipCounterPlayer2);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 2 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer2);
									isHitting = 1;

									if (shipCounterPlayer2 == 0)
									{
										printf("\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("| 				All Player 2 Ship was HIT by Player 1				 |\n");
										printf("| 							SUNK									 |\n");
										printf("| 				  			GameOver								 |\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("\n");
										isHitting = 0;
										exit(1);
									}
								}
								else if (player1Gamestatus == 2) //MISS
								{
									BoardPlayer2[player1Points.x][player1Points.y] = MISS;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 2 Ship was MISSED 	 Remaining: %d BOX				 		 |\n", shipCounterPlayer2);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 2 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer2);
									isHitting = 0;
								}
								else if (player1Gamestatus == 3)
								{
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| You played in your previous position, Play again!!!				 |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									isHitting = 1;
								}
							} while (isHitting == 1);
							player = 1;
							break;
						case 1: //Player2
							do
							{
								printf("\n");
								printf("|=-=-=-=-=-=-=-=-=-=---|\n");
								printf("| Player 1 GAME BOARD  |\n");
								printf("|=-=-=-=-=-=-=-=-=-=-=-|\n");
								printf("\n");
								printBoard(BoardPlayer1);
								player2Points = getInput();
								player2GameStatus = playStatus(player1ShipsLocations, player2Points);
								if (player2GameStatus == 1) //HIT
								{

									BoardPlayer1[player2Points.x][player2Points.y] = HIT;
									shipCounterPlayer1--;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 1 Ship was HIT by Player 2	 Bal: %d ships					 |\n", shipCounterPlayer1);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 1 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer1);
									isHitting = 1;

									if (shipCounterPlayer1 == 0)
									{
										printf("\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("| 				All Player 1 Ship was HIT by Player 2				 |\n");
										printf("| 							SUNK									 |\n");
										printf("| 				  			GAME OVER								 |\n");
										printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
										printf("\n");
										isHitting = 0;
										exit(1);
									}
								}
								else if (player2GameStatus == 2) //MISS
								{
									BoardPlayer1[player2Points.x][player2Points.y] = MISS;
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| Player 1 Ship was MISSED by Player 2	 Bal: %d ships				 |\n", shipCounterPlayer1);
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| UPDATED Player 1 GAME BOARD    |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printBoard(BoardPlayer1);
									isHitting = 0;
								}
								else if (player2GameStatus == 3)
								{
									printf("\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("| You played in your previous position, Play again!!!				 |\n");
									printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
									printf("\n");
									isHitting = 1;
								}
							} while (isHitting == 1);
							player = 0;

						default:
							break;
						}
					}
					run1 = 1;
					break; //Player 2 End
				default:
					run1 = 0;
					break;
				}

			} while (run1 == 0);
			run = 0;
			break;
		case 2:
			printf("+===================================================================================|\n");
			printf("|                                        PLAYER INSTRUCTION                         |\n");
			printf("+-----------------------------------------------------------------------------------|\n");
			printf("|     1. The game is played in turn                                                 |\n");
			printf("|     2. Each player has Total: 10 Ships.                                           |\n");
			printf("|     3. The ships are placed as follow:                                            |\n");
			printf("|                            ___________________________                            |\n");
			printf("|                            | ==> 4 ships over 2 boxes|                            |\n");
			printf("|                            | ==> 3 ships over 3 boxes|                            |\n");
			printf("|                            | ==> 2 ships over 4 boxes|                            |\n");
			printf("|                            | ==> 1 ships over 5 boxes|                            |\n");
			printf("|                            |_________________________|                            |\n");
			printf("|                                                                                   |\n");
			printf("|     4. The ships are either placed horizontally                                   |\n");
			printf("|        or vertically                                                              |\n");
			printf("|     5. If a player hit a piece of ship, the player will guess again               |\n");
			printf("|     6. If all piece of a ship is foundm the player says \"sunk\"                  |\n");
			printf("|     7. The gameboard is made of 10X10 boxes                                       |\n");
			printf("|     8. The horizonal axis are identified with numbers 1 - 10                      |\n");
			printf("|     9. The vertical axis are identified with A - J                                |\n");
			printf("|     10. Each player predicts the opponnet ship position by naming a field,        |\n");
			printf("|         This result from the crosing points e.g A5                                |\n");
			printf("|     11. The game is played untill one of the two players have found               |\n");
			printf("|         and sunk all the opponnet ships.                                          |\n");
			printf("|     12. The game is made up of two modes : One player with computer and 2 Players |\n");
			printf("|     13. The game conisists of two difficulty level, Easy and Hard                 |\n");
			printf("+===================================================================================|\n");
			printf("\n");
			run = 0;
			break;
		default:
			run = 0;
			break;
		}
	} while (run == 0);

	return 0;
}
