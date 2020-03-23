#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct edge
{
	int v, next;
}e[maxn*2];
int first[maxn], cnt;
 
void addNoteEdge(int u, int v)
{
	e[cnt].v = v;
	e[cnt].next = first[u];
	first[u] = cnt++;
	e[cnt].v = u;
	e[cnt].next = first[v];
	first[v] = cnt++;
}
 
int top[maxn], sz[maxn], son[maxn], f[maxn], dep[maxn];
int n, id[maxn], rankEdge[maxn], tid;
void init()
{
	memset(first, -1, sizeof(first));
	cnt = 0;
	memset(son, -1, sizeof(son));
	tid = 0;
}
 
void dfs1(int u, int fa, int d)
{
	sz[u] = 1;
	f[u] = fa;
	dep[u] = d;
	for(int i = first[u]; i != -1; i = e[i].next)
	{
		int v = e[i].v;
		if(v == fa)
			continue;
		dfs1(v, u, d+1);
		sz[u] += sz[v];
		if(son[u] == -1 || sz[son[u]] < sz[v])
			son[u] = v;
	}
}
void dfs2(int u, int tp)
{
	top[u] = tp;
	id[u] = ++tid;
	rankEdge[tid] = u;
	if(son[u] == -1)
		return;
	dfs2(son[u], tp);
	for(int i = first[u]; i != -1; i = e[i].next)
	{
		int v = e[i].v;
		if(v != f[u] && son[u] != v)
			dfs2(v, v);
	}
}
int a[maxn<<2];
void build(int l, int r, int rt)
{	
	a[rt] = 0;
	if(l == r)
		return;
	int m = (l + r) >> 1;
	build(l, m, rt<<1);
	build(m+1, r, rt<<1|1);
}
int search(int x, int y, int l, int r, int rt)
{
	if(x == l && y == r)
	{
		return a[rt];
	}
	int m = (l + r) >> 1;
	if(y <= m)
		return search(x, y, l, m, rt<<1);
	else if(x > m)
		return search(x, y, m+1, r, rt<<1|1);
	else
	{
		return max(search(x, m, l, m, rt<<1), search(m+1, y, m+1, r, rt<<1|1));
	}
}
void update(int x, int l, int r, int rt, int d)
{
	if(l == r)
	{
		a[rt] += d;
		return;
	}
	int m = (l + r) >> 1;
	if(x <= m)
		update(x, l, m, rt<<1, d);
	else
		update(x, m+1, r, rt<<1|1, d);
	a[rt] = max(a[rt<<1], a[rt<<1|1]);
}
int change(int u, int v)
{
	int ans = 0;
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
			swap(u, v);
		ans = max(ans, search(id[top[u]], id[u], 1, n, 1));
		u = f[top[u]];
	}
	if(dep[u] > dep[v])
		swap(u, v);
	ans = max(ans, search(id[u], id[v], 1, n, 1));
	return ans;
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		init();
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			addNoteEdge(u, v);
		}
		dfs1(1, 0, 0);
		dfs2(1, 1);
		build(1, n, 1);
		int q;
		scanf("%d", &q);	
		while(q--)
		{
			char s[10];
			int u, v;
			scanf("%s %d %d", s, &u, &v);
			if(s[0] == 'I')update(id[u], 1, n, 1, v);
			else printf("%d\n", change(u, v));
		}
	}
	return 0;
}
