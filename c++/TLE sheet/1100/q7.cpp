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
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

// Function to calculate (a^b) % mod using Binary Exponentiation
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

// Function to find modular inverse using Fermat's Little Theorem (a^(MOD-2) % MOD)
ll mod_inv(ll a, ll mod = MOD)
{
    return power(a, mod - 2, mod);
}

// Function to check if a number is prime
bool is_prime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Function to compute GCD
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// Function to compute LCM
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Sieve of Eratosthenes for finding all prime numbers up to MAXN
const int N = 1e7 + 5;
vi high_primefactor(N, 0); // store high prime factor of ith element
vi low_primefactor(N, 0);  // store low prime factor of ith element
void sieve()
{
    vi v(N, 1); // let assume all numbers are prime
    v[1] = v[0] = 0;
    // sleves algorithm
    for (int i = 2; i < N; i++)
    { // time complexity is O(n*log(log(n)))
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

bool fun(ll h , vector<pair<ll,ll>>& v ,ll x){
    int n=v.size();
    ll count=0;
    for(int i=0;i<n;i++){
        if(h>v[i].first){
            count+=(h-v[i].first)*v[i].second;
        }
    }
    if(count>x){
        return false;
    }
    return true;
}

// time complextiy is n/1 + n/2 + n/3 + ...... n/k ==O(nlog(k)).
// space complexity is O(n)

void solve()
{
    ll n,x;
    cin >> n >> x;
    vll arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    unordered_map<ll,ll> m;
    for(auto it : arr){
        m[it]++;
    }
    vector<pair<ll,ll>> v;
    for(auto it : m){
        v.pb(pair(it.first,it.second));
    }
    sort(v.begin(),v.end());
    ll low =1;
    ll high =1e12;
    ll maxi=1;
    while(low<=high){
        ll mid = (low+high)/2;
        bool val=fun(mid, v,x);
        if(val){
            maxi=max(maxi,mid);
            low=mid+1;
        }else{
             high=mid-1;
        }
    }
    cout<<maxi<<endl;
    return ;

}

int main()
{
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
    solve();
    return 0;
}
