#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool cmp(pair<int,int> a,pair<int,int>b){
    return a.second<b.second;
}
int32_t	 main(){
    int t;
    cin>>t;
    while(t--){
        int task;
        cin>>task;
        vector<pair<int,int>> activity;
        for(int i=0;i<task;i++){
            int start,end;
            cin>>start>>end;
            activity.push_back(make_pair(start,end));
        }
        sort(activity.begin(),activity.end(),cmp);
        int last_end=0;
        int count=0;
        for(int i=0;i<task;i++){
            if(activity[i].first>=last_end){
                count++;
                last_end=activity[i].second;
            }
        }
        cout<<count<<endl;
    }
}