#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5, mod = 1e9 + 7;
vector<int> g[mxn];
long long int dp[mxn][2];
void dfs(int v, int p){
    dp[v][0] = dp[v][1] = 1;
    for(auto i : g[v]){
        if(i == p){
            continue;
        }
        dfs(i, v);
        dp[v][0] *= dp[i][0] + dp[i][1];
        dp[v][1] *= dp[i][0];
        dp[v][0] %= mod;
        dp[v][1] %= mod;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    cout << (dp[1][0] + dp[1][1]) % mod;
}