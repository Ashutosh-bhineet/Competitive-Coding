#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=9;
    int a[]={3,2,4,1,7,8,6,10,9};
/*     vector<int> dp(n,1);
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[j]<a[i])
                    dp[i]=max(1+dp[j],dp[i]);
            }
            ans=max(dp[i],ans);
        }
       cout<<ans; */
        vector<int>ans;
             ans.push_back(a[0]);
             int length=1;
             for(int i=1;i<n;i++){
                 if(a[i]>ans.back()){
                     ans.push_back(a[i]);
                     length++;
                 }
                 else{
                     int index = lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                     ans[index]=a[i];
                 }
             }
             cout<<length;
    }