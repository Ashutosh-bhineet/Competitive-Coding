#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=8;
    int arr[]={5,7,3,2,11,3,5,2};
    int temp=0;
    for(int i=0;i<n;i++){
        temp=arr[i]^temp;
    }
    int res=temp;
    int count=0;
    while(!((temp>>count)&1)){
        count++;
    }
    int a=0;
    for(int i=0;i<n;i++){
        if((arr[i]>>count)&1){
                a=a^arr[i];
        }
    }
    cout<<a<<" "<<(temp^a);
}