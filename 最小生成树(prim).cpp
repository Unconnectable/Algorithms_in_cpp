#include <cstdio>
#include <algorithm>
#include <vector>
#define lld long long 
const int N =1e3+9; 
const int MAXN=2e10+9;;
int n,m,s,ans;
using namespace std;
vector<vector<int> > G(N,vector<int>(N,0));
vector<int > dis(N,MAXN);
vector<bool > vis(N,0);
inline void init(){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            G[i][j]=0;
    for(int i=1;i<=m;++i) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(!G[x][y]) G[y][x]=G[x][y]=z;
        else G[x][y]=G[y][x]=min(G[x][y],z);
    }
    dis[1]=0;
}
inline void Prim(){
    for(int i=1;i<=n;++i){
        int u,mmin=MAXN;
        for(int j=1;j<=n;++j){
            if( vis[j]==0 && dis[j]<mmin ){
                mmin=dis[j];
                u=j;
            }
        }
        vis[u]=true;
        ans+=dis[u];
        for(int v=1;v<=n;++v){
            if( vis[v]==0  && G[u][v]!=0){
                dis[v]=min(G[u][v],dis[v]);
                
            }
        }
    }
    printf("%d",ans);
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    Prim();
    return 0;
}