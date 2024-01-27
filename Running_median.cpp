#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
    priority_queue<int,vector<int>,greater<int>> min_heap;
    priority_queue<int> max_heap;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>,greater<pair<int,pair<int,int>>>>> pq;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
       if(max_heap.empty() && min_heap.empty()){
            max_heap.push(num);
            return;}
        else if(!max_heap.empty()){
            if(max_heap.top()<num)
                min_heap.push(num);
            else
                max_heap.push(num);
        }
        else if(!min_heap.empty()){
            if(min_heap.top()<num)
                min_heap.push(num);
            else
                max_heap.push(num);
        }
        int x=min_heap.size();
        int y=max_heap.size();
        if(abs(x-y)>1){
        if(y>x){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else{
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        }
    }
    
    double findMedian() {
        if(max_heap.empty() && min_heap.empty())
            return -1;
        if(max_heap.size()==min_heap.size())
            return (max_heap.top()+min_heap.top())/2.0;
        else if(max_heap.size()>min_heap.size())
            return max_heap.top()*1.0;
        else 
            return min_heap.top()*1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main(){
    MedianFinder medianFinder;
    medianFinder.addNum(-1);    // arr = [1]
    cout<<medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(-2);    // arr = [1, 2]
    cout<<medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(-3);    // arr[1, 2, 3]
    cout<<medianFinder.findMedian();
    medianFinder.addNum(-4);    // arr[1, 2, 3]
    cout<<medianFinder.findMedian();
    medianFinder.addNum(-5);    // arr[1, 2, 3]
    cout<<medianFinder.findMedian();
}