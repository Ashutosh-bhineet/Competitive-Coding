#include <bits/stdc++.h>
using namespace std;
int get_i_bit(int n,int i){
    return ((n>>i)&1);
}
 void set_i_bit(int &n,int i){
    n=((1<<i)|n);
}
void clear_i_bit(int &n,int i){
    n=(n&(~(1<<i)));
}
void update_i_bit(int &n,int i,int v){
    if(v==0)
        clear_i_bit(n,i);
    else
        set_i_bit(n,i);
}
int count_set_bit(int n){
    int count=0;
    cout<<n<<" ";
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}
void clear_range_bit(int &n,int i,int j){
    int a=(~0)<<(i+1);
    int b=(1<<j)-1;
    a=a|b;
    n= n&a;
}
int main(){
    int n=404;
    int i=1;
    /* cout<<get_i_bit(n,i)<<endl;
    set_i_bit(n,1);
    cout<<get_i_bit(n,i)<<endl;
    clear_i_bit(n,1);
    cout<<get_i_bit(n,i)<<endl;
    update_i_bit(n,i,1);
    cout<<get_i_bit(n,i)<<endl; */
    cout<<count_set_bit(n)<<endl;
    clear_range_bit(n,2,6);
    cout<<count_set_bit(n)<<endl;
}