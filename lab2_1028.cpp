#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 15000 + 5;
const int INF = 32000 + 5;

typedef pair<int, int> Star;

Star pos[maxn];

int bit[INF];
int ans[maxn];

int n;

inline int lowbit(int x) {
    return x & -x;
}

void add(int i, int delta) {
    for (int j = i; j <= INF; j += lowbit(j)) {
        bit[j] += delta;
    }
}

int sum(int k) {
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i)) {
        ans += bit[i];
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pos[i].first, &pos[i].second);
        pos[i].first++;
        pos[i].second++;
        ans[sum(pos[i].first)]++;
        add(pos[i].first, 1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
