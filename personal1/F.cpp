#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;

struct P{
	ll x, y;
	P(){}
	P(ll x, ll y):x(x),y(y){}
	P operator + (const P&p)const{
		return P(x+p.x, y+p.y); 
	}
};

int i,j,k,m,n,l,p;

int main(){
	while (~scanf("%d%d", &p, &n) && p+n){
		P x=P(1, 1), y=P(1, 0), z;
		double pp=sqrt(1.*p);
		while (true){
			z = x + y;
			if (z.x>n) break;
			if (z.x*1./z.y<pp) x=z;
			else y=z;
		}

		cout<<y.x<<'/'<<y.y<<endl;
	}
	return 0;
}

