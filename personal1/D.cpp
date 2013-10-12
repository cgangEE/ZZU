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
#define N 10000

#define eps 1e-8
int sgn(double d){
	return d<-eps?-1:d>eps;
}

struct P{
	double x, y;
	P(){}
	P(double x, double y):x(x),y(y){}
	P operator +(const P&p)const{ return P(x+p.x, y+p.y); }
	P operator -(const P&p)const{ return P(x-p.x, y-p.y); }
	
	P operator *(double k){ return P(x*k, y*k); }
	P operator /(double k){ return P(x/k, y/k); }

	P rot(){ return P(-y, x); }

	double operator *(const P&p)const { return x*p.y-y*p.x; }
	double operator ^(const P&p)const { return x*p.x+y*p.y; }

	bool in(){
		return ~scanf("%lf%lf", &x, &y); 
	}

};

int i,j,k,m,n,l;
P a[3];

bool init(){
	double ret=0;
	rep(i, 3){
		if (!a[i].in()) return false;
		ret+=a[i].x+a[i].y;
	}
	return !(sgn(ret)==0);
}

P getSection(P p, P v, P q, P w){
	P u=p-q;
	double t=(w*u)/(v*w);
	return p+v*t;
}

bool onSeg(P p, P a1, P a2){
	return sgn((a1-p)*(a2-p))==0 && sgn((a1-p)^(a2-p))<0;
}

vp cutPoly(vp poly, P A, P u){
	vp ret;
	int n=sz(poly);
	rep(i, sz(poly)){
		P C = poly[i], D = poly[(i+1)%n];
		if (sgn(u*(C-A))>=0) ret.pb(C);
		if (sgn(u*(C-D))!=0){
			P p = getSection(A, u, C, D-C);
			if (onSeg(p, C, D)) ret.pb(p);
		}
	}

	return ret;
}

double polyArea(vp poly){
	double ret=0;
	rep(i, sz(poly)-2){
		ret+=(poly[i+1]-poly[0])*( poly[i+2]-poly[0]);
	}
	return ret/2;
}

int main(){
	while (init()){
		vp poly;
		poly.pb(P(0, 0)), poly.pb(P(N, 0)), 
		poly.pb(P(N, N)), poly.pb(P(0, N));
		repf(i, 1, 2){
			poly = cutPoly(poly, (a[0]+a[i])/2, (a[i]-a[0]).rot() );
		}
		printf("%.3lf\n", polyArea(poly)/1e8);
	}
	return 0;
}


