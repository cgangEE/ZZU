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

int i,j,k,m,n,l;

#define ft(x) (sqrt(1.-(x)*(x)))
#define eps 1e-7

int sgn(double d){
	return d<-eps?-1:d>eps;
}

double h, d, v;

double gao1(double x){
	return 0.5*(1.-d/4)*(x*ft(x)-atan(x/ft(x)));
}

double gao2(double x){
	return d*4./18*(-2*x*x-3*x*ft(x)+3*atan(x/ft(x))+6*x*x*x*log(1+ft(x)));
}

double gao3(double x){
	return d/4.*(log(x)/3.*x*x*x-x*x*x/9.);
}

double xxx;

double gaoit(double z){
	return gao2(d/2)-gao2(d/2)+gao3(d/2);
}

double gao(double z){
	return (xxx-gaoit(z))*2*h;
}


int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%lf%lf%lf", &h, &d, &v);
		xxx=gaoit(d/2);
		cout<<2*h<<xxx<<endl;
		double x=0, y=d/2;
		while (sgn(y-x)>0){
			double z=mid(x, y);
			if (sgn(gao(z)-v)<0) x=z+eps;
			else y=z;
		}
		printf("%.5lf\n", x);
	}
	return 0;
}


