#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    int marks;
    Student(string n,int m){
        name=n;
        marks=m;
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<Student>> m(400);
    for(int i=0;i<n;i++){
        string name;
        int marks;
        cin>>name>>marks;
        Student a(name,marks);
        m[marks].push_back(a);
    }
    int rank=1;
    cout<<"Ranks are: "<<endl;
    for(int i=399;i>=0;i--){
        int count=0;
        for(int j=0;j<m[i].size();j++){
            cout<<m[i][j].name<<" "<<m[i][j].marks<<" "<<rank<<endl;
            count++;
        }
        rank+=count;
    }
}