#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2,1,4,6,3,8,7};
    int n =7;
    int count=0;
    int target=11;
    sort(arr,arr+n);
    for(int i=0;i<=n-3;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            if(arr[i]+arr[j]+arr[k]<=target){
                count+=(k-j);
                j++;
            }
            else{
                k--;
            }
        }
    }
    cout<<count;
}