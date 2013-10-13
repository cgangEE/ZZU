#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 19
#define M 9*9*N

int i,j,k,m,n,l,x,y;
ll f[20][20][M*2+100];

ll gao(ll a){
	if (a<10) return a;

	vi v;
	ll ret=0;
	while (a) v.pb(a%10), a/=10;
	repd(i, sz(v), 1)
		repf(j, 0, v[i-1]-1){
			repd(k, sz(v), 1){
				x=0;
				repd(l, sz(v), i) x+=(l-k)*(l==i?j:v[l-1]);
				ret+=f[k][i-1][x+M];
			}
		}

	if (sz(v)>=2) ret-=sz(v)-1;
	return ret;
}

int main(){
	repf(k, 1, N){
		f[k][0][M]=1;
		repf(i, 1, N){
			rep(j, 10)
				repf(x, (k-i)*j, M*2+10)
					f[k][i][x]+=f[k][i-1][x-(k-i)*j];
		}
	}
	int ts;
	scanf("%d", &ts);
	while (ts--){
		ll a, b;
		cin>>a>>b;
		cout<<gao(b+1)-gao(a)<<endl;
	}
	return 0;
}
