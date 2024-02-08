#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pre_min[n];
    pre_min[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        pre_min[i]=min(pre_min[i+1],arr[i]);
    }
    int k;
    cin>>k;
    int ans=INT_MAX;
    for(int i=0;i<=n-k;i++){
        ans=min(ans,arr[i]*pre_min[i+k-1]);
    }
    cout<<ans;
}
// 6
// 1 2 3 4 5 

3/2(2+4)

1/2(4+2)

//5
//1 2 3 4 5