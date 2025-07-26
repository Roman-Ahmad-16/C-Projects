#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <sstream>
#include <stdlib.h>

using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char sign = 'X';
int player = 1;

void drawBoard() {
    cleardevice();
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 3);

    // Draw grid
    line(200, 0, 200, 600);
    line(400, 0, 400, 600);
    line(0, 200, 600, 200);
    line(0, 400, 600, 400);
}

void drawXO(int row, int col, char symbol) {
    int x = col * 200 + 100;
    int y = row * 200 + 100;

    if (symbol == 'X') {
        setcolor(RED);
        line(x - 50, y - 50, x + 50, y + 50);
        line(x - 50, y + 50, x + 50, y - 50);
    } else {
        setcolor(BLUE);
        circle(x, y, 50);
    }
}

bool placeMarker(int row, int col) {
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = sign;
        drawXO(row, col, sign);
        return true;
    }
    return false;
}

bool winner() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

bool boardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    sign = (sign == 'X') ? 'O' : 'X';
    player = (player == 1) ? 2 : 1;
}

void showMessage(string msg) {
    setcolor(YELLOW);
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(50, 610, (char*)msg.c_str()); // graphical message
}

void playGame() {
    drawBoard();

    while (true) {
        int x, y, row, col;

        stringstream ss;
        ss << "Player " << player << " (" << sign << ")'s Turn";
        showMessage(ss.str());

        while (true) {
            if (ismouseclick(WM_LBUTTONDOWN)) {
                getmouseclick(WM_LBUTTONDOWN, x, y);
                row = y / 200;
                col = x / 200;

                if (placeMarker(row, col))
                    break;
            }
        }

        if (winner()) {
            stringstream winMsg;
            winMsg << "Player " << player << " Wins!";
            showMessage(winMsg.str());

            // Print to console
            cout << " Player " << player << " (" << sign << ") wins the game!" << endl;

            delay(3000);
            closegraph();
            exit(0);
        }

        if (boardFull()) {
            showMessage("It's a Draw!");
            cout << "?? The game is a draw!" << endl;

            delay(3000);
            closegraph();
            exit(0);
        }

        switchPlayer();
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    playGame();

    return 0;
}

