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
#define N 25

template<int SZ>
struct UFS{
	int f[SZ+10];
	void clear(){ rep(i, SZ+10) f[i]=i; }
	int find(int i){
		if (f[i]==i) return i;
		return f[i]=find(f[i]);
	}
	void unions(int i, int j){
		i=find(i), j=find(j);
		f[i]=j;
	}
};

int i,j,k,m,n,l;
int a[N+10];
int e[N+10][N+10];
UFS<N> ufs;
vi v;

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
	bool operator <(const P&p)const{
		return e[x][y]<e[p.x][p.y];
	}
};

int g(int i){
	int ret=0;
   	v.clear();
	rep(j, n) if ((1<<j)&i) v.pb(j+1), ret++;
	return ret;
}

bool lt(int i, int j){
	rep(k, n){
		bool f=((1<<k)&i), g=((1<<k)&j);
		if (f && !g) return true;
		if (!f && g) return false;
	}
	return true;
}

int main(){
	while (~scanf("%d%d", &n, &m) && n+m){
		repf(i, 1, n) scanf("%d", &a[i]);
		repf(i, 1, n) repf(j, 1, n) scanf("%d", &e[i][j]);

		int ans=0;
		P now;
		rep(i, 1<<n) if (g(i)==m){
			P p(0, 0);
			vp es;

			rep(j, sz(v)) p.y+=a[v[j]];
			rep(j, sz(v)) rep(k, sz(v)) es.pb(P(v[j], v[k]));

			sort(all(es));
			l=0;

			ufs.clear();
			rep(j, sz(es)) 
				if (ufs.find(es[j].x)!=ufs.find(es[j].y)){
					ufs.unions(es[j].x, es[j].y);
					p.x+=e[es[j].x][es[j].y];
					if (++l==m-1) break;
				}

			if (ans==0 || p.x*now.y<now.x*p.y)
				ans=i, now=p;
			else if (p.x*now.y==now.x*p.y && lt(i, ans))
				ans=i;
		}


		rep(j, n) if ((1<<j)&ans)
			printf("%d%c", j+1, --m?' ':'\n');
	}
	return 0;
}


