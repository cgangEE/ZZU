#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int fin=0, maxn=50010;
struct rec{int w,h;} a[maxn];
int n,tn,limit;
long long w[maxn], h[maxn], f0[maxn], f1[maxn];
int q[maxn];

inline bool cmp(rec a, rec b){
	if (a.w==b.w) return a.h<b.h; return a.w>b.w;
}

void init(){
	int i, maxh;
	for (i=1; i<=tn; ++i) scanf("%d%d", &a[i].w, &a[i].h);
	std::sort(a+1, a+tn+1, cmp);
	maxh=-1; n=0; a[tn+1].w=-1;
	for (i=1; i<=tn; ++i)
		if (a[i].w!=a[i+1].w)
			if (a[i].h>maxh){
				maxh=a[i].h; n+=1;
				h[n]=a[i].h; w[n]=a[i].w;
			}
}

void solve(){
	int i,step,head,tail;
	long long ans, *x, *y, *t;
	for (i=1; i<=n; ++i) f1[i]=w[1]*h[i];
	if (limit>n) limit=n;
	if (limit==1){
		cout<<f1[n]<<endl;
		return;
	}
	x=f1, y=f0, ans=f1[n];
	for (step=2; step<=limit; ++step){
		t=x; x=y; y=t;
		head=1; tail=1; q[1]=step-1;
		for (i=step; i<=n; ++i){
			while (head<tail && (-h[i])*(w[q[head+1]+1]-w[q[head]+1])>(y[q[head+1]]-y[q[head]])) ++head;
			x[i]=y[q[head]]+w[q[head]+1]*h[i];
			while (head<tail && (y[q[tail]]-y[q[tail-1]])*(w[i+1]-w[q[tail]+1])<(y[i]-y[q[tail]])*(w[q[tail]+1]-w[q[tail-1]+1])) --tail;
			q[++tail]=i;
		}
		if (x[n]<ans) ans=x[n];
	}
	cout<<ans<<endl;
}

int main(){
	while (scanf("%d%d", &tn, &limit)==2){
		init();
		solve();
	}
	return 0;
}
