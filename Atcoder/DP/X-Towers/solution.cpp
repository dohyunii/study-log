#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e4 + 5;
struct Tower{
    int w, s, v;
} a[mxn];
long long int dp[mxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].w >> a[i].s >> a[i].v;
    }
    sort(a, a + n, [](const Tower &x, const Tower &y){
       return (x.w + x.s < y.w + y.s);
    });
    for(int i = 0; i < n; ++i){
        for(int j = a[i].s + a[i].w; j >= a[i].w; --j){
            dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
        }
    }
    cout << *max_element(dp, dp + mxn);
}