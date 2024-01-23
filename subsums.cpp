#include <bits/stdc++.h>
using namespace std;
vector<int> s(int arr[],int k,int n){
    vector<int> sum;
     for(int i=0;i<(1<<n);i++){
        int total=0;
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0)
                total+=arr[j+k];
        }
        sum.push_back(total);
    }
    return sum;
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> sum1,sum2;
    sum1=s(arr,0,n/2);
    sum2=s(arr,n/2,(n&1)?(n/2)+1:n/2);
    long long int sum=0;
    sort(sum2.begin(),sum2.end());
    for(int i=0;i<sum1.size();i++){
        int lo=lower_bound(sum2.begin(),sum2.end(),a-sum1[i])-sum2.begin();
        int up=upper_bound(sum2.begin(),sum2.end(),b-sum1[i])-sum2.begin();
        sum=sum+(up-lo);
    }
    cout<<sum<<endl;
}