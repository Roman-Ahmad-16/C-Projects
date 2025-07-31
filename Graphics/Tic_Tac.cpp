#include <graphics.h>
#include <iostream>
#include <sstream>  
using namespace std;

char board[3][3];
int player = 1;
int score1 = 0, score2 = 0;
bool vsAI = false;

void drawBoard() {
	
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 5);
    
    for (int i = 1; i < 3; ++i) {
        line(0, i * 200, 600, i * 200);
        line(i * 200, 0, i * 200, 600);
    }

    settextstyle(BOLD_FONT, HORIZ_DIR, 9);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') {
                setcolor(LIGHTRED);
                outtextxy(j * 200 + 65, i * 200 + 60, (char*)"X");
            } else if (board[i][j] == 'O') {
                setcolor(LIGHTCYAN);
                outtextxy(j * 200 + 65, i * 200 + 60, (char*)"O");
            }
        }
    }

    setcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    
    ostringstream oss;

    oss << "Player 1: " << score1;
    outtextxy(30, 610, (char*)oss.str().c_str());

    oss.str("");
    oss.clear(); 

    if (vsAI)
        oss << "AI: " << score2;
    else
        oss << "Player 2: " << score2;

    outtextxy(360, 610, (char*)oss.str().c_str());
}

void drawMenu() {
    setbkcolor(BLACK);
    cleardevice();

    settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    setcolor(WHITE);
    outtextxy(180, 180, (char*)"Choose Mode:");

    setfillstyle(SOLID_FILL, GREEN);
    bar(180, 270, 520, 340);
    setcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(210, 290, (char*)"Player vs Player");

    setfillstyle(SOLID_FILL, BLUE);
    bar(180, 370, 520, 440);
    setcolor(WHITE);
    outtextxy(240, 390, (char*)"Player vs AI");
}

bool checkButtonClick(int x, int y, int x1, int y1, int x2, int y2) {
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

void resetBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

int winner() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return true;
    return false;
}

int minimax(bool isMax) {
    if (winner()) return isMax ? -1 : 1;
    if (!isMovesLeft()) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    best = max(best, minimax(false));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    best = min(best, minimax(true));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void bestAIMove() {
    int bestVal = -1000;
    int bestRow = -1, bestCol = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int moveVal = minimax(false);
                board[i][j] = ' ';
                if (moveVal > bestVal) {
                    bestRow = i;
                    bestCol = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    if (bestRow != -1 && bestCol != -1) {
        board[bestRow][bestCol] = 'O';
        player = 1;
    }
}

void placeMarker(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = (player == 1 ? 'X' : 'O');
    }
}

void playGame() {
    int x, y, row, col;
    bool gameRunning = true;
    while (gameRunning) {
        cleardevice();
        drawBoard();

        if (winner()) {
            if (player == 1) 
				score2++; 
			else 
				score1++;

            ostringstream oss;
            if (vsAI && player == 2)
                oss << "AI Wins!";
            else
                oss << "Player " << (player == 1 ? 2 : 1) << " Wins!";

            setcolor(YELLOW);
            settextstyle(BOLD_FONT, HORIZ_DIR, 3);
            outtextxy(200, 650, (char*)oss.str().c_str());

            delay(2000);
            resetBoard();
            player = 1;
            continue;
        }

        if (!isMovesLeft()) {
            setcolor(YELLOW);
            settextstyle(BOLD_FONT, HORIZ_DIR, 3);
            outtextxy(250, 650, (char*)"Draw!");
            delay(2000);
            resetBoard();
            player = 1;
            continue;
        }

        if (vsAI && player == 2) {
            delay(300);
            bestAIMove();
        } else {
            while (!ismouseclick(WM_LBUTTONDOWN)) delay(10);
            getmouseclick(WM_LBUTTONDOWN, x, y);
            row = y / 200;
            col = x / 200;
            if (row < 3 && col < 3 && board[row][col] == ' ') {
                placeMarker(row, col);
                player = (player == 1 ? 2 : 1);
            }
        }
    }
}

int main() {
    initwindow(600, 670, "Tic Tac Toe");
    drawMenu();

    int x, y;
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (checkButtonClick(x, y, 180, 270, 520, 340)) {
                vsAI = false;
                break;
            } else if (checkButtonClick(x, y, 180, 370, 520, 440)) {
                vsAI = true;
                break;
            }
        }
    }

    resetBoard();
    cleardevice();
    playGame();
    getch();
    closegraph();
    return 0;
}
