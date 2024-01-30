#include<bits/stdc++.h>
using namespace std;
    bool canPlace(vector<vector<char>>& board,int i,int j,int N,char num){
        for(int k=0;k<9;k++){
            if(board[i][k]==num || board[k][j]==num)
                return false;
        }
        for (int row = (i/3)*3; row<(i/3)*3+3 ; row++) {
            for (int col = (j/3)*3; col<(j/3)*3+3 ; col++) {
                if (board[row][col] == num) 
                    return 0;
           }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board,int i,int j,int N){
        if(i==N)
            return 1;
        if(j==N)
            solve(board,i+1,0,N);
        if(board[i][j]!='.')
            return solve(board,i,j+1,N);
        for(char k='1';k<='9';k++){
            if(canPlace(board,i,j,N,k)){
                board[i][j]=k;
                if(solve(board,i,j+1,N))
                    return 1;
                
            }
    }
       board[i][j]='.';
       return 0;
    }
int main(){
    
}