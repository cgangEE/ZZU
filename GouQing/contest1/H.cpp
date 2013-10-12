#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

#define clr(a, b) memset(a, b, sizeof(a))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define sz(a) ((int)(a).size())
#define pb push_back
#define N 2000
#define M 10


int i,j,k,m,n,l;
vector<int> a[N+10];
int d[N+10];

void bfs(int e){
	queue<int> q; clr(d, -1);
	q.push(e), d[e]=0;

	while (sz(q)){
		int i=q.front(); q.pop();
		rep(k, sz(a[i])){
			int j=a[i][k];
			if (d[j]!=-1) continue;
			d[j]=d[i]+1;
			q.push(j);
		}
	}
}

int solve(){
	bfs(0);
	rep(i, n) if (d[i]==-1) return -1;

	int ret=0;
	rep(i, n){
		bfs(i);
		rep(j, n)
			ret=max(ret, d[j]);
	}
	return ret;
}

int main(){
while (~scanf("%d", &n) && n){
		rep(i, n) a[i].clear();
		string s, x, y;
		map<string, int> mp;
		rep(i, n) cin>>s, mp[s]=i;

		scanf("%d", &m);
		while (m--){
			cin>>x>>y;
			int i=mp[x], j=mp[y];
			a[i].pb(j), a[j].pb(i);
		}
		printf("%d\n", solve());
	}
	return 0;
}

