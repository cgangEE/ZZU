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
#define N 100

struct P{
	int to, w;
	P(){}
	P(int to, int w):to(to),w(w){}
};

int i,j,k,m,n,l,x,y;
bool v[N+10], inq[N+10];
vp a[N+10];
int d[N+10];

void spfa(){
	clr(d, -1); queue<int> que; clr(inq, 0);
	d[0]=0, que.push(0), inq[0]=1;

	while (sz(que)){
		int i=que.front(); que.pop();
		inq[i]=false;

		rep(k, sz(a[i])){
			int j=a[i][k].to;
			if (d[j]==-1 || d[i]+a[i][k].w<d[j]){
				d[j]=d[i]+a[i][k].w;
				if (!inq[j])
					inq[j]=1, que.push(j);
			}
		}
	}
}

int main(){
	while (~scanf("%d", &n)){
		clr(v, 0);
		rep(i, n){
			a[i].clear();
			scanf("%d%d", &j, &k);
			v[i]=(k==1);
			while (j--){
				scanf("%d%d", &x, &y);
				a[i].pb(P(x,y));
			}
		}
		spfa();
		int ret=-1;
		rep(i, n) if (v[i] && d[i]!=-1 ) _checkmin(ret, d[i]);
		printf("%d\n", ret);

	}
	return 0;
}

