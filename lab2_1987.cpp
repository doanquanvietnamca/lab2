
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100017;
int tt[maxn];
int n, m;
struct node
{
    int l, r;
    int num;
} x[maxn];
 
bool cmp(node a, node b)
{
    return a.l < b.l;
}
 
int cnt = 0, k = 1;
int findd(int q)
{
    while(q >= x[k].l)
    {
        tt[++cnt] = k;
        k++;
        if(k > n)
            break;
    }
    while(q > x[tt[cnt]].r)
    {
        cnt--;
        if(cnt < 1)
            break;
    }
    return x[tt[cnt]].num;
}
int main()
{
    int ans[maxn];
    while(~scanf("%d",&n))
    {
        memset(ans, 0, sizeof(ans));
        int ll, rr;
        int minn = maxn, maxx = -1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d",&ll,&rr);
            if(ll < minn)
            {
                minn = ll;
            }
            if(rr > maxx)
            {
                maxx = rr;
            }
            x[i].l = ll, x[i].r = rr;
            x[i].num = i;
        }
        int t, q[maxn];
        memset(tt, 0, sizeof(tt));
        scanf("%d",&m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d",&t);
            q[i] = t;
        }
        for(int i = 1; i <= m; i++)
        {
            if(q[i] < minn || q[i] > maxx)
            {
                ans[i] = -1;
                continue;
            }
            ans[i] = findd(q[i]);
        }
        for(int i = 1; i <= m; i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
