#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cctype>
using namespace std;

template <class T> T checkmax(T &a, T b){ if (a==-1 || b>a) a=b; }
template <class T> T checkmin(T &a, T b){ if (a==-1 || b<a) a=b; }
typedef vector<int> vi;
typedef long long ll;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back
#define N 10000
#define INF (1ll<<62)

int i,j,k,m,n,l;
ll L[N+10], R[N+10];
vi a[N+10];

bool dfs(int i){
	ll l=0;
	rep(k, sz(a[i])){
		int j = a[i][k];
		if (!dfs(j)) return false;
		l+=L[j];
	}
	checkmax(L[i], l+1);
	if (L[i]>R[i]) return false;
	return true;
}

bool gao(){
	
	fill(L+1, L+1+n, 1ll), fill(R+1, R+1+n, INF);
	while (m--){
		scanf("%d", &i);
		char ch=getchar();
		while (strchr("=<>", ch)==NULL) ch=getchar();
		scanf("%d", &j);

		if (ch=='='){
			checkmax(L[i], (ll)j);
			checkmin(R[i], (ll)j);
		}
		else if (ch=='<') checkmin(R[i], j-1ll);
		else if (ch=='>') checkmax(L[i], j+1ll);
	}
	return dfs(1);
}

int main(){
	while (~scanf("%d", &n)){
		repf(i, 1, n) a[i].clear();
		repf(i, 2, n) scanf("%d", &k), a[k].pb(i);
		scanf("%d", &m);
		puts(gao()?"True":"Lie");
	}
	return 0;
}

