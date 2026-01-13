#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
vector<pair<int, int>> a[mxn];
long long int t[mxn << 2], c[mxn << 2];
void push(int v, int tl, int tr){
    if(!c[v]){
        return;
    }
    t[v] += c[v];
    if(tl != tr){
        c[v << 1] += c[v];
        c[v << 1 | 1] += c[v];
    }
    c[v] = 0;
}
long long int query(int v, int tl, int tr, int l, int r){
    if(tl > r || tr < l){
        return 0;
    }
    push(v, tl, tr);
    if(tl >= l && tr <= r){
        return t[v];
    }
    int mid = tl + tr >> 1;
    return max(query(v << 1, tl, mid, l, r), query(v << 1 | 1, mid + 1, tr, l, r));
}
void update(int v, int tl, int tr, int l, int r, long long int x){
    push(v, tl, tr);
    if(tl > r || tr < l){
        return;
    }
    if(tl >= l && tr <= r){
        c[v] += x;
        push(v, tl, tr);
        return;
    }
    int mid = tl + tr >> 1;
    update(v << 1, tl, mid, l, r, x);
    update(v << 1 | 1, mid + 1, tr, l, r, x);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int l, r, x;
        cin >> l >> r >> x;
        a[r].push_back({ l, x });
    }
    for(int r = 1; r <= n; ++r){
        update(1, 1, n, r, r, query(1, 1, n, 1, r - 1));
        for(auto i : a[r]){
            auto [l, x] = i;
            update(1, 1, n, l, r, x);
        }
    }
    cout << max(0LL, t[1]);
}
