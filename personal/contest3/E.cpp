#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 1000

struct P{
	int to, c;
	P(){}
	P(int to, int c):to(to), c(c){}
};

int i,j,k,m,n,l;
vp a[N+10];
int x[N+10];
int ans;

bool dfs(int i, int fa){
	bool ret=x[i];
	rep(k, sz(a[i])) if (a[i][k].to!=fa){
		if (dfs(a[i][k].to, i)) 
			ans+=a[i][k].c, ret=true;
	}
	return ret;
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		clr(x, 0);
		rep(i, m){
			scanf("%d", &k);
			x[k]=1;
		}
		repf(i, 1, n) a[i].clear();
		rep(i, n-1){
			scanf("%d%d%d", &j, &k, &l);
			a[j].pb(P(k, l)), a[k].pb(P(j, l));
		}
		ans=0;
		repf(i, 1, n) if (x[i]){
			dfs(i, -1);
			break;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}


