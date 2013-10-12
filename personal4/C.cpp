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
#define M 26

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
};

int i,j,k,m,n,l;
char a[N+10][N+10];
P mx[M+10], mn[M+10];
bool v[M+10];

bool ok(int c){
	if (mx[c].x-mn[c].x<2) return false;
	if (mx[c].y-mn[c].y<2) return false;
	repf(x, mn[c].x, mx[c].x){
		if (a[x][mn[c].y]!=c+'A') return false;
		if (a[x][mx[c].y]!=c+'A') return false;
	}
	repf(y, mn[c].y, mx[c].y){
		if (a[mn[c].x][y]!=c+'A') return false;
		if (a[mx[c].x][y]!=c+'A') return false;
	}
	repf(x, mn[c].x+1, mx[c].x-1)
		repf(y, mn[c].y+1, mx[c].y-1)
			if (a[x][y]!='.') return false;

	return true;
}

int main(){
	while (~scanf("%d%d", &n, &m) && n+m){
		clr(v, 0);
		repf(i, 1, n) repf(j, 1, m){
			a[i][j]=getchar();
			while (!isalpha(a[i][j]) && a[i][j]!='.') a[i][j]=getchar();
			if (isalpha(a[i][j])){
				int c=a[i][j]-'A';
				if (!v[c]) mx[c]=P(i,j), mn[c]=P(i,j), v[c]=1;
				else{
				   	checkmax(mx[c].x, i), checkmax(mx[c].y, j);
					checkmin(mn[c].x, i), checkmin(mn[c].y, j);
				}
			}
		}
		rep(i, M) if (v[i] && ok(i)) putchar(i+'A');
		putchar('\n');
	}
	return 0;
}


