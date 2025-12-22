#include <bits/stdc++.h>
using namespace std;
const int mxn = 105, mxk = 1e5 + 5, mod = 1e9 + 7;
int a[mxn];
long long int dp[mxk], pref[mxk];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        pref[0] = dp[0];
        for(int j = 1; j <= k; ++j){
            pref[j] = (pref[j - 1] + dp[j]) % mod;
        }
        for(int j = 0; j <= k; ++j){
            dp[j] = (pref[j] - (j - a[i] - 1 < 0 ? 0 : pref[j - a[i] - 1]) + mod) % mod;
        }
    }
    cout << dp[k];
}