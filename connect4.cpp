#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
//declerations for checkState
int checkVertP(int arr[6][7]);
int checkHorP(int arr[6][7]);
int checkDiagP(int arr[6][7]);
int checkVertR(int arr[6][7]);
int checkHorR(int arr[6][7]);
int checkDiagR(int arr[6][7]);

void printBoard(int arr[6][7]) {
	for (int r = 0; r < 6; r++) // print the board
	{
		for (int c = 0; c < 7; c++)
		{
			cout << arr[r][c];
		}
		cout << '\n';
	}
	cout << endl << endl;
}
void fill(int arr[6][7]) {
	for (int r = 0; r < 6; r++) //initialize array
	{
		for (int c = 0; c < 7; c++)
		{
			arr[r][c] = 0;
		}
	}
}
int playerMoveCheck(int col, int arr[6][7])
{
	int flagOuter = 0;
	if (arr[5][col] == 0) 
	{
		flagOuter = 1;
	}
	else
	{
		int flag = 0;
		int r = 4;
		while (flag == 0 && r >= 0)
		{
			if (arr[r][col] == 0)
			{
				flagOuter = 1;
				flag = 1;
			}
			r--;
		}
		if (flag == 0)
		{
			
			flagOuter = 0;
		}
	}
	return flagOuter;
	//printBoard(arr);
	cout << endl;
}
void playerMove(int col, int arr[6][7]) {
	//int flagTemp = 0;
	
	if (arr[5][col] == 0) {
		arr[5][col] = 1;
		cout << "Move made" << endl;
	}
	else
	{
		int flag = 0;
		int r = 4;
		while (flag == 0 && r >=0)
		{
			if (arr[r][col] == 0)
			{
				arr[r][col] = 1;
				cout << "Move made" << endl;
				flag = 1;
				//flagTemp = 1;
			}
			r--;
		}
		if (flag == 0)
		{
			cout << "Column full, pick again" << endl;
			//flagTemp = 0;
		}
	}
	//printBoard(arr);
	cout << endl;
	//return flagTemp;
	//return 0 if no move made, 1 if successful
}
void playerMove2(int col, int arr[6][7])
{
	if (arr[5][col] == 0) {
		arr[5][col] = 2;
		cout << "Move made" << endl;
	}
	else
	{
		int flag = 0;
		int r = 4;
		while (flag == 0 && r >= 0)
		{
			if (arr[r][col] == 0)
			{
				arr[r][col] = 2;
				cout << "Move made" << endl;
				flag = 1;
				//flagTemp = 1;
			}
			r--;
		}
		if (flag == 0)
		{
			cout << "Column full, pick again" << endl;
			//flagTemp = 0;
		}
	}
	//printBoard(arr);
	cout << endl;
}
int randomMoveCheck(int arr[6][7])
{
	int flagtemp = 0;
	int col = rand() % 7;

	int flag = 0;
	int r = 5;
	while (flag == 0 && r >= 0)
	{
		if (arr[r][col] == 0)
		{
			flagtemp = 1;
			//cout << "Move made" << endl;
			flag = 1;
			//flagtemp = 1;
		}
		r--;
	}
	if (flag == 0)
	{
		//cout << "No move made" << endl;
		flagtemp = 0;
	}
	//printBoard(arr);
	cout << endl;
	//return 0 if no move made, 1 if successful
	return flagtemp;
}
void randomMove(int arr[6][7]) {
	//int flagtemp = 0;
	int col =  rand() % 7;
	
		int flag = 0;
		int r = 5;
		while (flag == 0 && r >= 0)
		{
			if (arr[r][col] == 0)
			{
				arr[r][col] = 2;
				cout << "Move made" << endl;
				flag = 1;
				//flagtemp = 1;
			}
			r--;
		}
		if (flag == 0)
		{
			cout << "No move made" << endl;
			//flagtemp = 0;
		}
	//printBoard(arr);
	cout << endl;
	//return 0 if no move made, 1 if successful
	//return flagtemp;
}
void randomMove2(int arr[6][7])
{
	int col = rand() % 7;

	int flag = 0;
	int r = 5;
	while (flag == 0 && r >= 0)
	{
		if (arr[r][col] == 0)
		{
			arr[r][col] = 1;
			cout << "Move made" << endl;
			flag = 1;
			//flagtemp = 1;
		}
		r--;
	}
	if (flag == 0)
	{
		cout << "No move made" << endl;
		//flagtemp = 0;
	}
	//printBoard(arr);
	cout << endl;
	//return 0 if no move made, 1 if successful
	//return flagtemp;
}
//full game chack (check for player and random wins) return 0 if no win, 1 if player win, 2 if AI win
int checkState(int arr[6][7]) {
	int flag = 0;
	if (checkVertP(arr) == 1 || checkHorP(arr) == 1 || checkDiagP(arr) == 1)
		flag = 1; // player wins if c4 is found
	if (checkVertR(arr) == 2 || checkHorR(arr) == 2 || checkDiagR(arr) == 2)
		flag = 2; // random wins if c4 is found
	return flag;
}
//player gamestate win checkers (vertical, horizontal, and diagonal wins) return 1 for win
int checkVertP(int arr[6][7]) { // return 1 if vertical win is found
	int cnt = 0;
	int flag = 0;
	for (int c = 0; c < 7; c++) {
		for (int r = 0; r < 6; r++) {
			if (arr[r][c] == 1)
			{
				cnt++;
				if (cnt >= 4)
					flag = 1; // gamewin
			}
			else
				cnt = 0;
		}
	}
	return flag;
}
int checkHorP(int arr[6][7]) { // return 1 if vertical win is found
	int cnt = 0;
	int flag = 0;
	for (int r = 0; r < 6; r++) {
		for (int c = 0; c < 7; c++) {
			if (arr[r][c] == 1)
			{
				cnt++;
				if (cnt >= 4)
					flag = 1; // gamewin
			}
			else
				cnt = 0;
		}
	}
	return flag;
}
int checkDiagP(int arr[6][7]) {
	//up right diag win
	int flag = 0;
	for (int r = 3; r < 6; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (arr[r][c] == 1 && arr[r-1][c+1] == 1 && arr[r - 2][c + 2] == 1 && arr[r - 3][c + 3] == 1) // check if there is a updiag win
			{
				flag = 1;
			}
		}
	}
	//down right diag win
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (arr[r][c] == 1 && arr[r + 1][c + 1] == 1 && arr[r + 2][c + 2] == 1 && arr[r + 3][c + 3] == 1) // check if there is a updiag win
			{
				flag = 1;
			}
		}
	}
	//up left diag win
	for (int r = 3; r < 6; r++)
	{
		for (int c = 3; c < 7; c++)
		{
			if (arr[r][c] == 1 && arr[r - 1][c - 1] == 1 && arr[r - 2][c - 2] == 1 && arr[r - 3][c - 3] == 1) // check if there is a updiag win
			{
				flag = 1;
			}
		}
	}
	// down left diag win
	for (int r = 0; r < 3; r++)
	{
		for (int c = 3; c < 7; c++)
		{
			if (arr[r][c] == 1 && arr[r + 1][c - 1] == 1 && arr[r + 2][c - 2] == 1 && arr[r + 3][c - 3] == 1) // check if there is a updiag win
			{
				flag = 1;
			}
		}
	}
	return flag;
}
//random gamestate win checkers, returns a 2 for win
int checkVertR(int arr[6][7]) { 
	int cnt = 0;
	int flag = 0;
	for (int c = 0; c < 7; c++) {
		for (int r = 0; r < 6; r++) {
			if (arr[r][c] == 2)
			{
				cnt++;
				if (cnt >= 4)
					flag = 2; // gamewin
			}
			else
				cnt = 0;
		}
	}
	return flag;
}
int checkHorR(int arr[6][7]) { // return 1 if vertical win is found
	int cnt = 0;
	int flag = 0;
	for (int r = 0; r < 6; r++) {
		for (int c = 0; c < 7; c++) {
			if (arr[r][c] == 2)
			{
				cnt++;
				if (cnt >= 4)
					flag = 2; // gamewin
			}
			else
				cnt = 0;
		}
	}
	return flag;
}
int checkDiagR(int arr[6][7]) {
	//up right diag win
	int flag = 0;
	for (int r = 3; r < 6; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (arr[r][c] == 2 && arr[r - 1][c + 1] == 2 && arr[r - 2][c + 2] == 2 && arr[r - 3][c + 3] == 2) // check if there is a updiag win
			{
				flag = 2;
			}
		}
	}
	//down right diag win
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (arr[r][c] == 2 && arr[r + 1][c + 1] == 2 && arr[r + 2][c + 2] == 2 && arr[r + 3][c + 3] == 2) // check if there is a updiag win
			{
				flag = 2;
			}
		}
	}
	//up left diag win
	for (int r = 3; r < 6; r++)
	{
		for (int c = 3; c < 7; c++)
		{
			if (arr[r][c] == 2 && arr[r - 1][c - 1] == 2 && arr[r - 2][c - 2] == 2 && arr[r - 3][c - 3] == 2) // check if there is a updiag win
			{
				flag = 2;
			}
		}
	}
	// down left diag win
	for (int r = 0; r < 3; r++)
	{
		for (int c = 3; c < 7; c++)
		{
			if (arr[r][c] == 2 && arr[r + 1][c - 1] == 2 && arr[r + 2][c - 2] == 2 && arr[r + 3][c - 3] == 2) // check if there is a updiag win
			{
				flag = 2;
			}
		}
	}
	return flag;
}
int checkScore(int arr[6][7])
{
	return 0;
}


int main(){
	srand((unsigned)time(0));
	int board[6][7];
	fill(board);
	
	int flag = 0;
	while (flag == 0)
	{
		int type;// = 0;
		cout << "Choose game type (0 for pvp, 1 for pvr, and 2 for rvr)";
		cin >> type;
		switch (type) {
		case 0:
		{
			while (checkState(board) == 0)
			{
				int choose;
				cout << "P1 choose col: ";
				cin >> choose;
				if (playerMoveCheck(choose, board) == 1) // if move can be made successfully, make it and print
				{
					playerMove(choose, board);
					printBoard(board);
				}
				else
				{
					while (playerMoveCheck(choose, board) == 0)
					{
						cout << "Col full, choose new col: ";
						cin >> choose;
						if (playerMoveCheck(choose, board) == 1) // if move can be made successfully, make it and print
						{
							playerMove(choose, board);
							printBoard(board);
						}
					}
				}
				if (checkState(board) != 0)
					break;
				int choose2;
				cout << "P2 choose col: ";
				cin >> choose2;
				if (playerMoveCheck(choose2, board) == 1) // if move can be made successfully, make it and print
				{
					playerMove2(choose2, board);
					printBoard(board);
				}
				else
				{
					while (playerMoveCheck(choose2, board) == 0)
					{
						cout << "Col full, choose new col: ";
						cin >> choose2;
						if (playerMoveCheck(choose2, board) == 1) // if move can be made successfully, make it and print
						{
							playerMove2(choose2, board);
							printBoard(board);
						}
					}
				}
			}
			if (checkState(board) == 1)
				cout << "Player 1 wins!" << endl;
			else
				cout << "Player 2 wins!" << endl;
			break;
		}
		case 1:

			while (checkState(board) == 0)
			{
				int choose;
				cout << "Choose col: ";
				cin >> choose;
				if (playerMoveCheck(choose, board) == 1) // if move can be made successfully, make it and print
				{
					playerMove(choose, board);
					printBoard(board);
				}
				else 
				{
					while (playerMoveCheck(choose, board) == 0)
					{
						cout << "Col full, choose new col: ";
						cin >> choose;
						if (playerMoveCheck(choose, board) == 1) // if move can be made successfully, make it and print
						{
							playerMove(choose, board);
							printBoard(board);
						}
					}
				}
				if (checkState(board) != 0)
					break;
				cout << "Random move: ";
				if (randomMoveCheck(board) == 1)
				{
					randomMove(board);
					printBoard(board);
				}
				else
				{
					while (randomMoveCheck(board) == 0)
					{
						if (randomMoveCheck(board) == 1) // if move can be made successfully, make it and print
						{
							randomMove(board);
							printBoard(board);
						}
					}
				}
			}
			if (checkState(board) == 1)
				cout << "Player 1 wins!" << endl;
			else
				cout << "random Player wins!" << endl;
			break;
		case 2: // rvr

			while (checkState(board) == 0)
			{
				cout << "Random move (2): ";
				if (randomMoveCheck(board) == 1) // checks for move by player 2
				{
					randomMove(board);
					printBoard(board);
				}
				else
				{
					while (randomMoveCheck(board) == 0)
					{
						if (randomMoveCheck(board) == 1) // if move can be made successfully, make it and print
						{
							randomMove(board);
							printBoard(board);
						}
					}
				}
				if (checkState(board) != 0)
					break;
				cout << "Random (1) move: "; 
				if (randomMoveCheck(board) == 1) // checks for player 1
				{
					randomMove2(board);
					printBoard(board);
				}
				else
				{
					while (randomMoveCheck(board) == 0)
					{
						if (randomMoveCheck(board) == 1) // if move can be made successfully, make it and print
						{
							randomMove2(board);
							printBoard(board);
						}
					}
				}
			}

			if (checkState(board) == 1)
				cout << "Random (1) wins!" << endl;
			else
				cout << "Random (2) wins!" << endl;
			break;
			
		}
		cout << "Play again? (1 to quit, 0 to play again): ";
		cin >> flag;
		fill(board);
	}

	
	return 0; 
}
