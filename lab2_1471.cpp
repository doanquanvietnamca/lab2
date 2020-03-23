#include<bits/stdc++.h>
using namespace std;
 
const int N = 50000 + 10;
struct node
{
    int y,z,next;
}t[2 * N];
 
int fa[N][20],dep[N],head[2 * N];
long long d[N];
int n,m,root,tot = 0;
 
void add(int x,int y,int z)
{
    t[++tot].y = y;
    t[tot].z = z;
    t[tot].next = head[x];
    head[x] = tot;
}
 
void BFS(int x)
{
    queue<int>q;
    dep[x] = 0;
    fa[x][0] = x;
    q.push(x);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for(int i = 1;i < 20; ++i)
            fa[tmp][i] = fa[fa[tmp][i - 1]][i - 1];
        for(int i = head[tmp];i != -1; i = t[i].next)
        {
            if(fa[tmp][0] == t[i].y) continue;
            dep[t[i].y] = dep[tmp] + 1;
            fa[t[i].y][0] = tmp;
            q.push(t[i].y);
        }
    }
}
 
int LCA(int u,int v)
{
    if(dep[u] > dep[v]) swap(u,v);
    for(int det = dep[v] - dep[u],i = 0;det;det >>= 1,i++)
        if(det & 1) v = fa[v][i];
    if(u == v) return v;
    for(int i = 19; i >= 0; --i)
    {
        if(fa[u][i] == fa[v][i]) continue;
        u = fa[u][i];
        v = fa[v][i];
    }
    return fa[u][0];
}
 
void DFS(int x,int f)
{
    for(int i = head[x];i != -1; i = t[i].next)
    {
        if(t[i].y == f) continue;
        d[t[i].y] = d[x] + t[i].z;
        DFS(t[i].y,x);
    }
}
 
int main()
{
    while(~scanf("%d",&n))
    {
        memset(head,-1,sizeof(head));
        for(int i = 1;i < n; ++i)
        {
            int u,v,z;
            scanf("%d%d%d",&u,&v,&z);
            add(u,v,z);
            add(v,u,z);
        }
        d[1] = 0;
        DFS(1,-1);
        BFS(1);
        scanf("%d",&m);
        for(int i = 0;i < m; ++i)
        {
            int x,y;
            long long ans;
            scanf("%d%d",&x,&y);
            ans = d[x] + d[y] - 2 * d[LCA(x,y)];
            printf("%lld\n",ans);
        }
    }
    return 0;
}

