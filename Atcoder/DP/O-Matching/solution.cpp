#include <bits/stdc++.h>
using namespace std;
const int mxn = 22, mod = 1e9 + 7;
long long int dp[mxn][1 << mxn];
bool a[mxn][mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        if(a[0][i]){
            ++dp[0][1 << i];
        }
    }
    for(int i = 1; i < n; ++i){
        for(int mask = 1; mask < (1 << n); ++mask){
            if(i + 1 == __builtin_popcount(mask)){
                for(int j = 0; j < n; ++j){
                    if(mask >> j & 1 && a[i][j]){
                        dp[i][mask] += dp[i - 1][mask ^ (1 << j)];
                        dp[i][mask] %= mod;
                    }
                }
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1];
}