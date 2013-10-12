#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cctype>
using namespace std;

int i,j,k,m,n,l;

struct P{
	int x, y, z;
};

struct Face{
	int v[3];
	P normal(P *p)const{
		return (p[v[1]]-p[v[0]]) * (p[v[2]]-p[v[0]]);
	}
	int cansee(P *p, int i){
		return (p[i]-p[v[0]]) ^ normal(p) > 0 ? 1 : 0;
	}
};

int main(){
	while (~scanf("%d", &n)){
		
	}
	return 0;
}


