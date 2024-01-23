#include <bits/stdc++.h>
using namespace std;
int check(vector<long long int> stalls,int k,int dif){
    int count=1;
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=dif){
                count++;
                last=stalls[i];
            }
        }
        if(count>=k)
            return 1;
        return 0;
    }
    long long int solve(vector<long long int> &stalls,int n,int k) {
        int start=0;
        sort(stalls.begin(),stalls.end());
        int end=stalls[n-1]-stalls[0];
        int ans;
        while(start<=end){
            int mid=(start+end)/2;
            if(check(stalls,k,mid)){
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
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<long long int> arr;
        for(int i=0;i<n;i++){
            long long int x;
            cin>>x;
            arr.push_back(x);
        }
            cout<<solve(arr,n,c)<<endl;
    }
}