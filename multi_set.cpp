#include <bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> my;
    my.insert(19);
    my.insert(19);
    my.insert(30);
    my.insert(20);
    my.insert(40);
    auto it=my.lower_bound(19);
    cout<<*it;
}