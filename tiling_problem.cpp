#include<bits/stdc++.h>
using namespace std;
long long numberOfWays(long long n) {
        if(n==2)
            return 2;
        if(n==1)
            return 1;
        if(n<0)
            return 0;
        return (numberOfWays(n-1)%1000000007+numberOfWays(n-2)%1000000007)%1000000007;
    }