#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    string arr[k];
    arr[0]="1",arr[1]="5",arr[2]="7";
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" ";
    int i=3,j=0;
    int count=0;
   while(i<k){
    if(count==3){
        j=j+1;
        count=0;
    }
        arr[i]=arr[j]+arr[count];
        cout<<arr[i++]<<" ";
        count++;
   }
   cout<<endl;
   cout<< arr[k-1];
} 