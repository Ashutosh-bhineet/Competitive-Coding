#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> arr={{1,6,9,11},{0,2,7,10},{0,0,3,8},{0,0,0,4}};
    int n=4;
    for(int i=0;i<n;i++){
        cout<<arr[i][i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        for(int k=0;k<n-i;k++){
            cout<<arr[k][k+i]<<" ";
        }
        cout<<endl;
    }
}