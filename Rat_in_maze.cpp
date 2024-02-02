#include <bits/stdc++.h>
using namespace std;
int cou=0;
void solve(vector<vector<int>> matrix,int i,int j,int n,int m,string ans,vector<string> &out){
    if(i==n-1 && j==n-1 && matrix[i][j]!=0){
        cou++;
        out.push_back(ans);
        return ;
    }
    if(i>=0 && i<n && j>=0 && j<m){
        if(matrix[i][j]==2 || matrix[i][j]==0)
            return ;
        matrix[i][j]=2;
        solve(matrix,i,j+1,n,m,ans+'R',out);
        solve(matrix,i+1,j,n,m,ans+'D',out);
        solve(matrix,i-1,j,n,m,ans+'U',out);
        solve(matrix,i,j-1,n,m,ans+'L',out);
        matrix[i][j]=0;
    }
}
vector<string> count_path(vector<vector<int>> matrix,int n,int m){
    vector<string> res;
    solve(matrix,0,0,n,m,"",res);
    return res;
}
int main(){
    vector<vector<int>> matrix={{1, 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0},{0, 1, 1, 1}};
    int n=matrix.size(),m=matrix[0].size();
    vector<string> res=count_path(matrix,n,m);
    for(auto it:res){
        cout<<it<<endl;
    }
}