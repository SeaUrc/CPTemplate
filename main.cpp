//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vll vector<long long>

using namespace std;

void setIO(string name = ""){
    cin.tie(0)->sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    if ((ll)(name.size())){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

template<typename T1, typename T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second << '\n'); }
ostream& operator<<(ostream &ostream, const vector<bool> &c) { for (bool it : c) cout << it << " "; return ostream; }
template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

class Fenwick {
private:
    int n;
    vector<int> tree;

public:
    Fenwick(int sz) : n(sz), tree(sz){}
    void add(int k, int x){ // pos k, increase by x
        while (k <= n){
            tree[k] += x;
            k += k & -k; // LSB
        }
    }
    int sum (int k) {
        int s = 0;
        while (k >= 1){
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }
};

class DisjointSets {
private:
    vector<int> parents;
    vector<int> sizes;

public:
    DisjointSets(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }
    int find(int x) {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
    int size(int x){
        return sizes[find(x)];
    }
};

template <typename T>
struct SegTree { // cmb(ID,b) = b
    const T ID{}; T cmb(T a, T b) { return (a&b); }
    int n; vector<T> seg;
    void init(int _n) { // upd, query also work if n = _n
        for (n = 1; n < _n; ) n *= 2;
        seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {	// zero-indexed, inclusive
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = cmb(ra,seg[l++]);
            if (r&1) rb = cmb(seg[--r],rb);
        }
        return cmb(ra,rb);
    }
};

ll modPow(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll modInv(ll x, ll m) {return modPow(x, m-2, m);}
bool isPrime(ll n) { if(n < 2) return false; for(ll k = 2; k * k <= n; k++) if(n % k == 0) return false; return true; }

ll binom(ll N, ll K, ll MOD, vector<ll> &factorial){
    return (factorial[N] * (modInv(factorial[K], MOD)%MOD * modInv(factorial[N-K], MOD)%MOD)%MOD)%MOD;
}

const ll MOD = 998244353;
const ll INF = 1e16; // INT64_MAX ~ 1.84e19
const int MAXN = 3e5+5;

void solve() {

}

int main() {
    setIO("");
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}