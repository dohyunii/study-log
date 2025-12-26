#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int mxn = 2e5 + 5;
int h[mxn];
long long int bit[mxn];
long long int query(int r){
    long long int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret = max(ret, bit[r]);
    return ret;
}
void update(int n, int idx, long long int val){
    for (; idx <= n; idx = idx | (idx + 1))
        bit[idx] = max(bit[idx], val);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    for(int i = 0, a; i < n; ++i){
        cin >> a;
        update(n, h[i], query(h[i] - 1) + a);
    }
    cout << query(n);
}