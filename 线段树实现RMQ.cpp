#include <cstdio>
#include <cmath>
#include <algorithm>
#define lld long long 
const int  N = 1e7 + 9;
using namespace std;
const lld MAXN=1e10;
lld a[N]; // valueo
struct node {
    int left, right;
    lld value, tag;
};
node t[N];

inline void bd(int p, int l, int r) { // build


    t[p].left = l, t[p].right = r;
    if (l == r) {
        t[p].value = a[l]; // length of the interval is 1
        return;
    }
    int mid = (l + r) / 2; // addition operation has higher priority than bitwise operation
    bd(p * 2, l, mid);
    bd(p * 2 + 1, mid + 1, r);
    t[p].value = min(t[p * 2].value , t[p * 2 + 1].value);
}

inline lld ask_range(int p, int x, int y) { // query interval sum
    if (t[p].left >= x && t[p].right <= y)  
        return t[p].value;
    lld sum = MAXN;
    if (x <= t[2 * p].right)    sum =min(sum, ask_range(2 * p, x, y) );
    if (y >= t[2 * p + 1].left) sum =min(sum, ask_range(2 * p + 1, x, y) );
    return sum;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    bd(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld ",ask_range(1,x,y));
    }
    return 0;
}
