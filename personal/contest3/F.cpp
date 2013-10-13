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
#define N 100000

int i,j,k,m,n,l;
char s[N+10];
int f[N+10];

int gao(){
	if (m==0){
		rep(i, n) if (s[i]=='0') return -1;
		return 0;
	}

	int ret=0, k=0;
	clr(f, 0);
	repf(i, 0, n-m){
		if (i>=m && f[i-m]) k=1-k;
		if ((s[i]=='0' && k==0 ) || (s[i]=='1' && k==1)){
		   	k=1-k;
			f[i]=1, ret++;
		}
	}
	repf(i, n-m+1, n-1){
		if (i>=m && f[i-m]) k=1-k;
		if ((s[i]=='0' && k==0 ) || (s[i]=='1' && k==1)) return -1;
	}
	return ret;
}

int main(){
	while (~scanf("%d%d", &n, &m) && n+m){
		scanf("%s", s);
		n=strlen(s);
		printf("%d\n", gao());
	}
	return 0;
}


