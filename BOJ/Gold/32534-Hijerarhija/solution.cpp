#include <bits/stdc++.h>
using namespace std;
const int mxn = 3e5 + 5;
int ones = 0, zeros = 0, indeg[mxn], n;
set<int> g[mxn];
void print(){
    cout << (ones == n - 1 && zeros == 1 ? "DA" : "NE") << '\n';
}
void update(int &x, bool add){
    x += (add ? 1 : -1);
    if(x == 2 && add){
        --ones;
    }
    if(!x){
        ++zeros;
        if(!add){
            --ones;
        }
    }
    else if(x == 1){
        ++ones;
        if(add){
            --zeros;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        ++indeg[v];
    }
    for(int i = 1; i <= n; ++i){
        if(indeg[i] == 1){
            ++ones;
        }
        else if(!indeg[i]){
            ++zeros;
        }
    }
    cin >> q;
    print();
    while(q--){
        int u, v;
        cin >> u >> v;
        if(g[u].find(v) == g[u].end()){
            swap(u, v);
        }
        g[u].erase(v);
        g[v].insert(u);
        update(indeg[v], false);
        update(indeg[u], true);
        print();
    }
}