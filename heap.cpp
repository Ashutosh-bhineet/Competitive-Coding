#include <bits/stdc++.h>
using namespace std;
class Heap{
    vector<int> arr;
    int last;
    void heapify(int idx){
        int L=2*idx;
        int R=L+1;
        int mx=idx;
        if(L<arr.size() && arr[idx]<arr[L])
            mx=L;
        if(R<arr.size() && arr[mx]<arr[R])
            mx=R;
        if(mx!=idx){
            swap(arr[idx],arr[mx]);
            heapify(mx);
        }
    }
    public:
    void push(int x){
        if(arr.size()==0){
            arr.push_back(x);
            last=0; 
        }
        last++;
        arr.push_back(x);
        int i=last;
        while(i>1){
            int parent=i/2;
            if(arr[parent]<x){
                swap(arr[parent],arr[i]);
                i=parent;
            }
            else{
                break;
            }
        }
    }
    int top(){
        return arr[1];
    }
    void print(){
        for(int i=1;i<=last;i++){
            cout<<arr[i]<<" ";
        }
    }
    void pop(){
        swap(arr[1],arr[last]);
        last--;
        arr.pop_back();
        heapify(1);
    }
    bool isEmpty(){
        if(arr.size()==1)
            return true;
        return false;
    }
};
int main(){
    int n;
    cin>>n;
    Heap H;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        H.push(x);
    }
    cout<<"Top element is: "<<H.top()<<endl;
    while(!H.isEmpty()){
        cout<<H.top()<<" ";
        H.pop();
    }
}