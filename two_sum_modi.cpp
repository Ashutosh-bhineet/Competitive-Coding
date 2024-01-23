#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> arr,int target){
   int i=0,j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j]==target)
            return {i,j};
        else if(arr[i]+arr[j]>target)
            j--;
        else
            i++;
    }
    return {-1};
}
unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            mp1[arr1[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp1.find(arr2[i])!=mp.end())
            {
                v.push_back(arr2[i]);
            }
            
        }
        if(!v.empty())
        return v;
        v.push_back(-1);
        return v;
int main(){
    vector<int> arr={2,7,11,15};
    int target=9;
    vector<int> ans=solve(arr,target);
    cout<<ans[0]<<" "<<ans[1];
}