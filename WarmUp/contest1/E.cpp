#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size)
#define pb push_back
#define N 4000

struct P{
	int i, x, ret;
	void in(int a){
		i=a;
		scanf("%d", &x);
	}
	bool operator <(const P&p)const{
		return x<p.x;
	}
};

int i,j,k,m,n,l;
P a[N+10], b[N+10];
ll f[2][N+10];
short int g[N+10][N+10];

int x, y;

template<class T> void checkmin(T &a, T b){ if (a==-1 || b<a) a=b; }

void gao(int n, int m){
	if (n==0) return;
	a[n].ret=b[m].i;
	gao(n-1, g[n][m]);
}

bool cmp(P a, P b){ return a.i<b.i; }

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d", &n);
		repf(i, 1, n) a[i].in(i);
		scanf("%d", &m);
		repf(i, 1, m) b[i].in(i);
		sort(a+1, a+1+n);
		sort(b+1, b+1+m);

		clr(f, -1);
		f[1][1]=abs(a[1].x-b[1].x);

		repf(i, 2, n){
			x=i&1, y=1-x;

			clr(f[x], -1);

			f[x][1]=f[y][1]+abs(a[i].x-b[1].x);
			g[i][1]=1;
			repf(j, 2, min(m, i)){

				int det=abs(a[i].x-b[j].x);
				
				
				if (f[y][j-1]!=-1 && (f[x][j]==-1 || f[y][j-1]+det<f[x][j])){
					f[x][j]=f[y][j-1]+det;
					g[i][j]=j-1;
				}


				if (f[y][j]!=-1 && (f[x][j]==-1 || f[y][j]+det<f[x][j])){
					f[x][j]=f[y][j]+det;
					g[i][j]=j;
				}
				
			

			}
		}
		cout<<f[n&1][m]<<endl;
		
		
		gao(n, m);
		
		sort(a+1, a+1+n, cmp);
		repf(i, 1, n){
			if (i-1) putchar(' ');
			printf("%d", a[i].ret);
		}
		putchar('\n');
	}
	return 0;
}
