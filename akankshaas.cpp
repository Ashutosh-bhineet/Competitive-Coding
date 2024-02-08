#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int flag=1;
    int i=0;
    if(s[0]=='-')
    {
        flag=-1;
        i=1;
    }
    int num=0;
    while(i<s.size())
    {
        if(s[i]>='0'&&s[i]<='9')
        {
          num=num*10+s[i]-'0';// 121
          i++;
        }
        else
        {
             cout<<-1<<endl;
            return 0;
            
        }
    }
     cout<<num*flag<<endl;
}