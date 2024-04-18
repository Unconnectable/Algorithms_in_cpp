#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
#define lld unsigned long long 
const int N =1e5+9; 
using namespace std;
stack<int>q1;
template <typename T>//typename T == calss T
struct Stack_{
    //vector<T> data;
    T data[N];
    int pos=0;
    void push_(T x){
        data[++pos]=x;
    }
    bool empty_(){
        return pos==0;
    }
    int top_(){
        return data[pos];
    }
    void pop_(){
        if(pos>0){
            pos--;
        }
    }
    int size_(){
        return pos;
    }
};
Stack_<int> q;
int main()
{
     ios_base::sync_with_stdio(false); // 关闭输入输出流同步
    cin.tie(NULL); // 禁止cin和cout同步，加快输入速度
    return 0;
}
