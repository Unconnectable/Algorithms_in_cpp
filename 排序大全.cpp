#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#define lld long long 
const int N =1e6+9;
using namespace std;
int n,a[N],temp_1[N],temp_2[N],tem_3[N];

//form small to Big

inline int read();
void write(int x);
void init(){
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
}
void print(){
    for(int i=1;i<=n;++i) printf("%d ",a[i]);
}
void Selection_sort(){
    for(int i=1;i<=n;++i){
        int pos=i;
        for(int j=i+1;j<=n;++j){
            if(a[j]<a[pos]) pos=j; 
        }
        swap(a[pos],a[i]);
    }
}
void Bubble_sort(){
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(a[j]<a[i]) swap(a[i],a[j]);
        }
    }
}
void Insert_sort() {
  for (int i = 1; i <= n; ++i) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}
void quick_sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int left = l, right = r, pivot = a[(l + r) / 2]; // 选择中间元素作为pivot
    while (left<right ) {
        while (a[left] < pivot)  left++;
        while (a[right] > pivot) right--;
        if (left <= right) {
            std::swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    quick_sort(l, right); // 递归排序左半部分
    quick_sort(left, r); // 递归排序右半部分
}
int main()
{
   std::ios::sync_with_stdio(false);
   std::cin.tie(0);
   init();
   //Selection_sort();
   //Bubble_sort();
   //Insert_sort();
   //quick_sort(1,n);
   print();
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