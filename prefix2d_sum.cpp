#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int s[n][n];
    s[0][0]=arr[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                continue;
            }
            else if(i==0){
                s[i][j]=s[i][j-1]+arr[i][j];
            }
            else if(j==0){
                s[i][j]=s[i-1][j]+arr[i][j];
            }
            else{
                s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans=INT_MIN;
    for(int i=0;i<=n-2;i++){
        int ram=INT_MAX;
        for(int j=0;j<=n-2;j++){
            int q1=s[i][j];
            int q2=s[i][n-1]-q1;
            int q3=s[n-1][j]-q1;
            int q4=s[n-1][n-1]-q1-q2-q3;
            ram=min(q1,min(q2,min(q3,q4)));
            ans=max(ram,ans);
        }
    }
    cout<<ans;
}