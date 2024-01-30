#include<bits/stdc++.h>
using namespace std;
#define int long long int
void bubble_sort(int arr[],int n){
    if(n==1)
        return;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    } 
    bubble_sort(arr,n-1);
}
void another(int arr[],int i,int n){
    if(n==1 || n==0)
        return ;
    if(i==n-1){
        another(arr,0,n-1);
        return ;
    }
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
    another(arr,i+1,n);
}
void bubblyyy(int arr[],int i,int n){
    if(n==1 || i==n-1)
        return ;
    if(i<n-1){
    if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    bubblyyy(arr,i+1,n);
    }
    bubblyyy(arr,0,n-1);
}
int32_t	 main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    /* for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    } */
    //bubble_sort(arr,n);
    another(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }       
}