#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << " = " << x << endl;
const ll MOD = 998244353;
const ll INF = LLONG_MAX;
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

ll power(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll a, ll mod = MOD)
{
    return power(a, mod - 2, mod);
}

bool is_prime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

const int N = 1e7 + 5;
vi high_primefactor(N, 0);
vi low_primefactor(N, 0);
void sieve()
{
    vi v(N, 1);
    v[1] = v[0] = 0;
    for (int i = 2; i < N; i++)
    {
        if (v[i] == 1)
        {
            low_primefactor[i] = i;
            high_primefactor[i] = i;
            for (int j = i * 2; j < N; j += i)
            {
                v[j] = 0;
                if (low_primefactor[j] == 0)
                {
                    low_primefactor[j] = i;
                }
                high_primefactor[j] = i;
            }
        }
    }
}

ll bs(vector<ll> &maxi, ll x, vector<ll> &presum)
{
    int n = maxi.size();
    if (maxi[n - 1] <= x)
    {
        return presum[n - 1];
    }
    if (maxi[0] > x)
    {
        return 0;
    }
    ll l = 0;
    ll h = n - 1;
    ll ans = INT_MIN;
    while (l < h)
    {
        ll mid = l + (h - l) / 2;
        if (maxi[mid] <= x)
        {
            ans = max(ans, presum[mid]);
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vll arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vll query(q, 0);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
    }
    vll presum(n, 0);
    presum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        presum[i] = presum[i - 1] + arr[i];
    }
    vll maxi(n, 0);
    maxi[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxi[i] = max(maxi[i - 1], arr[i]);
    }
    for (int i = 0; i < q; i++)
    {
        ll ans = bs(maxi, query[i], presum);
        cout << ans << " ";
    }
    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}