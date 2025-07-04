#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

// Function to display the Tic-Tac-Toe board
void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

// Function to mark the board with the player's move
bool placeMarker(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false; // Position already taken
    }
}

// Function to check for a win condition
bool checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    return false;
}

// Function to check if the board is full (draw condition)
bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch the turn to the next player
void switchPlayer() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

// Function to start the game
void playGame() {
    int position;
    displayBoard();

    while (true) {
        cout << "Player " << currentPlayer << " (" << currentMarker << "), enter your position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9 || !placeMarker(position)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        displayBoard();

        if (checkWinner()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull()) {
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    
    while (currentMarker != 'X' && currentMarker != 'O') {
        cout << "Invalid choice! Please select X or O: ";
        cin >> currentMarker;
    }

    currentPlayer = 1;
    playGame();

    return 0;
}

