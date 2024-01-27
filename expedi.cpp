#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool cmp(vector<int> a,vector<int> b){
    return a[0]>b[0];
}
int32_t	 main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            arr.push_back({x,y});
        }
        int target,start_fuel;
        cin>>target>>start_fuel;
        sort(arr.begin(),arr.end(),cmp);
        priority_queue<int> pq;
        int count=0;
        int flag=0;
        int start=0;
        int i=0;
        while(i<n){
            int distance=target-arr[i][0]-start;
            if(start_fuel>=distance){
                start_fuel-=distance;
                pq.push(arr[i][1]);
                start=target-arr[i][0];
            }
            else{
                if(pq.empty() ){
                    flag=1;
                    break;
                }
                    start_fuel+=pq.top();
                    pq.pop();
                    count++;
                    continue;
            }
            i++;
        }
        if(flag){
            cout<<-1<<endl;
            continue;
        }
        int last_distance=target-target-arr[n-1][0];
        if(start_fuel>=last_distance){
               cout<<count<<endl;
               continue;
            }
        while(start_fuel<last_distance){
                if(pq.empty() && start_fuel<last_distance){
                    flag=1;
                    break;
                }
                    start_fuel+=pq.top();
                    pq.pop();
                    count++;
        }
        if(flag==1)
            cout<<-1<<endl;
        else
            cout<<count<<endl;
    }       
}