#include <bits/stdc++.h>
using namespace std;
int TotalPairs(vector<int>nums, int k){
	    int count=0;
	    int i=0,j=i+1;
	    sort(nums.begin(),nums.end());
	    set<vector<int>> s;
	    while(i<=j && j<nums.size() && i<nums.size()){
	        if(i==j)
	            j++;
	        else if(nums[j]-nums[i]==k){
	            s.insert({nums[i],nums[j]});
	            i++;
	            j++;
	        }
	        else if(nums[j]-nums[i]>k){
	            i++;
	        }
	        else{
	            j++;
	        }
	    }
	    return s.size();
	}