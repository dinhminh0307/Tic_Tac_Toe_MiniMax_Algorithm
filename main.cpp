#include <iostream>

char myTable[3][3] = {'X', 'O', 'O',
                      'O', 'X', 'X',
                      'X', 'O', 'O'};
bool isPlayerWin = false;

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

bool checkGameOver(char table[3][3]) { // Bug is here the function always returns true
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) {
                if(table[i][j] == 'X') {
                    isPlayerWin = true;
                    return true;
                }
                else {
                    isPlayerWin = false;
                    return true;
                }
            }
            else if(table[i][j] == table[i +1][j] && table[i][j] == table[i+2][j]) {
                if(table[i][j] == 'X') {
                    isPlayerWin = true;
                    return true;
                }
                else {
                    isPlayerWin = false;
                    return true;
                }
            }
            else if(table[i][j] == table[i +1][j + 1] && table[i][j] == table[i + 2][j + 2]) {
                if(table[i][j] == 'X') {
                    isPlayerWin = true;
                    return true;
                }
                else {
                    isPlayerWin = false;
                    return true;
                }
            }
            if(i == 0 && j == 2) {
                if(table[i][j] == table[i + 1][j - 1] && table[i][j] == table[i + 2][j - 2]) {
                    if(table[i][j] == 'X') {
                        isPlayerWin = true;
                        return true;
                    }
                    else {
                        isPlayerWin = false;
                        return true;
                    }
                }
            }
            continue;
        }
    }
    return false;
}

void game(char table[3][3]) {
    while(1) {
        // std:: cout << checkGameOver(table);
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
            userTurn(table);
            // computerTurn(table);
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