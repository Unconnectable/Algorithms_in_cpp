
/*

time O(n^2)
way: adjacency matrix
1:Static array
2:Dynamic array ,just vector
*/
//version:1
#include<cstdio>
#include<algorithm>

const int N=1e4+9;//scale
const int  M=2e10+9;//infinity in INT
int mink(int a,int b){
    return a<b?a:b;
}
using namespace std;
int G[N][N]; //adjacency matrix
bool vis[N];//have visited vertex u or not
int dis[N];//distance initialized infty
bool tag[N][N];
int track[N];
int x,y,z,n,m,s,ans;
void init(){
    scanf("%d%d",&n,&m);
    //initialize G=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            G[i][j]=0;

    for(int i=1;i<=m;++i){
        //scanf("%d%d%d",&n,&m,&s);
        //G[x][y]=z,G[y][x]=z;
        scanf("%d%d%d",&x,&y,&z);
        if(!G[x][y]) G[x][y] =z ;
        else G[x][y]= mink(G[x][y],z);
        //Multiple digraphs get smaller 
        // if undigraph G[x][y]=G[y][x]=z;
    } 
    for(int i=1;i<=n;++i) dis[i]=M,vis[i]=false;
    dis[s]=0;
}
void Dijitra(int x){
    for(int i=1;i<=n;++i){
        int u, mmin=M;//now minn
        for(int j=1;j<=n;++j){
            if( !vis[j] && dis[j] < mmin){
                mmin=dis[j];
                u=j;
            }
        }
        track[i]=u;
        ans+=dis[u];
        vis[u]=true;//put u to S
        //for v in V-S
        for(int v=1;v<=n;++v){
            if( !vis[v] && G[u][v] ){
                dis[v]=mink( dis[v], dis[u]+G[u][v] );
                //update dis[v] in V-S
            }
        }
    }
}
int main(){
    init();
    Dijitra(s);
 //   for(int i=1;i<=n;++i) 
        //printf("%d track=%d\n",dis[track[i]],track[i]);
 //       printf("%d ",dis[i]);
    printf("%lld",ans);
    return 0;
}
//version2:vector
/*
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<vector>
#define lld long long 
const int N =1010; 
//!!!!
//!!!!
const int MAXN=2147483647;//infinity
//!!!
//!!!
using namespace std;
vector<int > dis(N,MAXN);
vector<bool > vis(N,0);
vector<int > pre(N,0);
vector<vector<int> > G(N,vector<int>(N,0));
int n,m,s;
void read(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            G[i][j]=0;
    for(int i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(G[x][y]!=0) G[x][y]=min(G[x][y],z);
        else G[x][y]=z;
    }
    dis[s]=0;
}
inline void Dijstra(){
    for(int i=1;i<=n;++i){
        int u,mmin=MAXN;
        for(int j=1;j<=n;++j){
            if(!vis[j] && dis[j]<mmin ){
                mmin=dis[j];
                u=j;
            }
        }
        vis[u]=true;
        for(int v=1;v<=n;++v){
            if(!vis[v] && G[u][v] ){
                dis[v]=min(dis[v],dis[u]+G[u][v]);
            }
        }
    }
}
inline void print(){
    for(int i=1;i<=n;++i){
        if(i==n) printf("%d",dis[i]);
        else  printf("%d ",dis[i]);
    }
}
int main()
{
    read();
    Dijstra();
    print();
    return 0;
}
*/