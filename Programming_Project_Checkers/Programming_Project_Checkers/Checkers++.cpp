/*
Computer Programing 1
Group Project
Bradley Trowbridge
This is a 2 player checkers game titled CHECKERS ++

*/
#include <iostream> //for normal i/o 

using namespace std; // for use of standrd ibrary space

//declaring initial board character array
char board[8][8] =
{
	{ ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b' },
	{ 'b', ' ', 'b', ' ', 'b', ' ', 'b', ' ' },
	{ ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ 'r', ' ', 'r', ' ', 'r', ' ', 'r', ' ' },
	{ ' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r' },
	{ 'r', ' ', 'r', ' ', 'r', ' ', 'r', ' ' },
};

//Declare global variables
char turn = 'B';                   //charachter representing player turn B or R
bool leap;                         //boolean for determine whether the player will leap
bool gameRunning = true;           //globaldetermines whether the game is running
int row1, row2, column1, column2;  //determines integers representing row and columns of checkers pieces


//Prototyping functions
void DisplayBoard();               //Displaying the board
void PlayerInput();				   //Player input 
bool CheckMove();                  //Determines whether move is legal or not
void Move();                       //Moves the piece
void DoLeap();					   //Leap function
void King();					   //"King's" the piece and applies new rules to move limit
void GameOver();				   //Ends the game


int main()
{
	//Text explaining the rules and contents of the game
	cout << "________CHECKERS++________" << endl;
	cout << "This is an interactive, 2-player checkers game." << endl;
	cout << "Player 1 [b]" << endl;
	cout << "Player 2 [r]\n" << endl;
	cout << "Program Perameters:" << endl;
	cout << "Player can perform multiple leaps." << endl;
	cout << "King pieces are represented by capital letters." << endl;
	cout << "Rows and columns are from 0 to 7" << endl;

	cout << "<------COLUMNS------>\n";
	cout << "^\n";
	cout << "|\n";
	cout << "|\n";
	cout << "|\n";
	cout << "ROWS\n";
	cout << "|\n";
	cout << "|\n";
	cout << "|\n";
	cout << "v\n\n";
	cout << "Please resize your console screen so that this line fits on the screen:" << endl;
	cout << "_____________________________________________________________________________________\n\n";
	cout << "Press enter to play...";
	cin.get();           //Prompts the user to press enter and begin the game

	//Continues the game while it is still running
	while (gameRunning)
	{
		DisplayBoard();  //prints the board for the player


		//lets player knows whose turn it is
		if (turn == 'B')
		{
			cout << "--Player 1 [B]--\n";
		}
		else if (turn == 'R')
		{
			cout << "--Player 2 [R]--\n";
		}

		//These are the turn phases
		PlayerInput();            //allows player input for move
		Move();                   //executes the movement
		King();					  //"Kings" appropriate pieces
		GameOver();				  //Checks for game over condition
	}

	//While game is not running determines which player wins based on whose turn it is
	if (turn == 'B')
	{
		cout << endl << endl << "Player 2 (Red]) wins!" << endl;
	}
	else if (turn == 'R')
	{
		cout << endl << endl << "Player 1 [Black] wins!" << endl;
	}

	cout << "GAME OVER!" << endl;
}

//This function prints out a virtual board with all of its pieces using the board array to fill the spaces
void DisplayBoard()
{
	cout << "==================================================================================\n\n\n\n";
	cout << "       0         1         2         3         4         5         6         7     \n";
	cout << "  _________________________________________________________________________________\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "0 |    " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << "    |    " << board[0][3] << "    |    " << board[0][4] << "    |    " << board[0][5] << "    |    " << board[0][6] << "    |    " << board[0][7] << "    |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "1 |    " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << "    |    " << board[1][3] << "    |    " << board[1][4] << "    |    " << board[1][5] << "    |    " << board[1][6] << "    |    " << board[1][7] << "    |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "2 |    " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << "    |    " << board[2][3] << "    |    " << board[2][4] << "    |    " << board[2][5] << "    |    " << board[2][6] << "    |    " << board[2][7] << "    |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "3 |    " << board[3][0] << "    |    " << board[3][1] << "    |    " << board[3][2] << "    |    " << board[3][3] << "    |    " << board[3][4] << "    |    " << board[3][5] << "    |    " << board[3][6] << "    |    " << board[3][7] << "    |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "4 |    " << board[4][0] << "    |    " << board[4][1] << "    |    " << board[4][2] << "    |    " << board[4][3] << "    |    " << board[4][4] << "    |    " << board[4][5] << "    |    " << board[4][6] << "    |    " << board[4][7] << "    |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "5 |    " << board[5][0] << "    |    " << board[5][1] << "    |    " << board[5][2] << "    |    " << board[5][3] << "    |    " << board[5][4] << "    |    " << board[5][5] << "    |    " << board[5][6] << "    |    " << board[5][7] << "    |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "6 |    " << board[6][0] << "    |    " << board[6][1] << "    |    " << board[6][2] << "    |    " << board[6][3] << "    |    " << board[6][4] << "    |    " << board[6][5] << "    |    " << board[6][6] << "    |    " << board[6][7] << "    |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "7 |    " << board[7][0] << "    |    " << board[7][1] << "    |    " << board[7][2] << "    |    " << board[7][3] << "    |    " << board[7][4] << "    |    " << board[7][5] << "    |    " << board[7][6] << "    |    " << board[7][7] << "    |\n";
	cout << "  |         |         |         |         |         |         |         |         |\n";
	cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
}

//this function controls the player input
void PlayerInput()
{


	//player choses which piece to move
	cout << "Move piece" << endl;
	cout << "Row: ";
	cin >> row1;           //player inputs for row
	cout << "Column: ";
	cin >> column1;		   //player input for column

	//if input is invalid...
	while ( row1 < 0 || row1 > 7 || column1 < 0 || column1 > 7)
	{
		cout << "Sorry! that is not a valid input. Please use only numbers from 0 to 7" << endl;
		cout << "Move piece" << endl;
		cout << "Row: ";
		cin >> row1;
		cout << "Column: ";
		cin >> column1;
	}

	//player choses where to move to
	cout << "To box" << endl;
	cout << "Row: ";
	cin >> row2;
	cout << "Column: ";
	cin >> column2;

	//if input is invalid...
	while (row1 < 0 || row1 > 7 || column1 < 0 || column1 > 7)
	{
		cout << "Sorry! that is not a valid input. Please use only numbers from 0 to 7" << endl;
		cout << "To box" << endl;
		cout << "Row: ";
		cin >> row2;
		cout << "Column: ";
		cin >> column2;
	}

	//Uses CheckMove function to determine if move is legal
	while (CheckMove() == false)
	{
		cout << "Illegal Move!" << endl;
		PlayerInput(); //recall player input
	}
}

//Checks rules for moving pieces
bool CheckMove()
{
	//rules are as such...
	//non king pieces cannot move backward depending on whose turn it is and current position
	if (board[row1][column1] != 'B' && board[row1][column1] != 'R')
	{
		if ((turn == 'B' && row2 < row1) || (turn == 'R' && row2 > row1))
		{
			leap = false; //no leap
			return false; //return false
		}
	}

	//pieces can only move to empty spaces
	if (board[row2][column2] != ' ')
	{
		leap = false; //no leap
		return false; //return false
	}

	//player must move from a space where a piece is present
	if (board[row1][column1] == ' ')
	{
		leap = false; //no leap 
		return false; //return false
	}

	//pieces cannot move horizontally or vertically
	if (column1 == column2 || row1 == row2)
	{
		leap = false;
		return false;
	}

	//pieces cannot move more than one column or row
	if ((column2 > column1 + 1 || column2 < column1 - 1) && (row2 == row1 + 1 || row2 == row1 - 1))
	{
		leap = false;
		return false;
	}

	//If the piece is leaping...
	if (row2 > row1 + 1 || row2 < row1 - 1)
	{
		//it cannot leap too far
		if (row2 > row1 + 2 || row2 < row1 - 2)
		{
			leap = false;
			return false;
		}

		//it must leap two columns away
		if (column2 != column1 + 2 && column2 != column1 - 2)
		{
			leap = false;
			return false;
		}

		//makes sure that they are leaping over a piece (checks four dimensions)
		if (row2 > row1 && column2 > column1)
		{
			if (board[row2 - 1][column2 - 1] == ' ')
			{
				leap = false;
				return false;
			}
		}
		else if (row2 > row1 && column2 < column1)
		{
			if (board[row2 - 1][column2 + 1] == ' ')
			{
				leap = false;
				return false;
			}
		}
		else if (row2 < row1 && column2 > column1)
		{
			if (board[row2 + 1][column2 - 1] == ' ')
			{
				leap = false;
				return false;
			}
		}
		else if (row2 < row1 && column2 < column1)
		{
			if (board[row2 + 1][column2 + 1] == ' ')
			{
				leap = false;
				return false;
			}
		}
		//return legal leap
		leap = true;
		return true;
	}
	//return legal non-leap
	leap = false;
	return true;
}

//function that moves the piece and changes turn
void Move()
{
	//boolean default piece to non-king
	bool kingPiece = false;

	//checks piece to determine if the piece is king
	if (board[row1][column1] == 'B' || board[row1][column1] == 'R')
	{
		kingPiece = true;
	}

	//sets previous position to blank or ''
	board[row1][column1] = ' ';

	//if turn is B or player 1...
	if (turn == 'B')
	{
		//if piece is not king, places normal piece
		if (kingPiece == false)
		{

			board[row2][column2] = 'b';
		}
		//if piece is king, places king piece
		else if (kingPiece == true)
		{
			board[row2][column2] = 'B';
		}

		//changes turn to R or player 2
		turn = 'R';
	}

	//same case for R or player 2, determines which piece to place and changes new location to that piece
	else if (turn == 'R')
	{
		if (kingPiece == false)
		{
			board[row2][column2] = 'r';
		}
		else if (kingPiece == true)
		{
			board[row2][column2] = 'R';
		}

		//changes tun to B or player 1
		turn = 'B';
	}

	//if the movement is a leap then it executes the leap function
	if (leap == true)
	{
		DoLeap();
	}
}

//function operating the leap maneuver of the game
void DoLeap()
{
	//leap choice
	char answer;

	//removes the checker piece that was leaped (4 dimensions)
	if (row2 > row1 && column2 > column1)
	{
		board[row2 - 1][column2 - 1] = ' ';
	}
	else if (row2 > row1 && column2 < column1)
	{
		board[row2 - 1][column2 + 1] = ' ';
	}
	else if (row2 < row1 && column2 > column1)
	{
		board[row2 + 1][column2 - 1] = ' ';
	}
	else if (row2 < row1 && column2 < column1)
	{
		board[row2 + 1][column2 + 1] = ' ';
	}

	DisplayBoard();			//prints the board after the changes

	//asks the user if it wants to leap again
	do
	{
		cout << "You successfully leaped. Do you want to leap again if possible? (y/n) (Note: only legal leaps allowed, any wrong move will skip your turn): ";
		cin >> answer;
	} while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

	if (answer == 'y' || answer == 'Y')
	{
		//sets new location to current
		row1 = row2;
		column1 = column2;

		//asks user where to leap to next
		cout << "leap piece: row: " << row1 << ", column: " << column1 << endl;		//piece selected
		cout << "To box" << endl;
		cout << "row: ";
		cin >> row2;
		cout << "column: ";
		cin >> column2;

		//for incorrect input
		while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)
		{
			cout << "Sorry! that is not a valid input. Please use only numbers from 0 to 7" << endl;
			cout << "To box" << endl;
			cout << "Row: ";
			cin >> row2;
			cout << "Column: ";
			cin >> column2;
		}

		//switches turns after leap
		if (turn == 'B')
		{
			turn = 'R';
		}
		else if (turn == 'R')
		{
			turn = 'B';
		}

		//checks to see if move is legal
		CheckMove();

		//output for when move is illegal 
		if (leap == false)
		{
			cout << "Sorry! That is not a valid leap" << endl;
	
				//switches turn due to illegal leap
				if (turn == 'B')
				{
					turn = 'R';
				}
				else if (turn == 'R')
				{
					turn = 'B';
				}
		}
		//executes leap move and changes the pieces
		else if (leap == true)
		{
			Move();
		}
	}
}

//function that kings pieces
void King()
{
	//checks position of all pieces for front and backrow for opponents piece and then switches them for a king piece
	for (int i = 0; i < 8; i++)
	{
		if (board[0][i] == 'r')
		{
			board[0][i] = 'R';
		}

		if (board[7][i] == 'b')
		{
			board[7][i] = 'B';
		}
	}
}

//function that determines when the game ends
void GameOver()
{
	int counter = 0;

	//counts the non-empty spaces on the board for pieces
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != ' ')
			{
				counter++;
			}
		}
	}

	//changes global variable gameRunning to false when the game end condition  is met
	if (counter > 1)
	{
		gameRunning = true;
	}
	else if (counter == 1)
	{
		gameRunning = false;
	}
}