#include <bits/stdc++.h>
using namespace std;
 bool check(int n,int a,int b,int mid){
        long long int mod=1e9+7;
        long long int first_a=mid/a;
        long long int second_b=mid/b;
        long long int third=mid/(a*b)%mod/__gcd(a,b);
        long long int sum=(a+b-third)%mod;
        return sum>=n;
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long int mod=1e9+7;
        long long int start=1,end=n*(a*b)%mod;
        long long int mid=-1;
        long long int ans;
        while(start<=end){
            long long int mid=start+(end-start)/2;
            if(check(n,a,b,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
int main(){
    cout<<nthMagicalNumber(5,2,4);
}