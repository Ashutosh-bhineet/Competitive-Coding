#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> oddsum(n);
        vector<int> evensum(n);
        oddsum[0]=0;
        evensum[0]=arr[0];
        for(int i=1;i<n;i++){
            if(i%2==0){
                evensum[i]=evensum[i-1]+arr[i];
                oddsum[i]=oddsum[i-1];
            }
            else{
                evensum[i]=evensum[i-1];
                oddsum[i]=oddsum[i-1]+arr[i];
            }
        }
        int even=evensum[n-1];
        int odd=oddsum[n-1];
        int count=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(evensum[n-1]-arr[i]==oddsum[n-1])
                    count++;
            }
            else{
                int s=evensum[i-1]+oddsum[n-1]-oddsum[i];
                int t=oddsum[i-1]+evensum[n-1]-evensum[i];
                if(s==t)
                    count++;
            }
        }
        return count;
    }
// 4 3 2 7 6 -2
// 4 4 6 6 12 12
// 0 3 3 10 10 8
