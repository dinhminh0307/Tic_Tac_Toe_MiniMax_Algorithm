#include <iostream>

char myTable[3][3] = {' ', ' ', ' ',
                      ' ', ' ', ' ',
                      ' ', ' ', ' '};
bool isPlayerWin = false;
bool checkValidMove = false;
int gameState = 0;

void tableDisplay(char table[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "|"<< table[i][j] << "|";
        }
        std::cout << "\n";
    }
    std:: cout << "Enter your turn: " << "\n";
}

void userTurn(char table[3][3]) {
    int row, column;
    tableDisplay(table);
    std::cin >> row >> column;
    table[row][column] = 'X';
}

void secondPlayerTurn(char table[3][3]) {
    int row, column;
    tableDisplay(table);
    std::cin >> row >> column;
    table[row][column] = 'O';
}

bool checkMoveLeft(char table[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(table[i][j] == ' ') {
                return true;
            }
        }
    }
    return false;
}
bool checkGameOver(char table[3][3]) {
    for(int i = 0; i < 3; i++) {
            if(table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
                if(table[i][0] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    gameState = 1;
                    return true;
                }
                else if(table[i][0] == ' ') {
                    checkValidMove = false;
                    gameState = 0;
                }
                else {
                    isPlayerWin = false;
                    checkValidMove = true;
                    gameState = -1;
                    return true;
                }
            }
            else if(table[i][0] == table[i +1][0] && table[i][0] == table[i+2][0]) {
                if(table[i][0] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    gameState = 1;
                    return true;
                }
                else if(table[i][0] == ' ') {
                    checkValidMove = false;
                    gameState = 0;
                }
                else {
                    isPlayerWin = false;
                    gameState = -1;
                    checkValidMove = true;
                    return true;
                }
            }
            else if(table[i][1] == table[i +1][1] && table[i][1] == table[i + 2][1]) {
                if(table[i][1] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    gameState = 1;
                    return true;
                }
                else if(table[i][1] == ' ') {
                    gameState = 0;
                    checkValidMove = false;
                }
                else {
                    isPlayerWin = false;
                    checkValidMove = true;
                    gameState = -1;
                    return true;
                }
            }
            else if(table[i][2] == table[i +1][2] && table[i][2] == table[i + 2][2]) {
                if(table[i][2] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    gameState = 1;
                    return true;
                }
                else if(table[i][2] == ' ') {
                    checkValidMove = false;
                }
                else {
                    isPlayerWin = false;
                    gameState = -1;
                    checkValidMove = true;
                    return true;
                }
            }
            else if(table[i][0] == table[i + 1][1] && table[i][0] == table[i + 2][2]) {
                if(table[i][0] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    gameState = 1;
                    return true;
                }
                else if(table[i][0] == ' ') {
                    checkValidMove = false;
                }
                else {
                    isPlayerWin = false;
                    checkValidMove = true;
                    gameState = -1;
                    return true;
                }
            }
            else if(table[i][2] == table[i + 1][1] && table[i][2] == table[i +2][0]) {
                if(table[i][0] == 'X') {
                    isPlayerWin = true;
                    gameState = 1;
                    return true;
                }
                else {
                    isPlayerWin = false;
                    gameState = -1;
                    return true;
                }
            }
        }
    gameState = 0;
    return false;
}

int getMaxValue(int bestVal, int miniMaxVal) {
    if(bestVal < miniMaxVal) {
        return miniMaxVal;
    }
    else {
        return bestVal;
    }
}

int computerMiniMax(char table[3][3], bool isPlayerMove) {
    // Minimax function
    checkGameOver(table);
    if(gameState == 1) {
        return gameState;
    }
    else if(gameState == -1) {
        return gameState;
    }
    else if(gameState == 0) {
        return gameState;
    }
    if(isPlayerMove) {
        int bestVal = -1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(table[i][j] == ' ') {
                    table[i][j] = 'X';
                    int val = computerMiniMax(table, !isPlayerMove);
                    bestVal = getMaxValue(bestVal, val);
                    table[i][j] = ' ';
                }
            }
        }
        return bestVal;
    }
    else {
        int bestVal = 1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(table[i][j] == ' ') {
                    table[i][j] = 'O';
                    int val = computerMiniMax(table, !isPlayerMove);
                    bestVal = getMaxValue(bestVal, val);
                    table[i][j] = ' ';
                }
            }
        }
        return bestVal;
    }
}

void computerTurn(char table[3][3]) {
    // This function to take the move
    int row = 0;
    int col = 0;
    int score = -1000;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int j = 0; j < 3;j++) {
                if(table[i][j] == ' ') {
                    table[i][j] = 'X';
                    int currentMove = computerMiniMax(table, false);
                    table[i][j] = ' ';
                    if(currentMove > score) {
                        score = currentMove;
                        row = i;
                        col = j;
                    }
                }
            }
        }
    }
    table[row][col] = 'O';
}

void game(char table[3][3]) {
    while(1) {
        // std:: cout << checkGameOver(table);
        if(checkMoveLeft(table)) {
            if(checkGameOver(table)) {
                if(checkValidMove) {
                    if(isPlayerWin) {
                        std::cout << "Game Over! and Player Win!" << std::endl;
                    }
                    else {
                        std::cout << "Game Over! and Computer Win!" << std::endl;
                    }
                    break;
                }
                else {
                    continue;
                }
            }
            else {
                userTurn(table);
                computerTurn(table);
            }
        }
        else {
            if(checkGameOver(table)) {
                if(isPlayerWin) {
                    std::cout << "Game Over! and Player Win!" << std::endl;
                }
                else {
                    std::cout << "Game Over! and Computer Win!" << std::endl;
                }
                break;
            }
            else {
                std::cout << "Game Over! and No one Win!" << std::endl;
                break;
            }
        }
    }
} 

void twoPlayerMode(char table[3][3]) {
    while(1) {
        if(checkMoveLeft(table)) { // For full table and 1 of the two players win
            if(checkGameOver(table)) {
                if(checkValidMove) {
                    if(isPlayerWin) {
                        std:: cout << "Game Over! and Player1 Win!" << std::endl;
                    }
                    else {
                        std::cout << "Game Over! and Player2 Win" << std::endl;
                    }
                }
                else {
                    continue;
                }
            }
            else {
                userTurn(table);
                if(checkGameOver(table)) { // When there is not full table and 1 of the players win
                    if(isPlayerWin) {
                        std:: cout << "Game Over! and Player1 Win!" << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Game Over! and Player2 Win" << std::endl;
                        break;
                    }
                }
                secondPlayerTurn(table);
            }
        }
        else {
            if(checkGameOver) {
                    if(isPlayerWin) {
                        std:: cout << "Game Over! and Player1 Win!" << std::endl;
                    }
                    else {
                        std::cout << "Game Over! and Player2 Win" << std::endl;
                    }
                    break;
                }
                else {
                    std:: cout << "Game Over! and Draw" << std::endl;
                    break;
                }
        }
    }
    // std::cout << "Game Over" << std::endl;
}

void menuPromptMessage() {
    std::cout << "----------------------------" << std::endl;
    std::cout << "|     Tic Tac Toe Game!     |" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << ">>> Made by Dinh Minh" << std::endl;
    std::cout << "Press 1 to Play with computer >>>>" << std::endl;
    std::cout << "Press 2 to Play with 2 players mode >>>>>" << std::endl;
}
void menu(char table[3][3]) {
    int choice;
    menuPromptMessage();
    std:: cin >> choice;
    while(1) {
        if(choice == 1 || choice == 2) {
            break;
        }
        menuPromptMessage();
        std:: cin >> choice;
    }
    if(choice == 1) {
        game(table);
    }
    else if(choice == 2) {
        twoPlayerMode(table);
    }
}

int main(void) {
    menu(myTable);
}