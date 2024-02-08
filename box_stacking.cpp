#include <bits/stdc++.h>
using namespace std;
class Box{
    public:
        int l;
        int w;
        int h;
        Box(int len,int wid,int hei){
            l=len;
            w=wid;
            h=hei;
        }
};
bool cmp(Box a,Box b){
    return a.l>b.l;
}
int main(){
    int n=5;
    vector<Box> arr;
    for(int i=0;i<n;i++){
        int l,b,h;
        cin>>l>>b>>h;
        Box bo(l,b,h);
        arr.push_back(bo);
    }
    sort(arr.begin(),arr.end(),cmp);
    vector<int> dp(n,0);
    dp[0]=arr[0].h;
    int ans=arr[0].h;
    for(int i=1;i<n;i++){
        dp[i]=arr[i].h;
        for(int j=i-1;j>=0;j--){
            if(arr[j].w>arr[i].w){
                dp[i]=max(dp[i],dp[j]+arr[i].h);
            }
        }
        ans=max(dp[i],ans);
    }
    cout<<ans;
}