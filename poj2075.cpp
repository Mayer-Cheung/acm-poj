#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;
const int maxn=1000+10;
const int maxm=1000*1000+10;

struct Edge
{
    int u,v;
    double dist;
    Edge(){}
    Edge(int u,int v,double d):u(u),v(v),dist(d){}
    bool operator<(const Edge&rhs)const
    {
        return dist <rhs.dist;
    }
};

struct Kruskal
{
    int n,m;
    Edge edges[maxm];
    int fa[maxn];
    int findset(int x){ return fa[x]==-1? x: fa[x]=findset(fa[x]); }

    void init(int n)
    {
        this->n=n;
        m=0;
        memset(fa,-1,sizeof(fa));
    }

    void AddEdge(int u,int v,double dist)
    {
        edges[m++]=Edge(u,v,dist);
    }

    double kruskal()
    {
        double sum=0;
        int cnt=0;
        sort(edges,edges+m);

        for(int i=0;i<m;i++)
        {
            int u=edges[i].u, v=edges[i].v;
            if(findset(u) != findset(v))
            {
                sum += edges[i].dist;
                fa[findset(u)] = findset(v);
                if(++cnt>=n-1) break;
            }
        }
        if(cnt<n-1) return -1;
        return sum;
    }
}KK;

int main()
{
    map<string,int> mp;
    double max_sum;
    int n,m;
    scanf("%lf%d",&max_sum,&n);
    KK.init(n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        mp[s]=i;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        string s1,s2;
        double x;
        cin>>s1>>s2>>x;
        KK.AddEdge(mp[s1],mp[s2],x);
    }
    double ans = KK.kruskal();
    if(ans==-1 || ans> max_sum) printf("Not enough cable\n");
    else printf("Need %.1f miles of cable\n",ans);
    return 0;
}
