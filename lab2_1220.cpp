#include <cstdio>
#include <stack>
#include <map>
using namespace std;

map<int,stack<int> > m;
int i,n,a,b;
char command[10];

void main(void)
{
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%s",command);
    if (command[1] == 'U')
    {
      scanf("%d %d\n",&a,&b);
      m[a].push(b);
    }
    else
    {
      scanf("%d\n",&a);
      printf("%d\n",m[a].top());
      m[a].pop();
    }
  }
}