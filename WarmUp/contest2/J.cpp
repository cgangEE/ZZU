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
#include <deque>
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
#define N 50000
#define M 100

struct P{
	int x, y;
	void in(){ scanf("%d%d", &x, &y); }
	bool operator <(const P&p)const{
		if (x!=p.x) return x<p.x;
		return y<p.y;
	}
	void out(){
		cout<<x<<' '<<y<<endl;
	}
};

int i,j,k,m,n,l;
P a[N+10], b[N+10];
int idx;
ll f[N+10][M+10];
deque<int> que[M+10];

void gao(int i, int j, deque<int> & q){
	if (sz(q)==0) return;
	while (sz(q)>1){
		int x=*q.begin(), y=*(q.begin()+1);
		if (b[i].y*(b[x+1].x-b[y+1].x)>=f[y][j-1]-f[x][j-1]) q.pop_front();
		else break;
	}
	int k=q.front();
	f[i][j]=f[k][j-1]+b[i].y*b[k+1].x;


	if (sz(que[j])<=1) que[j].pb(i);
	else{
		int x=*(q.end()-1), y=*(q.end()-2);
		if ((f[i][j]-f[x][j])*(b[y+1].x-b[x+1].x)>=(f[x][j]-f[y][j])*(b[x+1].x-b[i+1].x)) que[j].pb(i);
	}
}

int main(){
	while (~scanf("%d%d", &n, &m)){
		rep(i, n) a[i].in();
		sort(a, a+n);
		idx=1;
		b[idx]=a[n-1];
		repd(i, n-2, 0)
			if (a[i].y>b[idx].y) b[++idx]=a[i];


		repf(j, 0, m) que[j].clear();
		que[0].pb(0);

		clr(f, -1);
		f[0][0]=0;

		repf(i, 1, idx) repf(j, 1, min(i, m)){
			gao(i, j, que[j-1]);			
		}


		ll ans=-1;
		repf(j, 1, m) if (f[idx][j]!=-1)  
			_checkmin(ans, f[idx][j]);
		cout<<ans<<endl;
	}
	return 0;
}

