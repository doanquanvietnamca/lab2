
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map <int, vector<int> > mm;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int tt;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&tt);
            mm[tt].push_back(i);
        }
        int m;
        scanf("%d",&m);
        int l, r;
        int ans[70017];
        vector<int> ::iterator iter;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&l,&r,&tt);
            int len = mm[tt].size();
            if(len == 0)
            {
                ans[i] = 0;
                continue;
            }
            iter = lower_bound(mm[tt].begin(), mm[tt].end(),l);
            if(iter == mm[tt].end() || *iter > r)
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = 1;
            }
        }
        for(int i = 0; i < m; i++)
        {
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}