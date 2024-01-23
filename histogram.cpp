#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &heights){
    stack<pair<int,int>> st;
    int n=heights.size();
    vector<int> prev_small;
    vector<int> next_small(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first>=heights[i]){
            st.pop();
        }
        if(st.empty())
            prev_small.push_back(-1);
        else
            prev_small.push_back(st.top().second);
        st.push(make_pair(heights[i],i));
    }
    while(!st.empty())
        st.pop();
    next_small[n-1]=n;
    st.push(make_pair(heights[n-1],n-1));
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top().first>=heights[i]){
            st.pop();
        }
        if(st.empty())
            next_small[i]=-1;
        else
            next_small[i]=st.top().second;
        st.push(make_pair(heights[i],i));
    }
    int area=0;
    for(int i=0;i<n;i++){
        area=max(area,heights[i]*(next_small[i]-prev_small[i]-1));
    }
    return area;
}
int largestRectangleArea(vector<int>& heights) {
         stack<int> s1;
        int res = 0, n = heights.size();
        
        for(int i=0; i<=n; i++){
            while(!s1.empty() and (i==n || heights[s1.top()] >= heights[i])){
                int len = heights[s1.top()];
                s1.pop();
                
                int bre;
                if(s1.empty()) bre = i;
                else bre = i - s1.top() - 1;
                res = max(res, len*bre);
            }
            
            s1.push(i);
        }
        
        return res;
    }
int main(){
    vector<int> arr={2,1,5,6,2,3};
    cout<<largestRectangleArea(arr);
    cout<<endl<<solve(arr);
}