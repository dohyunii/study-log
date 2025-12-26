#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int mxn = 2e5 + 5;
int h[mxn];
long long int t[mxn << 2], dp[mxn];
void update(int v, int tl, int tr, int idx, long long int x){
    if(tl == tr){
        t[v] = x;
        return;
    }
    int mid = tl + tr >> 1;
    if(idx <= mid){
        update(v + v, tl, mid, idx, x);
    }
    else{
        update(v + v + 1, mid + 1, tr, idx, x);
    }
    t[v] = max(t[v + v], t[v + v + 1]);
}
long long int query(int v, int tl, int tr, int l, int r){
    if(tl > r || tr < l){
        return 0;
    }
    if(tl >= l && tr <= r){
        return t[v];
    }
    int mid = tl + tr >> 1;
    return max(query(v + v, tl, mid, l, r), query(v + v + 1, mid + 1, tr, l, r));
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
        dp[h[i]] = max(dp[h[i]], query(1, 1, n, 1, h[i] - 1) + a);
        update(1, 1, n, h[i], dp[h[i]]);
    }
    cout << query(1, 1, n, 1, n);
}