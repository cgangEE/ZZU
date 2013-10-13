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
#define e 10007

int i,j,k,m,n,l;

struct Mat{
	int a[2][2];
	Mat(){ clr(a, 0); }
	Mat(int i, int j, int k, int l){
		a[0][0]=i, a[0][1]=j, a[1][0]=k, a[1][1]=l;
	}
	void E(){
		clr(a, 0);
		a[0][0]=a[1][1]=1;
	}
	Mat operator *(const Mat& m)const{
		Mat ret;
		rep(i, 2) rep(j, 2) rep(k, 2)
			ret.a[i][j]+=a[i][k] * m.a[k][j];

		rep(i, 2) rep(j, 2) ret.a[i][j]%=e;

		return ret;
	}
};

int gao(int n){
	Mat a(1, 1, 1, 0);
	Mat ret; ret.E();

	n--;
	while (n){
		if (n&1) ret=ret*a;
		a=a*a;
		n>>=1;
	}
	return (4*ret.a[0][1]+2*ret.a[1][1])%e;
}

int pow2(int n){
	int ret=1, a=2;
	while (n){
		if (n&1) ret=ret*a%e;
		a=(a*a)%e;
		n>>=1;
	}
	return ret;
}

int main(){
	while (~scanf("%d", &n)){
		if (n<=3){
			switch (n){
				case 1: 
				case 2:
					puts("0");
					break;
				case 3:
					puts("2");
			}
		}
		else{
//			cout<<gao(n)<<endl;
			printf("%d\n", (pow2(n)+e-gao(n))%e);
		}
	}
	return 0;
}


