#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> temp;//2 1 3 // 1 3 5 8 9
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        vector<long long> ans;
        sort(temp.begin(),temp.end());
        vector<long long> prefi_sum(n,0);
        prefi_sum[0]=0;
        for(int i=1;i<n;i++){
            prefi_sum[i]=temp[i]+prefi_sum[i-1];//0 1 4 9 17 
        }
        for(int i=0;i<n;i++){
            int lb=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            ans.push_back(prefi_sum[lb]);
        }
        return ans;
    }
int32_t	 main(){
        vector<int> arr={3,5,1,8,9};
        smallerSum(5,arr);
}