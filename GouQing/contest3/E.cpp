#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back
#define M 20
#define N 6

int i,j,k,m,n,l;

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
	P operator +(const P&p)const{ return P(x+p.x, y+p.y); }
};

struct MZ{
	int a[N][N];
	P bg, ed;
	void in(){
		rep(i, N) rep(j, N){
		   	scanf("%d", &a[i][j]);
			if (a[i][j]&(1<<5)) bg=P(i,j);
			if (a[i][j]&(1<<6)) ed=P(i,j);
		}
	}
};

char c[]="LDRU";
P d[]={P(0, -1), P(1,0), P(0, 1), P(-1,0)};
int x[]={1,0,2,3};

struct Q{
	P i, j;
	int k;
	Q(){}
	Q(P i, P j):i(i),j(j){
		k=((i.x*N+i.y)*N+j.x)*N+j.y;
	}
	void update(){
		k=((i.x*N+i.y)*N+j.x)*N+j.y;
	}
};

MZ maze[M+10];
int g[N*N*N*N+10];
Q pre[N*N*N*N+10];
int ed;

bool move(MZ &m, P & p, int i, P &q){
	if (!(m.a[p.x][p.y]&(1<<i))){
		q=p+d[i];
		if (q.x<0 || q.y<0 || q.x>=N || q.y>=N || (!(m.a[q.x][q.y]&(1<<4)))) 
			return false;
	}
	else q=p;
	return true;
}

void bfs(MZ &m1, MZ &m2){
	Q q(m1.bg, m2.bg);

	queue<Q> que; clr(g, -1);
	que.push(q), g[q.k]=4;

	ed=Q(m1.ed, m2.ed).k;
	if (q.k==ed) return;

	while (sz(que)){
		Q p=que.front();
		rep(i, 4){
			if (move(m1, p.i, x[i], q.i) && move(m2, p.j, x[i], q.j)){
				q.update();
				if (g[q.k]==-1){
//					cout<<q.i.x<<' '<<q.i.y<<' '<<q.j.x<<' '<<q.j.y<<endl;
					g[q.k]=x[i], que.push(q), pre[q.k]=p;
					if (q.k==ed) return;
				}
			}
		}
		que.pop();
	}
}

int s[N*N*N*N+10];
void ans(){
	if (g[ed]==-1){
		puts("-1"); return;
	}
	s[0]=0;
	while (g[ed]!=4){
		s[++s[0]]=g[ed];
		ed=pre[ed].k;
	}	
	repd(i, s[0], 1) putchar(c[s[i]]);
	putchar('\n');
}

int main(){
	int ts;
	scanf("%d", &ts);

	maze[0].in();
	repf(te, 1, ts-1){
		maze[te].in();
		bfs(maze[te-1], maze[te]);
		ans();
	}
	return 0;
}

