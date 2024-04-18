#include <cstdio>
#include <cmath>
#include <algorithm>
#define lld long long 
const int  N =1e6+9;
using namespace std;

int n,m;
int a[N]; // 数组存储 n 个数
int segTree[4 * N]; // 线段树数组

inline void buildSegmentTree(int p, int l, int r) {
    if (l == r) {
        segTree[p] = a[l];
    } else {
        int mid = (l + r) / 2;
        buildSegmentTree(2 * p, l, mid);
        buildSegmentTree(2 * p + 1, mid + 1, r);
        segTree[p] = min(segTree[2 * p], segTree[2 * p + 1]);
    }
}

inline int query(int p, int l, int r, int a, int b) {
    if (l > b || r < a) return INT_MAX; // 当前节点区间与询问区间不重叠
    if (l >= a && r <= b) return segTree[p]; // 当前节点区间完全包含询问区间
    int mid = (l + r) / 2;
    return min(query(2 * p, l, mid, a, b), query(2 * p + 1, mid + 1, r, a, b)); // 合并左右子树的结果
}

inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]); // 读取 n 个数
    //printf("%d %d \n",n,m);
    buildSegmentTree(1, 1, n); // 构建线段树
    for(int i=1;i<=m;++i){
        int left, right; // 将变量名修改为 left 和 right
        scanf("%d%d", &left, &right); // 读取询问区
        printf("%d ", query(1, 1, n, left, right)); // 输出区间最小值
    }
    return 0;
}
