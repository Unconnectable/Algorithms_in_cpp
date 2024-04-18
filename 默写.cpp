#include <cstdio>
#include <cmath>
#include <vector>
#define lld long long 
const int N =2000;
const int M=2e10+1;
int n,m,s;
using namespace std;
vector<int> dis(N,M);
vector<int> vis(N,0);
vector<int> pre(N,0);
vector<vector<int> > G(N,vector<int> (N,0));
inline void init(){
   scanf("%d%d%d",&n,&m,&s);
   for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
         G[i][j]=0;
   for(int i=1;i<=m;++i){
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      if(!G[x][y]) G[x][y]=z;
      else G[x][y]=min(G[x][y],z);
   }
   dis[s]=0;
   //for(int i=1;i<=n;++i) dis[i]
}
inline void f(){
   for(int i=1;i<=n;++i){
      int u=-1,minn=M;
      for(int j=1;j<=n;++j){
         if(!vis[j] && dis[j]<minn){
            minn=dis[j];
            u=j;
         }
      }
     // if(u==-1) break;
      vis[u]=1;
      for(int v=1;v<=n;++v){
         if(!vis[v] && G[u][v]){
            dis[v]= min(G[u][v]+dis[u] ,dis[v]);
         }
      }
   }
   for(int i=1;i<=n;++i)
   printf("%d ",dis[i]);
}
int main()
{
   init();
   f();
   return 0;
}
