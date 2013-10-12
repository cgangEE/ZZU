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

int i,j,k,m,n,l;
char s[1000];
int a, b, c;

int gao(char *s, char *t){
	int ret=0;
	bool flag=false;
	for (char *c=s; c!=t; ++c){
		if (isdigit(*c)) ret=ret*10+*c-'0';
		else if (*c=='-') flag=true;
	}
	if (flag) ret*=-1;
	return ret;
}

bool gao(){
	if (c<0) return false;
	if (c==0) return true;
	repf(x, 0, c/a) if ((c-a*x)%b==0) return true;
	return false;
}

int main(){
	while (gets(s)!=NULL){
		a=gao(s, strchr(s, 'x'));
		b=gao(strchr(s, '+')+1, strchr(s, 'y'));
		c=gao(strchr(s, '=')+1, s+strlen(s));
		checkmax(a, 1), checkmax(b, 1);
		if (gao()) printf("Yes.\n\n");
		else printf("No.\n\n");
	}
	return 0;
}


