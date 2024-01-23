#include <bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        if(nums.size()==1 && nums[0]==target)
            return true;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[start]==nums[end]){
                start++;
                end--;
            }
            else if(nums[mid]>nums[end]){
                if(target>nums[end]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(nums[mid]<target && nums[start]<target)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return false;
    }
int main(){
    int n;
    cin>>n;
    vector<int> arr{1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1};
    cout<<search(arr,13)<<endl;
}