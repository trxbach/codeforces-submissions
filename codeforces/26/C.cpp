#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
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

const int N = 1e2 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e18 + 7;
const ll infll = 1e18 + 7;

int n, m;
char a[N][N];
int x, y, z;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void cal(vpii b){
    bool ck[26];
    mset(ck);
    Fora(v, b){
        For(i, 0, 4){
            int x = v.fi + dx[i], y = v.se + dy[i];
            if (a[x][y]){
                ck[a[x][y] - 'a'] = 1;
            }
        }
    }
    For(i, 0, 26){
        if (!ck[i]){
            Fora(v, b){
                a[v.fi][v.se] = (char)(i + 'a');
            }
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> z;
    if (2 * x + 2 * y + 4 * z < n * m) Ptest("IMPOSSIBLE");
    if ((n * m) & 1) Ptest("IMPOSSIBLE");
    if (n & 1){
        if (x < m / 2) Ptest("IMPOSSIBLE");
        ForE(i, 1, m / 2){
            cal({{n, i * 2 - 1}, {n, i * 2}});
            x--;
        }
    }
    if (m & 1){
        if (y < n / 2) Ptest("IMPOSSIBLE");
        ForE(i, 1, n / 2){
            cal({{i * 2 - 1, m}, {i * 2, m}});
            y--;
        }
    }
    ForE(i, 1, n / 2){
        ForE(j, 1, m / 2){
            if (z){
                cal({{i * 2 - 1, j * 2 - 1}, {i * 2 - 1, j * 2}, {i * 2, j * 2 - 1}, {i * 2, j * 2}});
                z--;
                continue;
            }
            if (x >= 2){
                cal({{i * 2 - 1, j * 2 - 1}, {i * 2 - 1, j * 2}});
                cal({{i * 2, j * 2 - 1}, {i * 2, j * 2}});
                x -= 2;
                continue;
            }
            if (y >= 2){
                cal({{i * 2 - 1, j * 2 - 1}, {i * 2, j * 2 - 1}});
                cal({{i * 2 - 1, j * 2}, {i * 2, j * 2}});
                y -= 2;
                continue;
            }
            Ptest("IMPOSSIBLE");
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            cout << a[i][j];
        }
        cout << endl;
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