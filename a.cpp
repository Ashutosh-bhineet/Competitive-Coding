#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> nums) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto it:nums){
        pq.push(it);
    }
    int sum=0;
    while(pq.size()>=2){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        sum+=x+y;
        pq.push(x+y);
    }
    cout<<sum;
    return sum;
}
int main(){
    cout<<solve({4 ,5, 99, 100,34});
}