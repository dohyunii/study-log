#include <bits/stdc++.h>
using namespace std;
const int mxn = 22, mod = 1e9 + 7;
long long int dp[1 << mxn];
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
    dp[0] = 1;
    for(int mask = 1; mask < (1 << n); ++mask){
        for(int j = 0; j < n; ++j){
            int i = __builtin_popcount(mask) - 1;
            if(mask >> j & 1 && a[i][j]){
                dp[mask] += dp[mask ^ (1 << j)];
                dp[mask] %= mod;
            }
        }
    }
    cout << dp[(1 << n) - 1];
}