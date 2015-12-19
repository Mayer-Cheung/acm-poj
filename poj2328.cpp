#include<iostream>
#include<string>
using namespace std;
int main()
{
    int high,low;
    int a;
    string b,c;
    while(1)
    {
        high=11;
        low=0;
        while(cin>>a)
        {
            if(a==0)return 0;
            cin>>b>>c;
            if(c=="high")
            {
                if(a<high)high=a;
            }
            else if(c=="low")
            {
                if(a>low)low=a;
            }
            else if(c=="on")
            {
                break;
            }
        }
        if(a>=high||a<=low)cout<<"Stan is dishonest"<<endl;
        else cout<<"Stan may be honest"<<endl;
    }
    return 0;
}