#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000 + 5;
const int max_logn = 18;

struct edge {
    int to, weight;
};

vector<edge> G[maxn];

int vs[maxn*2-1];           
int id[maxn];               
int depth[maxn*2-1];       
int dis[maxn];              

int st[maxn*2-1][max_logn];

int n, root;

void dfs(int v, int p, int d, int w, int &k) {
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    dis[v] = w;
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i].to != p) {
            dfs(G[v][i].to, v, d + 1, w + G[v][i].weight, k);
            vs[k] = v;
            depth[k++] = d;
        }
    }
}

void rmq_init(int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = i;
    }
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            if (depth[st[i][j-1]] <= depth[st[i+(1<<(j-1))][j-1]]) {
                st[i][j] = st[i][j-1];
            } else {
                st[i][j] = st[i+(1<<(j-1))][j-1];
            }
        }
    }
}

void init() {
    int k = 0;
    dfs(root, -1, 0, 0, k);
    rmq_init(n * 2 - 1);
}

int query(int L, int R) {
    int k = log2(R - L);
    if (depth[st[L][k]] <= depth[st[R-(1<<k)][k]]) {
        return st[L][k];
    } else {
        return st[R-(1<<k)][k];
    }
}

int lca(int u, int v) {
    return vs[query(min(id[u], id[v]), max(id[u], id[v])+1)];
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    root = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back((edge){v, w});
        G[v].push_back((edge){u, w});
    }
    init();
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        int t = lca(u, v);
        int len = dis[u] - dis[t] + dis[v] - dis[t];
        printf("%d\n", len);
    }
    return 0;
}
