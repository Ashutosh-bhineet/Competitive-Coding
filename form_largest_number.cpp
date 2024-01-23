#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool comparator(int a,int b){
    return (to_string(a)+to_string(b))>(to_string(b)+to_string(a));
}
string solve(vector<int> arr,int n){
    sort(arr.begin(),arr.end(),comparator);
    string ans="";
    for(int i=0;i<n;i++){
        ans+=to_string(arr[i]);  
    }
    return ans;
}
int32_t main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);   
    }
    cout<<solve(arr,n);
}