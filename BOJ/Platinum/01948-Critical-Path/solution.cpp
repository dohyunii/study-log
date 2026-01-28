#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e4 + 5;
vector<pair<int, int>> g[mxn], rg[mxn];
bool vis[mxn];
int d[mxn];
vector<int> tp;
void dfs(int v){
    vis[v] = true;
    for(auto i : g[v]){
        if(!vis[i.first]){
            dfs(i.first);
        }
    }
    tp.push_back(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, st, fn, gold = 0;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        rg[v].push_back(make_pair(u, w));
        g[u].push_back(make_pair(v, w));
    }
    cin >> st >> fn;
    dfs(st);
    for(int i = n - 1; i >= 0; --i){
        for(auto j : g[tp[i]]){
            d[j.first] = max(d[j.first], j.second + d[tp[i]]);
        }
    }
    queue<int> q;
    memset(vis, false, sizeof(vis));
    vis[fn] = true;
    q.push(fn);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto j : rg[v]){
            if(d[j.first] + j.second == d[v]){
                if(!vis[j.first]){
                    q.push(j.first);
                    vis[j.first] = true;
                }
                ++gold;
            }
        }
    }
    cout << d[fn] << '\n' << gold;
}