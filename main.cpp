#include <iostream>

char myTable[3][3] = {' ', ' ', ' ',
                      ' ', ' ', ' ',
                      ' ', ' ', ' '};
bool isPlayerWin = false;
bool checkValidMove = false;

void tableDisplay(char table[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "|"<< table[i][j] << "|";
        }
        std::cout << "\n";
    }
    std:: cout << "Enter your turn: " << "\n";
}

void computerTurn(char table[3][3]) {

}
void userTurn(char table[3][3]) {
    int row, column;
    tableDisplay(table);
    std::cin >> row >> column;
    table[row][column] = 'X';
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
bool checkGameOver(char table[3][3]) { // Bug is here the function always returns true
    for(int i = 0; i < 3; i++) {
            if(table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
                if(table[i][0] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    return true;
                }
                else if(table[i][0] == ' ') {
                    checkValidMove = false;
                }
                else {
                    isPlayerWin = false;
                    checkValidMove = true;
                    return true;
                }
            }
            else if(table[i][0] == table[i +1][0] && table[i][0] == table[i+2][0]) {
                if(table[i][0] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    return true;
                }
                else if(table[i][0] == ' ') {
                    checkValidMove = false;
                }
                else {
                    isPlayerWin = false;
                    checkValidMove = true;
                    return true;
                }
            }
            else if(table[i][1] == table[i +1][1] && table[i][1] == table[i + 2][1]) {
                if(table[i][1] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    return true;
                }
                else if(table[i][1] == ' ') {
                    checkValidMove = false;
                }
                else {
                    isPlayerWin = false;
                    checkValidMove = true;
                    return true;
                }
            }
            else if(table[i][2] == table[i +1][2] && table[i][2] == table[i + 2][2]) {
                if(table[i][2] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    return true;
                }
                else if(table[i][2] == ' ') {
                    checkValidMove = false;
                }
                else {
                    isPlayerWin = false;
                    checkValidMove = true;
                    return true;
                }
            }
            else if(table[i][0] == table[i + 1][1] && table[i][0] == table[i + 2][2]) {
                if(table[i][0] == 'X') {
                    isPlayerWin = true;
                    checkValidMove = true;
                    return true;
                }
                else if(table[i][0] == ' ') {
                    checkValidMove = false;
                }
                else {
                    isPlayerWin = false;
                    checkValidMove = true;
                    return true;
                }
            }
            else if(table[i][2] == table[i + 1][1] && table[i][2] == table[i +2][0]) {
                if(table[i][0] == 'X') {
                    isPlayerWin = true;
                    return true;
                }
                else {
                    isPlayerWin = false;
                    return true;
                }
            }
        }
    return false;
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
            // computerTurn(table);
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

void menuPromptMessage() {
    std::cout << "----------------------------" << std::endl;
    std::cout << "|     Tic Tac Toe Game!     |" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << ">>> Made by Dinh Minh" << std::endl;
    std::cout << ">>> Version 1.0.0" << std::endl;
    std::cout << "Press 1 to continue >>>>" << std::endl;
    std::cout << "Press 2 to exit>>>>>" << std::endl;
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

    }
}
int main(void) {
    
    menu(myTable);
}