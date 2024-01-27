#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t	 main(){
    while(true){
    int n;
    cin>>n;
    if(n==-1)
        break;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }       
    int pre_sum[n];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        pre_sum[i]=sum;
    }
    sum=0;
    if(pre_sum[n-1]%n!=0)
        cout<<-1<<endl;
    else{
        int ans=0;
        int sum=0;
        int req=pre_sum[n-1]/n;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            ans=max(ans,abs(sum-(req)*(i+1)));
        }
        cout<<ans<<endl;
    }
    }
}