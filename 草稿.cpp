#include <bits/stdc++.h>
using namespace std;
#define lld long long 
int tree[1000000];
int A[1000000];
int n,m;
int a[1000000];
void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

lld query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
    // out of range
    if (start > end or start > r or end < l)
        return;

    // Current node is a leaf node
    if (start == end)
    {
        // Add the difference to current node
        tree[node] += val;
        return;
    }

    // If not a leaf node, recur for children.
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);

    tree[node] = tree[node*2] + tree[node*2+1];
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;++i) scanf("%d",&A[i]);
   build(1,1,n);
   for(int i=1;i<=m;++i){
    int x,y,z,w;
    scanf("%d",&x);
    if(x==1){
        scanf("%d%d%d",&y,&z,&w);//y z +w
        updateRange(1,1,n,y,z,w);//node start end l r val
    }
    else {
        scanf("%d%d",&y,&z);
      //  update(1,y,z,0);
        printf("%lld\n",query(1,1,n,y,z));
    }
   }

   return 0;
}