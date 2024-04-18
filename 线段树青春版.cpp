#include <cstdio>
#include <cmath>
#include <algorithm>
#define lld long long 
const int  N = 1e7 + 9;
using namespace std;
lld a[N]; // value
struct node {
    int left, right;
    lld value, tag;
};
node t[N];

inline void bd(int p, int l, int r) { // build
    t[p].left = l, t[p].right = r;
    if (l == r) {a
        t[p].value = a[l]; // length of the interval is 1
        return;
    }
    int mid = (l + r) / 2; // addition operation has higher priority than bitwise operation
    bd(p * 2, l, mid);
    bd(p * 2 + 1, mid + 1, r);
    t[p].value = t[p * 2].value + t[p * 2 + 1].value;
}

inline lld ask_range(int p, int x, int y) { // query interval sum
    if (t[p].left >= x && t[p].right <= y)  
        return t[p].value;
    lld sum = 0;
    if (x <= t[2 * p].right) sum += ask_range(2 * p, x, y);
    if (y >= t[2 * p + 1].left) sum += ask_range(2 * p + 1, x, y);
    return sum;
}
inline void update_range(int p,int x,int y,lld k ){ //使用懒标记修改区间(l,r) k是加上的值
    if(t[p].left> y || t[p].right < x) return ;
    if(t[p].left==t[p].right) {
        t[p].value+=k;
        return;
    }
    if(t[2*p].right >= x) update_range(2*p,x,y,k);
    if(t[2*p+1].left <= y) update_range(2*p+1,x,y,k);
    t[p].value = t[p*2].value+t[p*2+1].value;
}
inline void update_dot(int p,int x,int y,lld k){ // modify all values in the interval [x, y] in the segment tree
    if(t[p].left >=x && t[p].right <=y){
        t[p].value =k*(t[p].right-t[p].left+1);
        return ;
    }
    if(t[2*p].right >= x) update_dot(2*p,x,y,k);
    if(t[2*p+1].left <= y) update_dot(2*p+1,x,y,k);
    t[p].value = t[p * 2].value + t[p * 2 + 1].value;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    bd(1, 1, n);
    printf("tot=%lld\n",ask_range(1,1,n));
    for (int i = 1; i <= m; ++i) {
        int x, y, z,k;
        scanf("%d",&x);
        if(x==1){
            scanf("%d%d%d",&y,&z,&k);
            update_dot(1,y,z,k);
        }
        else {
            scanf("%d%d",&y,&z);
            printf("\n sum==%lld    ",ask_range(1,y,z));
        }
    }
    return 0;
}
