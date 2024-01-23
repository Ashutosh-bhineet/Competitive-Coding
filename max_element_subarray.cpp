#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
deque<int> dq;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k;i<n;i++){
            ans.push_back(dq.front());
            while(!dq.empty() && i-k>=dq.front())
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
    for(auto it:ans){
        cout<<it<<" ";
    }

}