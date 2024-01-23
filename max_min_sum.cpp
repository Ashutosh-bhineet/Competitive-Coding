#include <bits/stdc++.h>
using namespace std;
int check(vector<int> arr,int n,int k,int mid){
    int sum=0;
    int count=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>=mid){
            count++;
            sum=0;
        }
    }
    if(count>=k)
        return 1;
    else
        return 0;
}
int solve(vector<int> arr,int n,int k){
    int sum=accumulate(arr.begin(),arr.end(),0);
    int start=*min_element(arr.begin(),arr.end()),end=sum;
    int ans;
    while(start<=end){
        int mid=(start+end)/2;
        if(check(arr,n,k,mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int n=10;    
    int k=6;
    vector<int> arr={6 ,4 ,5 ,1 ,5 ,6 ,6 ,6 ,5 ,2};
    cout<<solve(arr,n,k);
}