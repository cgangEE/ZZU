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
#define M 100000
#define N 20000

int i,j,k,m,n,l;
int a[N+10];
int f[N+10], g[N+10];

template<int SZ>
struct BIT{
	int a[SZ+10];
	void clear(){ clr(a, 0); }
	void ins(int x){
		while (x<=SZ){
			a[x]++;
			x+=x&-x;
		}
	}
	int qry(int x){
		int ret=0;
		while (x>0){
			ret+=a[x];
			x-=x&-x;
		}
		return ret;
	}
};

BIT<M> bit;

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d", &n);
		rep(i, n) scanf("%d", &a[i]);

		bit.clear();
		rep(i, n){
			f[i]=bit.qry(a[i]);
			bit.ins(a[i]);
		}

		bit.clear();
		repd(i, n-1, 0){
			g[i]=bit.qry(a[i]);
			bit.ins(a[i]);
		}

		ll ret=0;
		repf(i, 1, n-2) ret+=f[i]*(n-1-i-g[i])+(i-f[i])*g[i];
		cout<<ret<<endl;

	}
	return 0;
}


