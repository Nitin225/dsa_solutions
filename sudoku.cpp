// Time: O(9^n);
// Space: O(n)
// Leetcode 37


#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include <typeinfo>
using namespace std;


void print(vector<vector<int>>& sudoku){
    for(int i=0; i<sudoku.size(); i++){
        for(int j=0; j<sudoku[0].size(); j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>>& sudoku, int row, int col, int digit){
    for(int j=0; j<9; j++){
        if(sudoku[row][j] == digit)
            return false;
    }
    for(int i=0; i<9; i++){
        if(sudoku[i][col] == digit)
            return false;
    }

    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3;
    for(int i=startRow; i<startRow+3; i++){
        for(int j=startCol; j<startCol+3; j++){
            if(sudoku[i][j] == digit)
                return false;
        }
    }
    return true;

}


bool SudokuSolver(vector<vector<int>>& sudoku,  int row, int col){
    
    if(row == 9){
        print(sudoku);
        return true; 
    }
    
    int nextRow = row;
    int nextCol = col + 1;

    if(nextCol == 9){
        nextCol = 0;
        nextRow += 1; 
    }

    if(sudoku[row][col] != 0){
        return SudokuSolver(sudoku, nextRow, nextCol);
    }
    for(int digit=1; digit<=9; digit++){
        if(isSafe(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if(SudokuSolver(sudoku, nextRow, nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main(){

    vector<vector<string>> sudoku = {
                                    {"5","3",".",".","7",".",".",".","."},
                                    {"6",".",".","1","9","5",".",".","."},
                                    {".","9","8",".",".",".",".","6","."},
                                    {"8",".",".",".","6",".",".",".","3"},
                                    {"4",".",".","8",".","3",".",".","1"},
                                    {"7",".",".",".","2",".",".",".","6"},
                                    {".","6",".",".",".",".","2","8","."},
                                    {".",".",".","4","1","9",".",".","5"},
                                    {".",".",".",".","8",".",".","7","9"}
                                    };

    vector<vector<int>> board(9, vector<int>(9));

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(sudoku[i][j] == ".")
                board[i][j] = 0;   // empty cell
            else
                board[i][j] = sudoku[i][j][0] - '0';
        }
    }

    print(board);
    cout<<endl;
    SudokuSolver(board, 0, 0);

    vector<vector<string>> result(9, vector<string>(9));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == 0)
                result[i][j] = ".";   // empty
            else
                result[i][j] = to_string(board[i][j]);
        }
    }

    cout<<endl; 
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

}