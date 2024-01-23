#include <bits/stdc++.h>
using namespace std;
int check(vector<int> arr,int n,int p,int time){
    int count=0;
    for(int i=0;i<n;i++){
        int total=arr[i]*1;
        int j=2;
        while(total<=time){
            total+=arr[i]*j;
            count++;
            j++;
        }
        if(count>=p)
            return 1;
    }
    if(count>=p){
        return 1;
    }
    return 0;
}
int solve(vector<int> arr,int n,int p){
    int start=0;
    int min=*min_element(arr.begin(),arr.end());
    int end=min*((p*(p+1))/2);
    int ans=0;
    while(start<=end){
        int mid=(start+end)/2;
        if(check(arr,n,p,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int p;
        cin>>p;
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cout<<solve(arr,n,p)<<endl;
    }
}