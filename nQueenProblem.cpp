#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(vector<vector<int>> &board, int n, int r, int c) {
        for (int i = 0; i < r; i++)
            if (board[i][c]) return false;
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]) return false;
        for (int i = r, j = c; i >= 0 && j < n; i--, j++)
            if (board[i][j]) return false;
        return true;
    }
bool NQueen(vector<vector<int>> &board,int n,int i){
    if(i==n){
        print(board,n);
        cout<<"---------------"<<endl;
        return false;
    }
    for(int j=0;j<n;j++){
        if(isSafe(board,n,i,j)){
            board[i][j]=1;
            bool solve=NQueen(board,n,i+1);
            if(solve){
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    NQueen(board,n,0);
}