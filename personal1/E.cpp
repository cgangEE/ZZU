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

int i,j,k,m,n,l,p;

int gcd(int a, int b){
	return b==0?a:gcd(b, a%b); 
}

int find(int i){
	int x=1, y=n;
	while (x!=y){
		int z=mid(1+x, y);
		if (i*i>=z*z*p) x=z;
		else y=z-1;
	}
	while (gcd(i, x)!=1) x--;
	return x;
}

int main(){
	while (~scanf("%d%d", &p, &n) && n+p){
		int x=n, y=1;
		repf(i, 1, n){
			j=find(i);
			if (i*i>=j*j*p && i*y<x*j)
				x=i, y=j;
		}

		//repf(i, 1, n) repf(j, 1, n) 
		//	if (gcd(i, j)==1 && i*i>=j*j*p)

		printf("%d/%d\n", x, y);

	}
	return 0;
}


