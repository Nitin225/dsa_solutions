// Time = O(2^(2n))
// Space = O(n)


#include<iostream>
#include<vector>
#include<string>
using namespace std;

void  RatInMaze(vector<vector<bool>>& a, int n, int row, int col, string s){
    if(row >= n || col >= n)
        return;
        
    if(a[row][col] == false)
        return;

    if(row == n-1 && col == n-1){
        cout<<s<<endl;
        return;
    }

    if(col + 1 < n && a[row][col+1] == true){
        RatInMaze(a, n, row, col+1, s + "R");
    }

    if(row + 1 < n && a[row+1][col] == true){
        RatInMaze(a, n, row+1, col, s + "D");
    }

}

int main(){
    vector<vector<int>> maze = {{1,0,0,0},
                                {1,1,0,1},
                                {1,1,0,0},
                                {0,1,1,1}};
                                
    int n = maze.size();                            
    vector<vector<bool>> a(n, vector<bool>(n, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(maze[i][j] == 1)
                a[i][j] = true;
        }
    }
    string s = "";
    RatInMaze(a, n, 0, 0, s);

    return 0;
}