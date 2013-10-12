#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 1000

int i,j,k,m,n,l;
char s[N+10], t[N+10];
int f[N+10][10][10];
int g[1000][1000];

template <class T> void checkmin(T &a, T b){ if (a==-1 || b<a) a=b; }

struct P{
    int a[3];
    P(){}
    P(int e){
        rep(i, 3){
            a[i]=e%10;
            e/=10;
        }
    }
    int val(){
        int ret=0;
        repd(i, 2, 0) ret=ret*10+a[i];
        return ret;
    }

};
int d[]={1, 2, 4, 3, 6, 7};

void gao(int g[], int e){
    queue<P> q;
    g[e]=0, q.push(P(e));
    
    while (sz(q)){
        int l=g[q.front().val()];
        rep(i, 6) 
            repf(j, -1, 1) if (j!=0){
                P p=q.front();
                rep(k, 3) if ((1<<k)&d[i])
                    p.a[k]=(p.a[k]+j+10)%10;

                int val=p.val();

                if (g[val]==-1){
                    g[val]=l+1, q.push(p);
                }
            }
        q.pop();
    }
}

int main(){
    clr(g, -1);
    rep(i, 1000) gao(g[i], i);
    while (~scanf("%s%s", s, t)){
        n=strlen(s);
        
        if (n<=3){
            int x=0, y=0;
            rep(i, n)
                x=x*10+s[i]-'0', y=y*10+t[i]-'0';
            printf("%d\n", g[x][y]);
            continue;
        }

        clr(f, -1);
        f[1][s[0]-'0'][s[1]-'0']=0;
        repf(i, 2, n-1){
            rep(x, 10) rep(y, 10) if (f[i-1][x][y]!=-1)
                rep(u, 10) rep(v, 10)
                    checkmin(f[i][u][v], 
                        f[i-1][x][y]+g[(x*10+y)*10+s[i]-'0'][((t[i-2]-'0')*10+u)*10+v]);
        }

        printf("%d\n", f[n-1][t[n-2]-'0'][t[n-1]-'0']);
    }
    return 0;
}
