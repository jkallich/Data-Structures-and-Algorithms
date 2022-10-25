#include "util.h"
#include <vector>

int BOARD_SIZE = 15;
vector<vector<char> > board;

int adjacentAlive(int r, int c) {
    
    int adjacent= 0;
    for(int i= r-1; i <= r+1; i++) {
        if(i < 0) {
            i= 0;
        }
        if(i >= board.size()) {
            break;
        }
        
        for(int j= c-1; j <= c+1; j++) {
            if(i<0){
                j=0;
            }
            if(j>=board.size()){
                break;
            }
            
            if(r==i && j==c) {
                continue;
            }
            
            
            if(board[i][j] == 'O'){
                adjacent++;
            }
        }
    }
    
    return adjacent;
}

void printBoard() {
    for(int i= 0; i < board.size(); i++) {
        for(int j= 0; j < board[i].size(); j++) {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
}

void recreateBoard () {
    for(int i= 0; i < board.size(); i++) {
        for(int j= 0; j< 15; j++) {
            if(board[i][j] == 'O') { 
                if(adjacentAlive(i,j) !=2 & adjacentAlive(i,j) !=3){
                    board[i][j]= '-';
                }
            } else {
                if(adjacentAlive(i,j) == 3){
                    board[i][j]= 'O';
                }
            }
            if(j==14){
                break;
            }
        }
        
    }
}

int main()
{
    int initialAlive;
    cout << "Enter number of active cells (1-225): ";
    cin >> initialAlive;
    cin.ignore();
    cout << "Initial Alive: " << initialAlive << endl;
    
    for(int i=0; i<BOARD_SIZE; i++) {
        vector<char> row;
        for(int j= 0; j < BOARD_SIZE; j++) {
            row.push_back('-');
        }
        
        board.push_back(row);
    }
    
    int changed= 0;
    while(changed < initialAlive) {
        int r= randInt(0, 14);
        int c= randInt(0, 14);
        if(board[r][c]=='-'){
            board[r][c]= 'O';
            changed++;
        }
    }
    
    int count= 0;
    for(int i= 0; i<board.size();i++) {
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]=='O'){
                count++;
            }
        }
    }
    
    string input= "c";
    while(input != "q") {
        printBoard();
        cout << "Press enter to continue, q to quit. ";
        getline(cin, input);
        recreateBoard();
    }
    
    return 0;
}