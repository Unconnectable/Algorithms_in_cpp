#include <cstdio>
#include <cmath>
#include <algorithm>
//#include <iostream>
//#include <vector>
#define lld long long 

//using namespace std;

inline int read();
void write(int x);


int main()
{
   printf("%lld",MAXN);
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