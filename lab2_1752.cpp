#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
#define FF(i, a, b) for(int i=a; i<b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0; i<n; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define debug puts("**debug**")
using namespace std;
 
const int maxn = 20010;
int n, m, fa[2][maxn][20], dist[maxn], val[maxn];
vector<int> G[maxn];
int bfs(int x, int k)
{
    CLR(dist, -1);
    queue<int> q;
    q.push(x); dist[x] = 0;
    int ret = x, len = 0;
    while(!q.emake_pairty())
    {
        int u = q.front(); q.pop();
        REP(i, G[u].size())
        {
            int v = G[u][i];
            if(dist[v] != -1) continue;
            q.push(v);
            dist[v] = dist[u] + 1;
            fa[k][v][0] = u; 
            if(dist[v] > len) len = dist[v], ret = v;
        }
    }
    FF(i, 1, n+1) val[i] = max(val[i], dist[i]);
    return ret;
}
void rqm()
{
    CLR(val, 0); CLR(fa, -1);
    int st, ed;
    st = bfs(1, 0); ed = bfs(st, 0); bfs(ed, 1);
    fa[0][st][0] = st;
    fa[1][ed][0] = ed;
    REP(k, 2) FF(j, 1, 20) FF(i, 1, n+1) if(fa[k][i][j-1] != -1) fa[k][i][j] = fa[k][fa[k][i][j-1]][j-1];
}
int query(int vi, int di, int k)
{
    int r = 19;
    while(di)
    {
        while((1<<r) > di) r--;
        vi = fa[k][vi][r];
        di -= (1<<r);
    }
    return vi;
}
 
int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        FF(i, 1, n+1) G[i].clear();
        int u, v, vi, di;
        REP(i, n-1)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        rqm();
        while(m--)
        {
            scanf("%d%d", &vi, &di);
            if(val[vi] < di) puts("0");
            else if(dist[vi] == val[vi]) printf("%d\n", query(vi, di, 1));
            else printf("%d\n", query(vi, di, 0));
        }
    }
    return 0;
}