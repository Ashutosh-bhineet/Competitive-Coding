#include<bits/stdc++.h>
using namespace std;
#define int long long int
int get_random(int a,int b){
    /* random_device rand;  
    mt19937 gen(rand());  
    uniform_int_distribution<>dis(a,b);  
    int random_number = dis(gen);   
    return random_number; */
    srand(time(0));
    return (rand()%(b-a+1))+a;
}
void shuffle(int arr[],int n){
    for(int i=n-1;i>0;i--){
        int r=get_random(0,i-1);
        swap(arr[i],arr[r]);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int32_t	 main(){
    int arr[5]={1,2,3,4,5};
    print(arr,5);
    shuffle(arr,5) ;
    cout<<endl;
    print(arr,5);
}