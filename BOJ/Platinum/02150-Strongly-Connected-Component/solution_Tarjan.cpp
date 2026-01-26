#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e4 + 5;
vector<int> g[mxn];
stack<int> st;
int tin[mxn], timer = 0, low[mxn];
vector<vector<int>> answer;
bool inStack[mxn];
void dfs(int v){
    tin[v] = low[v] = ++timer;
    st.push(v);
    inStack[v] = true;
    for(int i : g[v]){
        if (!tin[i]){
            dfs(i);
            low[v] = min(low[v], low[i]);
        } 
        else if(inStack[i]){
            low[v] = min(low[v], tin[i]);
        }
    }
    if (low[v] == tin[v]){
        vector<int> temp;
        while(true){
            int u = st.top();
            st.pop();
            inStack[u] = false;
            temp.push_back(u);
            if(v == u){
                break;
            }
        }
        answer.push_back(temp);
        sort(answer.back().begin(), answer.back().end());
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
    }
    for(int i = 1; i <= n; ++i){
        if(!tin[i]){
            dfs(i);
        }
    }
    cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    for(auto i : answer){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << "-1\n";
    }
}