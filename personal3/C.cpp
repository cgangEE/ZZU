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

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
	void in(){ scanf("%d%d", &x, &y); }
	void out(){ printf("%d %d\n", x, y); }
	double dis(const P&p)const{
		return hypot(x-p.x, y-p.y); 
	}
};

int i,j,k,m,n,l;
P c, d, h, o(0,0);

double gaoIt(vp v){
	vi x;
	int n=sz(v);
	rep(i, n) x.pb(i);
	double ret=INT_MAX;

	do{
		double now=0;
		now+=h.dis(v[x[0]])+h.dis(v[x[2]]);
		rep(i, 2) now+=v[x[i]].dis(v[x[i+1]]);
		checkmin(ret, now);
	}
	while (next_permutation(all(x)));
	return ret;
}

double gaoIt2(vp v){
	double ret=INT_MAX;
	n=sz(v);
	vi x, y;
	rep(i, n) x.pb(i);
	rep(i, 2) y.pb(i);

	do{
		do{
			double now=v[x[0]].dis(v[x[2]]);
			rep(i, 2){
				if (y[i]==0){
					P e;
					if (v[x[i]].y*v[x[i+1]].y>0)
						e=P(v[x[i]].x, -v[x[i]].y);
					else 
						e=v[x[i]];
					now+=e.dis(v[x[i+1]]);
				}
				else if (y[i]==1){
					P e;
					if (v[x[i]].x*v[x[i+1]].x>0)
						e=P(-v[x[i]].x, v[x[i]].y);
					else
						e=v[x[i]];
					now+=e.dis(v[x[i+1]]);
				}
			}
			checkmin(ret, now);

			now=v[x[0]].dis(v[x[2]])+v[x[1]].dis(v[x[2]]);
			P e=v[x[0]];
			if (v[x[0]].x * v[x[1]].x>0) e.x*=-1;
			if (v[x[0]].y * v[x[1]].y>0) e.y*=-1;
			now+=e.dis(v[x[1]]);
			checkmin(ret, now);
		}while (next_permutation(all(y)));
	}
	while (next_permutation(all(x)));
	return ret;
}

double gao(){
	vp v; v.pb(c), v.pb(d), v.pb(o);
	double ret=gaoIt(v);
	v.clear();
	v.pb(c), v.pb(h), v.pb(d);
	checkmin(ret, gaoIt2(v));
	return ret;
}

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		c.in(), d.in(), h.in();
		printf("%.2lf\n", gao());
	}
	return 0;
}

