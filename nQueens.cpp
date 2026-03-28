// Time: O(n!)
// Space: O(n^2)
// place n queens in on an (n x n) chess board such that no 2 queens can attack
// leetcode 51

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char>> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"------------------"<<endl;
}

bool isSafe(vector<vector<char>> &board, int row, int col) {
    int n = board.size();

    // horizontal
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    // vertical
    for(int i=0; i<row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // left diagonal
    for(int i=row,j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // right diagonal
    for(int i=row,j=col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void nQueens(vector<vector<char>> &board, int row){
    int n = board.size();

    if(row == n){
        print(board);
        return;
    }

    for(int j=0; j<n; j++){
        if(isSafe(board, row, j)){
            board[row][j] = 'Q';
            nQueens(board, row+1);
            board[row][j] = '.';
        }
    }
}

int main(){
    int n = 4;

    vector<vector<char>> board(n, vector<char>(n, '.'));

    nQueens(board, 0);

    return 0;
}