#include <bits/stdc++.h>
using namespace std;
const int mxn = 3005, inf = 0x3f3f3f3f;
long long int dp[mxn][mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -0x3f, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> dp[i][i];
    }
    for(int len = 2; len <= n; ++len){
        for(int i = 0; i < n - len + 1; ++i){
            int j = i + len - 1;
            dp[i][j] = max((i + 1 <= j ? dp[i][i] - dp[i + 1][j] : -inf), (i <= j - 1 ? dp[j][j] - dp[i][j - 1] : -inf));
        }
    }
    cout << dp[0][n - 1];
}