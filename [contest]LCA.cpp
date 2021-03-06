
#include <bits/stdc++.h>
using namespace std;

#define hey(x) cerr << #x << " : " << x << "\n";
#define int long long int
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int, int> >
#define vvpi vector<vector<pair<int, int> > >
#define all(v) (v).begin(), (v).end()	
#define rall(v) (v).rbegin(), (v).rend()
#define pii pair<int, int>
#define pb push_back
#define SZ(x) (int)(x).size()
#define inf 1e12
#define F first
#define S second
#define fill(v, val) memset((v), val, sizeof(v))
#define PI 3.1415926535897932384626
#define out cout << fixed << setprecision(12)
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define hey2(x, y) cerr << #x << " : " << x << "," << #y << " : " << y << '\n';

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

vi g[N];
int u, v;

int dp[N][31];
int lvl[N];

void dfs(int u, int par){
    dp[u][0] = par;
    lvl[u] = lvl[par] + 1;
    
    for(int i = 1; i <= 30; ++i)
        if(dp[u][i-1] != -1)
            dp[u][i] = dp[dp[u][i-1]][i-1];
    
    for(int v: g[u]) if(v != par)
            dfs(v, u);
}

int lca(int u, int v){
    if(lvl[u] < lvl[v])
        swap(u, v);
    for(int i = 30; ~i; --i)
        if(lvl[u] - (1 << i) >= lvl[v])
            u = dp[u][i];
    if(u == v)
        return u;
    for(int i = 30; ~i; --i)
        if(dp[u][i] ^ dp[v][i])
            u = dp[u][i],v = dp[v][i];
    return dp[u][0];
}

int32_t main()
{    
    ios::sync_with_stdio(false);
    cin.tie(0);
    // ----------------------- Initialization ------------------------
    int n;
    cin >> n;
    for(int i = 0; i + 1 < n; ++i){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(dp, -1, sizeof(dp));
    lvl[0] = -1;
    
    dfs(1, 0);
    // ---------------------write code below-----------------------------
    
    return 0;
}
