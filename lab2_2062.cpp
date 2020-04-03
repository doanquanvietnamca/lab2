#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
int arr[N];
long long bin[N];
int lowbit(int x){
    return x & -x;
}
long long sum(int x){
    long long res = 0;
    for(int i=x ;i; i-=lowbit(i))
        res += bin[i];
    return res;
}
void add(int x,int w){
    for(int i=x ;i<N; i+=lowbit(i))
       bin[i] += w;
}
int main()
{
    int n,q;
    scanf("%d",&n);
    int i =0;
    while(i<n)
        scanf("%d",&arr[++i]);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int query,l,r,val,x;
        scanf("%d",&query);
        if(query == 1){
            scanf("%d",&x);
            long long ans = arr[x];
            int seq = sqrt(x+0.5);
            for(int i=1;i<=seq;i++){
                if(x % i == 0){
                    ans += sum(i);
                    if(i*i != x)
                        ans += sum(x/i);
                }
            }
            printf("%lld\n",ans);   
        }
        else{
            scanf("%d %d %d",&l,&r,&val);
            add(l,val);
            add(r+1,-val);
        }
    }
}