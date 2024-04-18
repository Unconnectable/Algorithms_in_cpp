#include <cstdio>
#include <vector>
using namespace std;
vector<int> fa;
vector<int> h;
int n,m;
inline int find(int x){
    while(x!=fa[x]) x=fa[x];
    return x;
}//path compressing
inline void add(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
    if(h[x]==h[y]) h[x]++,fa[y]=x;
    if(h[x]<h[y]) fa[x]=y;
    else fa[y]=x;
    }
}//merge  by  RANK
//O(m alpha(n));
inline void merge(){
    
}
inline void solve(){
    scanf("%d%d",&n,&m);
    fa.resize(n + 2);
    h.resize(n + 2);
    for(int i=1;i<=n;++i) fa[i]=i,h[i]=1;
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1)  add(y,z);
        else {
            if(find(y)==find(z)) printf("Y\n");
            else  printf("N\n");
        }
    }
}
int main()
{
    solve();
    for(int i=1;i<=n;++i){
        //printf("%d %d\n",i,fa[i]);
    }
    return 0;
}
