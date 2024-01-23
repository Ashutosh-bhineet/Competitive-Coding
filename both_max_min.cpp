#include <bits/stdc++.h>
using namespace std;
int solve(int n,int arr[],int max,int minn){
    int a=-1,b=-1;
    int ans=INT_MAX;
    if(max==minn)
        return 1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]==max){
            a=i;
        }
        else if(arr[i]==minn){
            b=i;
        }
        if(a!=-1 && b!=-1)
        ans=min(abs(a-b)+1,ans);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=INT_MIN,minn=INT_MAX;
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
                max=arr[i];
        }
        if(arr[i]<minn)
            minn=arr[i];
    }
    cout<<solve(n,arr,max,minn)<<endl;
    if(max==minn){
        cout<<1;
        return 0;
    }
    int start=-1,prev=-1;
    for(int i=0;i<n;i++){
        if(start!=-1){
            if(prev==max){
                if(arr[i]==minn){
                    ans=min(ans,i-start+1);
                    prev=minn;
                    start=i;
                }
                else if(arr[i]==max){
                    start=i;
                }
            }
            else{
                if(arr[i]==max){
                    ans=min(ans,i-start+1);
                    prev=max;
                    start=i;
                }
                else if(arr[i]==minn)
                    start=i;
            }
        }
        else{
            if(arr[i]==max || arr[i]==minn){
                start=i;
                prev=arr[i];
            }
        }
    }
    cout<<ans;
}