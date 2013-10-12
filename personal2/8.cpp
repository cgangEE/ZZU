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
#define e 10007
#define g 3336

int i,j,k,m,n,l;

int pow2(int a, int n){
	int ret=1;
	while (n){
		if (n&1) ret=(ret*a)%e;
		a=(a*a)%e;
		n>>=1;
	}
	return ret;
}

int main(){
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%d", &n);
		int ret;
		if (n%2==1){
			ret=pow2(4, n/2);
			ret=ret*(2+e-(5*g)%e)%e;
			ret=(ret+5*g)%e;
		}
		else{
			ret=pow2(4, n/2-1);
			ret=ret*(2+e-(4*g)%e)%e;
			ret=(ret+4*g)%e;
		}
		printf("Case #%d: %d\n", te, ret);
	}
	return 0;
}


