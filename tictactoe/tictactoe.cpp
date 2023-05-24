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
  //  int row = 3, col = 3;
    int u1Row = 0, u2Row = 0, u1Col = 0, u2Col = 0;
    char currentPlayer = 'X';
    //grid

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

    //Asking user
    cout << "User X select Enter row and column ";
    cin >> u1Row >> u1Col;
    grid[u1Row][u1Col] = 'X';
    printArray(grid, 3, 3);
    cout << "User O select Enter row and column ";
    cin >> u2Row >> u2Col;
    grid[u2Row][u2Col] = 'O';
    printArray(grid, 3, 3);
    //checkRow(grid, currentPlayer, 3) || checkCol(grid, currentPlayer, 3)
    bool gameOn = true;
    while (gameOn) {
        cout << "User X select Enter row and column ";
        cin >> u1Row >> u1Col;
        grid[u1Row][u1Col] = 'X';
        if (checkDiag(grid, currentPlayer, 3)) {
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
        cout << "User O select Enter row and column ";
        cin >> u2Row >> u2Col;
        grid[u2Row][u2Col] = 'O';
        printArray(grid, 3, 3);

        if (checkDiag(grid, currentPlayer, 3)) {
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
    //testing 



}

void printArray(char** arr, int rows, int col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}
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
    char answer[3] = {0,0,0};
    for (int i = 0; i < size; i++) {
        answer[i] = arr[i][i];
    }
    if (answer[0] == a && answer[1] == a && answer[2] == a)
        return true;
    return false;
}

bool checkWin(char** arr, char user, int row, int col) {
    if ((checkCol(arr, user, col) || checkRow(arr, user, row) || checkDiag(arr, user, row))) {
        return true;
    }
    return false;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file 
