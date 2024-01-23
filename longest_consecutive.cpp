#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it:nums)
            s.insert(it);
        int ans=0,count=1;
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int t=it+1;
                while(s.find(t)!=s.end()){
                    count++;
                    t++;
                }
                ans=max(ans,count);
                count=1;
            }
        }
        return ans;
    }
int main(){
    vector<int> a={9,1,4,7,3,-1,0,5,8,-1,6};
    cout<<longestConsecutive(a);
}