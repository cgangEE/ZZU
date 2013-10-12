#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 100

char s[10];
int d[]={'m', 's', 'p', 'c'};

struct P{
	int i, j;
	P(){}
	P(int i, int j):i(i),j(j){}
	void in(){
		scanf("%s", s);
		i=s[0]-'0';
		rep(k, 4) if (d[k]==s[1]) j=k;
	}
	void out(){
		printf(" %d%c", i, d[j]);
	}
};

int i,j,k,m,n,l;
P a[N+10];
int c[9+10][4], b[9+10][4];


bool dfs(int d, bool v){
	if (d>=14){
		return d==14 && v;
	}
	rep(j, 4) repf(i, 1, 9) if (c[i][j]){
		if (c[i][j]>=3){
			c[i][j]-=3;
			if (dfs(d+3, v)) return true;
			c[i][j]+=3;
		}
		if (j!=3 && c[i][j] && c[i+1][j] && c[i+2][j]){
			c[i][j]--, c[i+1][j]--, c[i+2][j]--;
			if (dfs(d+3, v)) return true;
			c[i][j]++, c[i+1][j]++, c[i+2][j]++;
		}
		if (c[i][j]>=2 && !v){
			c[i][j]-=2;
			if (dfs(d+2,1)) return true;
			c[i][j]+=2;
		}
		return false;
	}
	return false;
}

bool gao(){
	int ret=0;
	rep(j, 4) repf(i, 1, 9)
		if (c[i][j]!=2 && c[i][j]!=0) return false;
	return true;
}

bool gao2(){
	bool flag=false;
	repf(i, 1, 7){
	   	if (!c[i][3]) return false;
		if (c[i][3]>1) flag=true;
	}
	rep(j, 3){
	   	if (!c[1][j] || !c[9][j]) return false;
		if (c[1][j]>1 || c[9][j]>1) flag=true;
	}
	return flag;
}

bool ok(){
	clr(c, 0);
	rep(i, 14){
  	 	c[a[i].i][a[i].j]++;
		if (c[a[i].i][a[i].j]>4) return false;
	}
		
	
	if (gao()) return true;
	if (gao2()) return true;
	if (dfs(0, 0)) return true;

	return false;
}

void gao(vector<P> & ret){
	rep(j, 4) repf(i, 1, 9){
		if (j==3 && i>7) break;
		a[13]=P(i, j);
		if (ok()) ret.pb(P(i,j));
	}
}

int main(){
	int ts;
	scanf("%d", &ts);
	while(ts--){
		rep(i, 13) a[i].in();
		vector<P> ret;
		gao(ret);
		if (sz(ret)){
			printf("%d", sz(ret));
			rep(i, sz(ret)) ret[i].out();
			putchar('\n');
		}
		else puts("Nooten");
	}
}

