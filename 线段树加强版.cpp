#include <cstdio>
#include <cmath>
#include <algorithm>
#define lld long long 
const int N =1e6+9;
using namespace std;
int n,m;
int a[N];
struct node{
    int l,r;
    lld tag ,val;
};
node t[N];
int ls(int p){
    return 2*p;
}
int rs(int p){
    return 2*p+1;
}

void bd(int p,int x,int y) {
    t[p].l=x,t[p].r=y;
    if(x==y){
        t[p].val=a[x];
        return ;
    }
    int mid=(x+y)>>1;
    bd(ls(p),x,mid);
    bd(rs(p),mid+1,y);
    t[p].val=t[ls(p)].val+t[rs(p)].val;
}
inline void mark_up(int p){  //查询节点P的懒标记
    if(t[p].tag){
      //  t[p].val+=t[p].tag*(t[p].r-t[p].l+1);
        t[2*p].tag+=t[p].tag;
        t[2*p+1].tag+=t[p].tag;
      //  t[p].tag=0;
    }
}
inline void mark_ask(int p){  //查询节点P的懒标记
    if(t[p].tag){
        t[p].val+=t[p].tag*(t[p].r-t[p].l+1);
     //   t[2*p].tag+=t[p].tag;
     //   t[2*p+1].tag+=t[p].tag;
        t[p].tag=0;
    }
}
inline void update(int p,int x,int y,lld k){
    if(t[p].r < y || t[p].l > x) return ;
    if(k) t[p].tag+=k;
    mark_up(p);
    if(t[2*p].r >= x) update(2*p,x,y,k);
    if(t[2*p+1].l <= y) update(2*p+1,x,y,k);
    t[p].val=t[2*p].val+t[2*p+1].val;
}
inline lld ask(int p,int x,int y){
   // mark_ask(p);
    //t[p].val+=t[p].tag*(t[p].r-t[p].l+1);          //1.先对自己val进行增加
    if(t[p].l >= x && t[p].r <= y) return t[p].val;
    mark_ask(p);
    lld sum=0;
    if(t[2*p].r >= x)   sum+=ask(2*p,x,y);
    if(t[2*p+1].l <= y) sum+=ask(2*p+1,x,y);
    return sum;
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
      //  for(int i=1;i<=7;++i) printf("t[%d]= %d  ",i,t[i].val);
        printf("%lld\n",ask(1,y,z));
    }
    else {
        scanf("%d%d",&y,&z);
      //  update(1,y,z,0);
        printf("%lld\n",ask(1,y,z));
     //  for(int i=1;i<=7;++i) printf("t[%d].val=%d ",i,t[i].val);
    }
   }

   return 0;
}

