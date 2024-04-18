#include <cstdio>
#include <algorithm>
#define lld long long 
const int N =1e6+9; 
using namespace std;
struct node{
    int u,v,w;
};
node t[N];
int n,m,sum,fa[N],cnt;
int mink(int a,int b){
    return a<b?a:b;
}
inline void init(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
    for(int i=1;i<=m;++i) fa[i]=i;
}
bool cmp(node a,node b){
    return a.w<b.w;
}
inline int find(int x){
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
inline void add(int x,int y){
    //x become y's acesstor's son
    fa[find(x)]=find(y);
}
inline void Kruskal(){
    int e_pre,e_next;
    sort(t+1,t+1+m,cmp);
    for(int i=1;i<=m;++i){
        e_pre=find(t[i].u);
        e_next=find(t[i].v);
        if(e_pre==e_next) continue;
        sum+=t[i].w;
        fa[e_pre]=e_next;
        printf("%d\n",t[i].w);
        if(++cnt==n-1) break; 
    }
}
int main()
{
    init();
    Kruskal();
    if(cnt==n-1)
        printf("%d",sum);
    //else printf("orz");
    return 0;
}
