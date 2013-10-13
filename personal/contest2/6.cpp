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
#define N 100000

int i,j,k,m,n,l;
char s[N+10], t[N+10];
bool flag;


bool le(char *s){
	int n=strlen(s);
	rep(i, n) if (s[i]>s[0]) return false;
	return true;
}

char get(char *s){
	int n=strlen(s);
	rep(i, n) if (s[i]!=s[0]) return s[i];
	return s[0];
}


void solve(){
	n=strlen(s);
	char g=get(t);
	rep(i, n){
		if (s[i]<t[0]){
		   	putchar(s[i]); continue;
		}
		if (s[i]>t[0]){
			printf("%s%s\n", t, s+i);
			return;
		}

		char f=get(s+i);
		if (g<=t[0]){
			if (g<f) printf("%s%s\n", t, s+i);
			else printf("%s%s\n", s+i, t);
		}
		else{

		}
	}
	puts(t);
}

int main(){
	while (~scanf("%s%s", s, t)){
		solve();
	}
	return 0;
}

