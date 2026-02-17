#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    
public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }
    
    void displayBoard() {
        cout << "\n   1   2   3\n";
        cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
        cout << "  -----------\n";
        cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
        cout << "  -----------\n";
        cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n\n";
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
    
    cout << "====================================\n";
    cout << "      WELCOME TO TIC-TAC-TOE\n";
    cout << "====================================\n\n";
    
    while (playAgain) {
        game.displayBoard();
        
        while (true) {
            cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
            cin >> row >> col;
            
            row = row - 1;
            col = col - 1;
            
            if (game.makeMove(row, col)) {
                game.displayBoard();
                
                if (game.checkWin()) {
                    cout << "====================================\n";
                    cout << "      PLAYER " << game.getCurrentPlayer() << " WINS!\n";
                    cout << "====================================\n\n";
                    break;
                }
                
                if (game.isBoardFull()) {
                    cout << "====================================\n";
                    cout << "         IT'S A DRAW!\n";
                    cout << "====================================\n\n";
                    break;
                }
                
                game.switchPlayer();
            } else {
                cout << "Invalid move! Try again.\n\n";
            }
        }
        
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        
        if (choice == 'y' || choice == 'Y') {
            game.reset();
            cout << "\n";
        } else {
            playAgain = false;
        }
    }
    
    cout << "\nThanks for playing! Goodbye!\n";
    
    return 0;
}