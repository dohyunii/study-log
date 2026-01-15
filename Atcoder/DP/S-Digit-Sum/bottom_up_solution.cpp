#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
template <int MOD> struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  ModInt pow(ll p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};
typedef ModInt<1000000007> mint;
const int mod = 1e9 + 7, mxn = 1e4 + 5, mxd = 105;
string x;
int d, n;
mint dp[mxn][2][mxd];
mint solve(int pos, bool f, int c){
    if(pos == n){
        return !c;
    }
    if(dp[pos][f][c].get() != -1){
        return dp[pos][f][c];
    }
    dp[pos][f][c] = 0;
    for(int i = 0; i <= (f ? 9 : x[pos] - '0'); ++i){
        dp[pos][f][c] += solve(pos + 1, f | (i < x[pos] - '0'), (c + i) % d);
    }
    return dp[pos][f][c];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> x >> d;
    n = (int)x.size();
    cout << (solve(0, false, 0).get() - 1 + mod) % mod;
}