#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'

#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define FordE(i, a, b) for (int i = a; i >= b; i--)

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, x, y, a, b;
	cin >> n >> x >> y;
	a = max(x - 1, y - 1);
	b = max(n - x, n - y);
	if (a > b) cout << "Black";
	else cout << "White";
}