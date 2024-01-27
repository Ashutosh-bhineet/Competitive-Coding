#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<K;i++){
        pq.push(make_pair(arr[i][0],make_pair(i,0)));
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().first);
        int temp_i=pq.top().second.first;
        int temp_j=pq.top().second.second;
        pq.pop();
        if(temp_j+1<arr[temp_i].size()){
            pq.push(make_pair(arr[temp_i][temp_j+1],make_pair(temp_i,temp_j+1)));
        }
    }
    return ans;
}

int32_t main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res=mergeKArrays(arr,3);
    for(int num : res){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
