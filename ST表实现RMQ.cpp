#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#define lld long long 
const int N =1e5+9;
const int K=log2(N);
using namespace std;
int ST[N][70];
int a[N];
int n,m;
inline int read();
void write(int x);
void build()
{
    for(int i=0;i<N;i++)
    ST[i][0]=a[i];

    for(int j=1;j<=K;j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        ST[i][j] = min(ST[i][j-1],ST[i + (1 << (j - 1))][j - 1]);
    }
}
lld query(int L,int R){
    int j=log2(R-L+1);
    int mmin=min(ST[L][j],ST[R - (1 << j) + 1][j-1]);
    return mmin;
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=0;i<n;++i) a[i]=read();
   //printf("%d",K);
   for(int j=1;j<=m;++j){
    int x,y;
    x=read();
    y=read();
    printf("%lld ",query(x,y));
   }
   //std::ios::sync_with_stdio(false);
   //std::cin.tie(0);


   return 0;
}



inline int read()
{
   int x=0,f=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){
      if(ch=='-')
      f=-1;
      ch=getchar();
   }
   while(ch>='0' && ch<='9')
   x=x*10+ch-'0',ch=getchar();
   return x*f;
}
void write(int x)
{
   if(x<0) putchar('-'),x=-x;
   if(x>9) write(x/10);
   putchar(x%10+'0');
   return;
}