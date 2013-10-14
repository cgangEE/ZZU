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

const int N=100;
struct e_t {int to, cap, rev, cost;}; 

template <int N>
class MCMF{           
	public:          
		vector<e_t> a[N*5+10]; 
		int f[N*5+10], c[N*5+10];
		bool inQ[N*5+10];
		e_t *e[N*5+10];
		int s, t;

		void clear(){ rep(i,N*5+10) a[i].clear(); }

		void add(int i, int j, int c, int cost){ 
			a[i].pb((e_t){j, c, sz(a[j]), cost}); 
			a[j].pb((e_t){i, 0, sz(a[i])-1, -cost}); 
		} 

		bool bellmanFord(int &flow, int &cost){
			queue<int> q; 
			clr(f, 0), clr(c, 0x7f), clr(inQ, 0);

			q.push(s), f[s]=INF, c[s]=0, inQ[s]=1;
			while (!q.empty()){
				int i=q.front(); q.pop(); inQ[i]=0;
				rep(k, sz(a[i])){
					e_t & ei = a[i][k];
					if (ei.cap && c[ei.to]>c[i]+ei.cost){
						f[ei.to]=min(f[i], ei.cap);
						c[ei.to]=c[i]+ei.cost;
						e[ei.to]=&ei;                
						if (!inQ[ei.to]) inQ[ei.to]=true, q.push(ei.to);
					}

				}
			}
			if (c[t]==0x7f7f7f7f) return false;
			flow+=f[t], cost+=c[t]*f[t];
			int i=t;
			while (i!=s){
				e[i]->cap-=f[t];
				a[i][e[i]->rev].cap+=f[t];
				i=a[i][e[i]->rev].to;
			}
			return true;
		}

		void minCost(int &flow, int &cost){
			while (bellmanFord(flow, cost));    
		}

};


int i,j,k,m,n,l,ai,c;
MCMF<N> mcmf;

int main(){

	while (~scanf("%d%d%d", &n, &m, &l)){
		mcmf.clear();
		mcmf.s=0, mcmf.t=n+1;
		mcmf.add(mcmf.s, 1, l,0);
		mcmf.add(n, mcmf.t, l, 0);
		while (m--){
			scanf("%d%d%d%d", &i, &j, &ai, &c);
			repf(e, 1, c) mcmf.add(i, j, 1, (e*2-1)*ai);
		}
		int x=0, y=0;
		mcmf.minCost(x, y);
		if (x==l) printf("%d\n", y);
		else puts("-1");
	}
	return 0;
}

