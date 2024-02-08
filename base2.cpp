#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t	 main(){
    int n;
    cin>>n;
    int a=log2(n);
    cout<<min(n-pow(2,a),pow(2,a+1)-n)<<endl;
}