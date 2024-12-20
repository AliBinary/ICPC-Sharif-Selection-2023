/*
    author:  Ali
    Email: AliGhanbariCs@gmail.com
    GitHub: https://github.com/AliBinary
    created: 31.05.2024 09:23:53
*/
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define endl '\n'
#define sep ' '
typedef long long ll;
typedef long double ld;
typedef string str;

// pairs
typedef pair<ld, ld> pdd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
#define F first
#define S second
#define mp make_pair

#define tcT template <class T
tcT > using V = vector<T>;

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x));
#define sor_(x) sort(rall(x));
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define cpresent(container, element) (find(all(container), element) != container.end())
#define present(container, element) (container.find(element) != container.end())

// sets
#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, b) ROF(i, 0, b)
#define rep(n) FOR(_, 0, n)
#define each(x, a) for (auto &x : a)
#define tr(it, container) \
    for (typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

// debug
#define debug(x) cerr << #x << '=' << (x) << endl;
#define debugp(x) cerr << #x << "= {" << (x.first) << ", " << (x.second) << "}" << endl;
#define debug2(x, y) cerr << "{" << #x << ", " << #y << "} = {" << (x) << ", " << (y) << "}" << endl;
#define debugv(v)             \
    {                         \
        cerr << #v << " : ";  \
        for (auto x : v)      \
            cerr << x << ' '; \
        cerr << endl;         \
    }
#define wall cout << "----------------------------------------\n";
#define kill(x)            \
    {                      \
        cout << x << endl; \
        return;            \
    }

// bitwise ops
constexpr int pct(int x) { return __builtin_popcount(x); }               // # of bits set
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); } // floor(log2(x))
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }                     // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }                     // divide a by b rounded down
tcT > bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }                // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }                // set a = max(a,b)
tcT > void remDup(vector<T> &v) { sort(all(v)), v.erase(unique(all(v)), end(v)); } // sort and remove duplicates
bool cmp(pii &a, pii &b) { return (a.second < b.second); }

const int inf = std::numeric_limits<int>::max();
const ll INF = std::numeric_limits<ll>::max();
const ld epsilon = 1. / INF;
void solve();

void change(V<pair<int, char>> &a, int &m)
{
    each(x, a)
    {
        if (x.S == 'U')
        {
            if (x.F == m)
            {
                x.F = m - 1;
                x.S = 'D';
            }
            else
                x.F++;
        }
        else if (x.S == 'D')
        {
            if (x.F == 0)
            {
                x.F = 1;
                x.S = 'U';
            }
            else
                x.F--;
        }
    }
}

int main()
{
    fast_io;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    V<pair<int, char>> a(n);
    each(x, a)
    {
        cin >> x.F >> x.S;
    }
    int ans = 0;
    rep(m)
    {
        int cnt = 0;
        change(a, m);
        each(x, a)
        {
            cnt += x.F;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */