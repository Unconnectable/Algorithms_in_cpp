#include <cstdio>
#include <stack>
#include <vector>
#define lld long long 
using namespace std;
int n;
vector<lld> a(n,0);
vector<lld> ans(n,0);
template <class T>
struct Stack_{
    vector<T> data;
    //const int N =1e7+9;
    //T data[N];
    int pos=0;
    void push_(T x){
        data.push_back(x);
        pos++;
    }
    bool empty_(){
        return pos==0;
    }

    T top_(){
        return data.back();
    }
    void pop_(){
        if (!empty_()){
            data.pop_back();
            pos--;
        }
    }
    int size_(){
        return pos;
    }
};
Stack_<lld> q;
void f(){
    for(int i=1;i<=n;++i){
    if(q.empty_()) q.push_(i);
    else {
            while(a[i]>a[q.top_()] && !q.empty_()){
                ans[q.top_()]=i;
                q.pop_();
            }
            q.push_(i);
        }
    }
}
int main()
{
    scanf("%d",&n);
    a.resize(n+4);
    ans.resize(n+5);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    f();
    for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
    return 0;
}