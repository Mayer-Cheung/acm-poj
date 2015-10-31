//  other's code
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define N 35
#define inf 999999999

struct node{
	int y;
	double r;
};

map<string,int>ma;
vector<node>ve[N];
int visited[N];
double dis[N];
int up[N];
int n;

int SPFA(int u){
	memset(visited,0,sizeof(visited));
	memset(dis,0,sizeof(dis));
	memset(up,0,sizeof(up));
	int i, j, k, v;
	node p, q;
	queue<int>Q;
	Q.push(u);
	visited[u]=1;
	dis[u]=1000;
	while(!Q.empty()){
		v=Q.front();
		Q.pop();
		visited[v]=0;
		for(i=0;i<ve[v].size();i++){
			p=ve[v][i];
			if(dis[p.y]<dis[v]*p.r){
				dis[p.y]=dis[v]*p.r;
				if(!visited[p.y]){
					visited[p.y]=1;
					Q.push(p.y);
				}
				up[p.y]++;
				if(up[p.y]>=n) return 1;
			}
		}
	}
	return 0;
}

main()
{
    int i, j, k, m, x, y, kase=1;
    double z;
	string s1, s2;
	node p;
	while(scanf("%d",&n)==1&&n){
		ma.clear();
		k=1;
		for(i=1;i<=n;i++){
			ve[i].clear();
			cin>>s1;
			ma[s1]=k++;
		}
		scanf("%d",&m);
		while(m--){
			cin>>s1>>z>>s2;
			x=ma[s1];
			p.y=ma[s2];p.r=z;
			ve[x].push_back(p);
		}
		int f=0;
		for(i=1;i<=n;i++){
			if(SPFA(i)){
				f=1;printf("Case %d: Yes\n",kase++);break;
			}
		}
		if(!f) printf("Case %d: No\n",kase++);
	}	
}