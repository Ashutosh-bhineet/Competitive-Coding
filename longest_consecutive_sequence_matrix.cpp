#include <bits/stdc++.h>
using namespace std;
int maxi=INT_MIN;
int solve(int i, int j, int p, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    if(i == matrix.size() || j == matrix[0].size() || i<0 || j<0)
        return 0;
        
    if(p != -1 && matrix[i][j] != p+1)
        return 0;
        
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans=0;
    /* int left = 1 + solve(i, j-1, matrix[i][j], matrix, dp);
    int right = 1+solve(i, j+1, matrix[i][j], matrix, dp);
    int up = 1+solve(i-1, j, matrix[i][j], matrix, dp);
    int down = 1+solve(i+1, j, matrix[i][j], matrix, dp);
    int up_right=1+solve(i-1,j+1,matrix[i][j],matrix,dp);
    int down_right=1+solve(i+1,j+1,matrix[i][j],matrix,dp);
    int up_left=1+solve(i-1,j-1,matrix[i][j],matrix,dp);
    int down_left=1+solve(i+1,j-1,matrix[i][j],matrix,dp); */
    vector<int> x={0,-1,-1,-1,0,1,1,1};
    vector<int> y={1,1,0,-1,-1,-1,0,1};
    for(int k=0;k<8;k++){
        int x1=i+x[k];
        int x2=i+y[k];
        int subproblem=solve(x1,x2,matrix[i][j],matrix,dp);
        ans=max(ans,subproblem);
    }
 /*    int max1 = max(left, right);
    int max2 = max(up, down);
    int max3= max(up_right,down_right);
    int max4=max(up_left,down_left); 
    dp[i][j] = max(max1, max(max2,max(max3,max4))); */
    return dp[i][j]=ans+1;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix[0].size(), m = matrix.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int path = INT_MIN;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            path = max(path, solve(i, j, -1, matrix, dp));
        }
    }
    return path;
}
int main(){
    vector<vector<int>> matrix={{3,2,0,1},{4,1,6,2},{8,11,2,3},{10,7,24,4},{9,12,5,23},{11,20,21,22}};
    cout<<longestIncreasingPath(matrix);
}