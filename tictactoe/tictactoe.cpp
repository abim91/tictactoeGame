// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printArray(char** arr, int rows, int col);
bool checkCol(char** arr, char a, int col);
bool checkRow(char** arr, char a, int row);
bool checkDiag(char** arr, char a, int size);
bool checkWin(char** arr, char user, int row, int col);

int main()
{
    // variables 
    int u1Row = 0, u2Row = 0, u1Col = 0, u2Col = 0;
    char currentPlayer = 'X';
   
    //Create Dynamic Arrays
    char** grid = new char* [3];
    for (int i = 0; i < 3; i++) {
        grid[i] = new char[3];
    }
    grid[0][0] = 'i';
    grid[0][1] = 'i';
    grid[0][2] = 'i';
    grid[1][0] = 'i';
    grid[1][1] = 'i';
    grid[1][2] = 'i';
    grid[2][0] = 'i';
    grid[2][1] = 'i';
    grid[2][2] = 'i';

    
 
  //Starts the actual game
    bool gameOn = true;
    while (gameOn) {
        cout << "User X select Enter row and column ";
        cin >> u1Row >> u1Col;
        //Make sures the user do not write over previously selected block
        while (grid[u1Row][u1Col] == 'O') {
            cout << "This block is taken, choose another one" << endl;
            cout << "User X select Enter row and column ";
            cin >> u1Row >> u1Col;
        }
        grid[u1Row][u1Col] = 'X';
        printArray(grid, 3, 3);
        if (checkWin(grid, currentPlayer, 3, 3)) {
            cout << "game is over " << currentPlayer << " won" << endl;
            gameOn = false;

            
        }
        else {
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            }
            else {
                currentPlayer = 'X';
            }

            cout << "User O select Enter row and column ";
            cin >> u2Row >> u2Col;
            //Make sures the user do not write over previously selected block
            while (grid[u2Row][u2Col] == 'X') {
                cout << "This block is taken, choose another one" << endl;
                cout << "User O Enter row and column ";
                cin >> u2Row >> u2Col;
            }

            grid[u2Row][u2Col] = 'O';
            printArray(grid, 3, 3);

            if (checkWin(grid, currentPlayer, 3, 3)) {
                gameOn = false;
                cout << "game is over " << currentPlayer << " won" << endl;
            }
            else {
                if (currentPlayer == 'X') {
                    currentPlayer = 'O';
                }
                else {
                    currentPlayer = 'X';
                }
            }
        }
        

    }
    



}

void printArray(char** arr, int rows, int col) {
    //prints the whole 2-d array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}
// helper functions to check if anyone has won
bool checkCol(char** arr, char a, int col) {
    int row = col;
    for (int i = 0; i < col; i++) {
        char answer[3] = { 0,0,0 };
        for (int j = 0; j < row; j++) {
            answer[j] = arr[j][i];
        }
        if (answer[0] == a && answer[1] == a && answer[2] == a)
            return true;
    }
    return false;
}
bool checkRow(char** arr, char a, int row) {
    int col = row;
    for (int i = 0; i < row; i++) {
        char answer[3] = { 0,0,0 };
        for (int j = 0; j < col; j++) {
            answer[j] = arr[i][j];
        }
        if (answer[0] == a && answer[1] == a && answer[2] == a)
            return true;
    }
    return false;
}
bool checkDiag(char** arr, char a, int size) {
    char answerMD[3] = {0,0,0};
    char answerSD[3] = { 0,0,0 };
    // checking the main diagonal
    for (int i = 0; i < size; i++) {
        answerMD[i] = arr[i][i];
        answerSD[i] = arr[i][size-(i+1)];
    }
    if ((answerMD[0] == a && answerMD[1] == a && answerMD[2] == a) || (answerSD[0] == a && answerSD[1] == a && answerSD[2] == a))
        return true;

    return false;
}
// main function to judge who won
bool checkWin(char** arr, char user, int row, int col) {
    if ((checkCol(arr, user, col) || checkRow(arr, user, row) || checkDiag(arr, user, row))) {
        return true;
    }
    return false;

}
