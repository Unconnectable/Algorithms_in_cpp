#include <cstdio>
#include <cmath>
#include <algorithm>
#define lld long long 
const int  N =1e6+9;
using namespace std;
int n,m;
lld a[N];//value
struct node 
{
    int l,r;
    lld val ,tag;
    /* data */
};
node t[N];

inline void bd(int p,int x,int y){//建树
    //p:当前节点
    t[p].l=x,t[p].r=y;
    if(x==y) {
        t[p].val=a[x];//区间长度为1
        return ;
    }
    //递归 di=d(2i)+d(2i+1)
    //di的范围是l-r
    // 左节点 d(2i)     :l to (l+r)/2 
    // 右节点 d(2i+1) (l+r)/2+1 to r
    int mid=(x+y)/2;// 加法运算优先级高于位运算
    //递归对左右节点进行bd
    //左节点
    bd(p*2,x,mid);
    //右节点
    bd(p*2+1,mid+1,y);
    t[p].val = t[p*2].val + t[(p*2)+1].val;
}

inline void mark(int p){//懒标记
   if(t[p].tag){//如果懒标记不为0，就将其下传，修改左右儿子维护的值
        t[p*2].val+=t[p].tag*(t[p*2].r-t[p*2].l+1);
        t[p*2+1].val+=t[p].tag*(t[p*2+1].r-t[p*2+1].l+1);
        t[p*2].tag+=t[p].tag;//为该节点的左右儿子打上标记
        t[p*2+1].tag+=t[p].tag;
        t[p].tag=0;//下传之后将该节点的懒标记清0
    }
}

inline lld ask(int p,int x,int y){//查询区间和
    //p:当前节点 r-l:要搜索的区间
    mark(p);
    if(t[p].l >= x && t[p].r <= y)  
        return t[p].val;

    //mark(p);
    //(left,right)属于(l,r)
   // if(t[p].right<l || t[p].left>r) return 0;

    lld sum=0;

    //左节点和区间相交
    if( x<=t[2*p].r) sum+=+ask(2*p,x,y);
    //右节点相交
    if( y>=t[2*p+1].l) sum+=ask(2*p+1,x,y);
    return sum;
}


inline void update(int p,int x,int y,lld k ){ //使用懒标记修改区间(l,r) k是加上的值
//每一次更新的时候需要去检查 t[p].tag!=0
//但是单独的询问区间是不需要去检查的
//因此，每次update时去mark
    
    if(x<=t[p].l && t[p].r <=y){
        t[p].val+= (t[p].r-t[p].l+1)*k;
        t[p].tag+=k;
        return ;
    }
    mark(p);
    //对子节点打标记
    int mid=t[p].l+t[p].r>>1;
    if(x<=t[p*2].r) update(p*2,x,y,k);
   if(t[p*2+1].l<=y) update(p*2+1,x,y,k);
/*
    血的教训！！！！
    牢牢记住!!!
    mid是t[2p].left!!!!
    t[2*p].right + 1 =t[2*p+1].left
    注意等号的的选取
    等待修改区间l <= t[2p].right
               r >= t[2p+1].left

*/
    t[p].val=t[p*2].val+t[p*2+1].val;
}

int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;++i) scanf("%d",&a[i]);
   bd(1,1,n);
   //for(int i=1;i<=4*n;i++) printf("%lld\n",t[i].value);
  
   for(int i=1;i<=m;++i){
    int x,y,z,w;
    scanf("%d",&x);
    if(x==1){
        scanf("%d%d%d",&y,&z,&w);
        update(1,y,z,w);
    }
    else {
        scanf("%d%d",&y,&z);
      //  update(1,y,z,0);
        printf("%lld\n",ask(1,y,z));
    }
   }

   return 0;
}
