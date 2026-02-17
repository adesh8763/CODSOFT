#include <iostream>
#include <vector>


class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
    
public:
    TicTacToe() {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
    }
    
    void displayBoard() {
        std::cout << "\n   1   2   3\n";
        std::cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
        std::cout << "  -----------\n";
        std::cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
        std::cout << "  -----------\n";
        std::cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n\n";
    }
    
    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        
        board[row][col] = currentPlayer;
        return true;
    }
    
    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
        }
        
        for (int j = 0; j < 3; j++) {
            if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                return true;
            }
        }
        
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
        
        return false;
    }
    
    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
    
    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
    
    char getCurrentPlayer() {
        return currentPlayer;
    }
    
    void reset() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
    }
};

int main() {
    TicTacToe game;
    int row, col;
    bool playAgain = true;
    char choice;
    
    std::cout << "====================================\n";
    std::cout << "      WELCOME TO TIC-TAC-TOE\n";
    std::cout << "====================================\n\n";
    
    while (playAgain) {
        game.displayBoard();
        
        while (true) {
            std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
            std::cin >> row >> col;
            
            row = row - 1;
            col = col - 1;
            
            if (game.makeMove(row, col)) {
                game.displayBoard();
                
                if (game.checkWin()) {
                    std::cout << "====================================\n";
                    std::cout << "      PLAYER " << game.getCurrentPlayer() << " WINS!\n";
                    std::cout << "====================================\n\n";
                    break;
                }
                
                if (game.isBoardFull()) {
                    std::cout << "====================================\n";
                    std::cout << "         IT'S A DRAW!\n";
                    std::cout << "====================================\n\n";
                    break;
                }
                
                game.switchPlayer();
            } else {
                std::cout << "Invalid move! Try again.\n\n";
            }
        }
        
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;
        
        if (choice == 'y' || choice == 'Y') {
            game.reset();
            std::cout << "\n";
        } else {
            playAgain = false;
        }
    }
    
    std::cout << "\nThanks for playing! Goodbye!\n";
    
    return 0;
}