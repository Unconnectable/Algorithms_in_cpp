#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1e5 + 5;
const int LOG_MAXN = 20;
int a[MAXN];
int st[MAXN][LOG_MAXN];
const int N = 1e5;
int K = log2(N);
int lookup[N][LOG_MAXN];
int arr[N];

void build() {
    for (int i = 0; i < N; i++) {
        lookup[i][0] = arr[i];
    }
    for (int j = 1; j <= K; j++) {
        for (int i = 0; i + (1 << j) <= N; i++) {
            lookup[i][j] = min(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int j = log2(R - L + 1);
    int minimum = min(lookup[L][j], lookup[R - (1 << j) + 1][j]);
    return minimum;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    build();
    for (int j = 1; j <= m; ++j) {
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << " ";
    }
    return 0;
}