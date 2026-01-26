#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e4 + 5;
vector<int> g[mxn], rg[mxn], tp, temp;
vector<vector<int>> answer;
bool vis[mxn];
void top_sort(int v){
    vis[v] = true;
    for(auto i : g[v]){
        if(!vis[i]){
            top_sort(i);
        }
    }
    tp.push_back(v);
}
void dfs(int v){
    vis[v] = true;
    temp.push_back(v);
    for(auto i : rg[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            top_sort(i);
        }
    }
    reverse(tp.begin(), tp.end());
    memset(vis, false, sizeof(vis));
    for(auto i : tp){
        if(!vis[i]){
            dfs(i);
            sort(temp.begin(), temp.end());
            answer.push_back(temp);
            temp.clear();
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(auto &i : answer){
        for(auto &j : i){
            cout << j << ' ';
        }
        cout << "-1\n";
    }
}