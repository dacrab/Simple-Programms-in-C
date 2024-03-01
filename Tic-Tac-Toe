#include <stdio.h>

char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void displayBoard() {
    printf("  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-') {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')) {
        return 1;
    }
    // Check for draw
    int draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                draw = 0;
                break;
            }
        }
        if (!draw) break;
    }
    if (draw) return 2;
    return 0;
}

int main() {
    initializeBoard();
    int currentPlayer = 1, row, col, result;

    while (1) {
        displayBoard();
        printf("Player %d's turn (row column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '-') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[row - 1][col - 1] = (currentPlayer == 1) ? 'X' : 'O';
        result = checkWin();
        if (result == 1) {
            displayBoard();
            printf("Player %d wins!\n", currentPlayer);
            break;
        } else if (result == 2) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
