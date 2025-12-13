#include <bits/stdc++.h>
using namespace std;
const int mxn = 3e3 + 5;
long double dp1[mxn], dp2[mxn], answer = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    dp2[0] = 1;
    for(int i = 1; i <= n; ++i){
        long double p;
        cin >> p;
        for(int j = 0; j <= i; ++j){
            dp1[j] = (j ? dp2[j - 1] * p : .0L) + (i > j ? dp2[j] * (1.0L - p) : .0L);
        }
        memcpy(dp2, dp1, sizeof(long double) * n + 1);
    }
    for(int i = n / 2 + 1; i <= n; ++i){
        answer += dp1[i];
    }
    cout << fixed << setprecision(9) << answer;
}
