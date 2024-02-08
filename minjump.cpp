#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int>dp(n);// 1 3 5 6 7 
    dp[0]=arr[0];
    int maxreach=arr[0];
    for(int i=1;i<n;i++)
    {
        if(maxreach<i)
        {
            cout<<-1<<endl;
            return 0;
        }
        dp[i]=max(dp[i-1],i+arr[i]);
        maxreach=dp[i];
    }
    int i=0;
    int count=0;
    while(i<n-1)
    {
        i=dp[i];
        count++;
    }
    cout<<count;


}