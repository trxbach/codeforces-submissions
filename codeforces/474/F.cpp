#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

// #define int long long
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
//int randt(int l, int r){ return (rando() % (r - l + 1) + l); }

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1e5 + 5, K = 20;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

int n, q;
int a[N];

struct segment_tree{
    pii seg[4 * N];
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = {a[l], 1};
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        if (seg[id << 1].fi < seg[id << 1 | 1].fi){
            seg[id] = seg[id << 1];
        }
        else if (seg[id << 1].fi > seg[id << 1 | 1].fi){
            seg[id] = seg[id << 1 | 1];
        }
        else{
            seg[id] = {seg[id << 1].fi, seg[id << 1].se + seg[id << 1 | 1].se};
        }
    }
    
    pii get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return {inf, 1};
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        pii x = get(id << 1, l, mid, u, v);
        pii y = get(id << 1 | 1, mid + 1, r, u, v);
        if (x.fi < y.fi){
            return x;
        }
        else if (x.fi > y.fi){
            return y;
        }
        else{
            return {x.fi, x.se + y.se};
        }
    }
} it;

int rmq[K][N];

int get(int l, int r){
    int z = log2(r - l + 1);
    return __gcd(rmq[z][l], rmq[z][r - (1 << z) + 1]);
}

void init(){
    ForE(i, 1, n){
        rmq[0][i] = a[i];
    }
    For(j, 1, K){
        ForE(i, 1, n - (1 << j) + 1){
            rmq[j][i] = __gcd(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    it.build(1, 1, n);
    init();
    cin >> q;
    ForE(i, 1, q){
        int l, r; cin >> l >> r;
        if (get(l, r) == it.get(1, 1, n, l, r).fi){
            cout << r - l + 1 - it.get(1, 1, n, l, r).se << endl;
        }
        else{
            cout << r - l + 1 << endl;
        }
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/