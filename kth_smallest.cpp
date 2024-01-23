#include<bits/stdc++.h>
using namespace std;
#define int long long int
int partion(int arr[],int start,int end){
    int pivot=arr[end];
    int i=start-1;
   for(int j=start;j<=end;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}
int quickFix(int arr[],int low,int high,int k){
        if(low<=high){
        int pi=partion(arr,low,high);
        if(pi==k-1)
            return arr[pi];
        else if(k-1<pi){
         return quickFix(arr,low,pi-1,k);
        }
        else{
         return quickFix(arr,pi+1,high,k);
        }
        }
        return -1;
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int32_t	 main(){
    int arr[]={2,1,4,7,3};
    int n=5;  
    int k;
    cin>>k; 
    print(arr,n);
    cout<<quickFix(arr,0,4,k)<<endl;     
}