#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define pque priority_queue
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define FordE(i, a, b) for (int i = a; i >= b; i--)
#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
#define PrintVl(x) for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
#define Ptest(a) return cout << a << endl, 0;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 50 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, c;
int a[N], b[N], p, q, t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> c;
    For(i, 0, n) cin >> a[i];
    For(i, 0, n) cin >> b[i];
    For(i, 0, n){
        t += b[i];
        p += max(0ll, a[i] - c * t);
    }
    t = 0;
    FordE(i, n - 1, 0){
        t += b[i];
        q += max(0ll, a[i] - c * t);
    }
    if (p < q) cout << "Radewoosh";
    else if (p > q) cout << "Limak";
    else cout << "Tie";
}

/*
----------------------------------+
INPUT:                            |
==============================    |

==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |

==============================    |
----------------------------------+
*/