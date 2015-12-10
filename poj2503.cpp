#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;
map<string, string> mp;

int main()
{
//freopen("in", "r", stdin);
    string a, b, f, tmp;
    char t;
    int pos;
    while(1) {
    //puts("*");
    a.clear();
        char t = getchar();
        if(t == '\n') break;
        a += t;
        cin>>tmp;
        a += tmp;
        //cout<<a<<endl;
        cin>>b;
        getchar();
        mp[b] = a;
    }
    while(cin>>f) {
        map<string, string>::iterator it;
        it = mp.find(f);
        if(it == mp.end()) printf("eh\n");
        else cout<<mp[f]<<endl;

    }
    return 0;
}