#include <deque>
#include <cstdio>

 struct Node {
    int index;
     int value;
};
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    Node node;
    deque<Node> dq;
    int tmp;
    int num=0;
    while(scanf("%d", &node.value) && node.value!=-1){
        node.index= num++;
        while(!dq.empty() && dq.front().index < num-n )dq.pop_front();
        while(!dq.empty()&& dq.back().value < node.value)dq.pop_back();
        dq.push_back(node);
        if(num>=n)printf("%d\n", dq.front().value);
    }
    return 0;

}