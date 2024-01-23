#include<bits/stdc++.h>
using namespace std;
vector<int> leftSmaller(int n, int a[]){
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty())
                ans.push_back(-1);
            else if(st.top()<a[i])
                ans.push_back(st.top());
            else{
            while(st.top()>a[i] && !st.empty()){
                st.pop();
            }
            if(!st.empty())
                ans.push_back(st.top());
            else
                ans.push_back(-1);
            }
            st.push(a[i]);
        }
        return ans;
    }
int main(){
    int n=6;
    int arr[]={1,5,0,3,4,5};
    leftSmaller(n,arr);
}