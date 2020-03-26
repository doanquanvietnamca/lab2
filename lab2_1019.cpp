#include<bits/stdc++.h>
  using namespace std;
  typedef long long ll;
  const int maxn = 10000 + 10;
  struct node
  {
      int u, v;
      char s[3];
 }a[maxn];
 int num[maxn], tot, color[maxn];
 map<int, int>intToInt;
 int main()
 {
     int n;
     cin >> n;
     num[tot++] = 0, num[tot++] = 1e9;
     for(int i = 1; i <= n; i++)
     {
         scanf("%d%d%s", &a[i].u, &a[i].v, &a[i].s);
         num[tot++] = a[i].u;
         num[tot++] = a[i].v;
     }
     sort(num, num + tot);
     tot = unique(num, num + tot) - num;
     for(int i = 0; i < tot; i++)
     {
         intToInt[num[i]] = i;
     }
     for(int i = 1; i <= n; i++)
     {
         int tmp = 0;
         if(a[i].s[0] == 'b')tmp = 1;
         for(int j = intToInt[a[i].u] + 1; j <= intToInt[a[i].v]; j++)
         {
             color[j] = tmp;
         }
     }
     int l, r, length = 0;
     for(int i = 0; i < tot; i++)
     {
         if(color[i])continue;
         int j = i;
         while(color[j] == 0 && j < tot)j++;
         if(length < num[j - 1] - num[i - 1])
        {
             l = num[i - 1];
             r = num[j - 1];
             length = r - l;
         }
     }
     cout<<l<<" "<<r<<endl;
     return 0;
 }