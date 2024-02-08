#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    if(s.empty() || t.empty() || s.length()<t.length()){
        return "";
    }
    unordered_map<char,int> mp;
    int count=t.length();
    int start=0,end=0,minLen=INT_MAX,startIndex=0;
    for(char c:t){
        mp[c]++;
    }
    while(end<s.length()){
        if(mp[s[end++]]-->0){
            count--;
        }
        while(count==0){
            if(end-start<minLen){
                startIndex=start;
                minLen=end-start;
            }
            if(mp[s[start++]]++==0)
                count++;
        }
    }
    return minLen==INT_MAX?"":s.substr(startIndex,minLen);
}
int main(){
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<minWindow(s,t);
}