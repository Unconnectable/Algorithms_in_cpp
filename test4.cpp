/*
Segment Tree without Lazy tag
It Will TLE!!!!!
!!!!!
!!!!
!!!
!!!
!!!
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#define lld long long 
const int  N =1e7+9;
using namespace std;
int n,m;
lld a[N];//value
struct node 
{
    int left,right;
    lld value ,tag;
};
node t[N];

inline void bd(int p,int l,int r){//建树
    //p:当前节点
    t[p].left=l,t[p].right=r;
    if(l==r) {
        t[p].value=a[l];//区间长度为1
        return ;
    }
    int mid=(l+r)/2;// 加法运算优先级高于位运算
    bd(p*2,l,mid);
    bd(p*2+1,mid+1,r);
    t[p].value = t[p*2].value + t[(p*2)+1].value;
}

inline lld ask(int p,int x,int y){//查询区间和
    if(t[p].left>=x && t[p].right <= y)  
        return t[p].value;
    lld sum=0;
    if( x<=t[2*p].right) sum+=ask(2*p,x,y);
    if( y>=t[2*p+1].left) sum+=ask(2*p+1,x,y);
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
inline void update_dot(int p,int x,int y,lld k{
    //use k to replace a[p],a is originnal array

}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;++i) scanf("%d",&a[i]);
   bd(1,1,n);  
   for(int i=1;i<=m;++i){
    int x,y,z,w;
    scanf("%d",&x);
    //x=1 update_range form [y,z] all add w
    // query sum of range [y,z]
    if(x==1){
        scanf("%d%d%d",&y,&z,&w);
        update_range(1,y,z,w);
    }
    else {
        scanf("%d%d",&y,&z);
        printf("%lld\n",ask(1,y,z));
    }
   }
   return 0;
}