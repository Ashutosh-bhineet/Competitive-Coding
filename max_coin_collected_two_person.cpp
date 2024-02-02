#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> dp,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------"<<endl;
}
int solve(vector<vector<int>> matrix,int n,int m){
    vector<vector<int>> dp1(n,vector<int>(m));
    dp1[0][0]=matrix[0][0];
    for(int i=1;i<n;i++){
        dp1[i][0]=dp1[i-1][0]+matrix[i][0];
    }
    for(int j=1;j<m;j++){
        dp1[0][j]=dp1[0][j-1]+matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+matrix[i][j];
        }
    }
    vector<vector<int>> dp2(n,vector<int>(m));
    dp2[0][m-1]=matrix[0][m-1];
    for(int i=1;i<n;i++){
        dp2[i][0]=dp2[i-1][0]+matrix[i][0];
    }
    for(int j=m-2;j>=0;j--){
        dp2[0][j]=dp2[0][j+1]+matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=n-2;j>=0;j--){
            dp2[i][j]=max(dp2[i-1][j],dp2[i][j+1])+matrix[i][j];
        }
    }
    vector<vector<int>> dp3(n,vector<int>(m));
    dp3[n-1][0]=matrix[n-1][0];
    for(int i=n-2;i>=0;i--){
        dp3[i][0]=dp3[i+1][0]+matrix[i][0];
    }
    for(int j=1;j<m;j++){
        dp3[n-1][j]=dp3[n-1][j-1]+matrix[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=1;j<m;j++){
            dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+matrix[i][j];
        }
    }
    vector<vector<int>> dp4(n,vector<int>(m));
    dp4[n-1][m-1]=matrix[n-1][m-1];
    for(int i=n-2;i>=0;i--){
        dp4[i][m-1]=dp4[i+1][m-1]+matrix[i][m-1];
    }
    for(int j=m-2;j>=0;j--){
        dp4[n-1][j]=dp4[n-1][j+1]+matrix[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp4[i][j]=max(dp4[i+1][j],dp4[i][j+1])+matrix[i][j];
        }
    }
    int ans=0;
    int temp1,tempj;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            int opt1=dp1[i-1][j]+dp4[i+1][j]+dp2[i][j+1]+dp3[i][j-1];
            int opt2=dp1[i][j-1]+dp4[i][j+1]+dp2[i-1][j]+dp3[i+1][j];
            int total=max(opt1,opt2);
            if(total>ans){
                temp1=i;
                tempj=j;
            }
            ans=max(ans,max(opt1,opt2));
        }
    }
    print(dp1,n,m);
    print(dp2,n,m);
    print(dp3,n,m);
    print(dp4,n,m);
    cout<<temp1<<" "<<tempj<<endl;
    return ans;
}
int main(){
    vector<vector<int>> matrix={{1,2,1,4,6},{6,8,7,-2,3},{4,3,2,1,6},{11,10,8,5,4},{12,15,6,3,7}};
    print(matrix,5,4);
    cout<<solve(matrix,5,4);
}
