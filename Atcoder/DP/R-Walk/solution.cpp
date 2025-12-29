#include <bits/stdc++.h>
using namespace std;
#define vt vector
typedef long long int ll;
const int mxn = 55;
int n;
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
vt<vt<mint>> a(mxn, vt<mint>(mxn)), res(mxn, vt<mint>(mxn));
vt<vt<mint>> mult(vt<vt<mint>> &b){
    vt<vt<mint>> ret(mxn, vt<mint>(mxn));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                ret[i][j] += b[i][k] * a[k][j];
            }
        }
    }
    return ret;
}
void bin_pow(ll m){
    while(m){
        if(m & 1){
            res = mult(res);
        }
        a = mult(a);
        m >>= 1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        res[i][i] = 1;
        for(int j = 0; j < n; ++j){
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }
    bin_pow(k);
    mint answer = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            answer += res[i][j].get();
        }
    }
    cout << answer.get();
}