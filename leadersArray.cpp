#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=arr[n-1];
    int count=1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max){
            count++;
            max=arr[i];
        }
    }
    cout<<count;
}