// Time: O(1);
// Space: O(1)
// leetcode 36


#include<iostream>
#include<vector>
using namespace std;



bool isSafe(vector<vector<char>>& sudoku, int row, int col){

    char ch = sudoku[row][col];
    if(ch == '.') return true;

    for(int j=0; j<9; j++){
        if(j != col && sudoku[row][j] == ch)
            return false;
    }

    for(int i=0; i<9; i++){
        if(i != row && sudoku[i][col] == ch)
            return false;
    }

    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i=startRow; i<startRow+3; i++){
        for(int j=startCol; j<startCol+3; j++){
            if((i != row || j != col) && sudoku[i][j] == ch)
                return false;
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>>& sudoku) {

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(!isSafe(sudoku, i, j))
                return false;
        }
    }

    return true;
}

int main(){
    vector<vector<char>> input = {
                                 {'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};

    if(isValidSudoku(input)) cout<<"true"<<"\n";
    else cout<<"false"<<endl;
}