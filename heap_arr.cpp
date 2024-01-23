#include<bits/stdc++.h>
using namespace std;
#define int long long int
void heapify(int arr[],int n,int idx){
    int L=2*idx;
    int R=L+1;
    int mx=idx;
    if(L<n && arr[idx]<arr[L])
        mx=L;
    if(R<n && arr[mx]<arr[R])
        mx=R;
    if(mx!=idx){
        swap(arr[idx],arr[mx]);
        heapify(arr,n,mx);
    }
}
void build_heap(int arr[],int n){
    int start_index=n/2-1;
    for(int i=start_index;i>=0;i--){
        heapify(arr,n,i);
    }
}
void heap_sort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}
int32_t	 main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }       
    build_heap(arr,n);
    heap_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}