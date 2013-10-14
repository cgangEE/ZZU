#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define N 500000

struct P{
	int to, w;
	P *next;
};

int i,j,k,m,n,l,x,y;
P pool[N+10], *a[N+10];
int d[N+10], idx;

int gao(int i, bool v){
	if (a[i]==NULL) return (d[i]>=x && d[i]<=y)?d[i]:-1;
	int ret=-1;
	for (P *p=a[i]; p; p=p->next){
		int j=p->to;
		d[j]=d[i]+p->w;
		int l=gao(j, !v);
		if (l==-1) continue;
		if (v) _checkmax(ret, l);
		else _checkmin(ret, l);
	}
	return ret;
}

void add(int j, int k, int l){
	P *p=pool+(idx++);
	p->to=k, p->w=l, p->next=a[j];
	a[j]=p;
}

int main(){
	while (~scanf("%d%d%d", &n, &x, &y)){
		rep(i, n) a[i]=NULL;
		idx=0;

		rep(i, n-1){
			scanf("%d%d%d", &j, &k, &l);
			add(j, k, l);
		}
		int k=gao(0, 1);
		if (k==-1) puts("Oh, my god!");
		else printf("%d\n", k);
	}
	return 0;
}

