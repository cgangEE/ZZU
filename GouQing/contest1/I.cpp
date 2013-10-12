#include <algorithm>
#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define N 10

int i,j,k,m,n,l;
int f[]={16, 7, 8, 1, 1, 2, 3};
bool a[N+10];

int gao(){
	int ret=0;
	scanf("%d", &n);
	clr(a, 0);
	while (n--){
		char ch=getchar();
		while (!isalpha(ch)) ch=getchar();
		ch=toupper(ch);
		ret+=f[ch-'A'];
		a[ch-'A']=true;
	}
	if (!a[1] || !a[2]) 
		if (ret>1) ret--;

	return ret;
}

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		int i=gao(), j=gao();
		if (i==j) puts("tie");
		else if (i>j) puts("red");
		else puts("black");
	}
	return 0;
}
