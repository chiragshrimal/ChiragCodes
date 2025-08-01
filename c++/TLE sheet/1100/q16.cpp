// 2D traversing
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

void solve()
{
    ll n;
    cin>>n;
    // cout<<n<<endl;
    vll c(n,0);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    // for(auto it : c){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    if(n==1){
        if(c[0]==1){
            cout<<"yes"<<endl;
            return ;
        }else{
            cout<<"no"<<endl;
            return ;
        }
    }
    sort(c.begin(),c.end());
    if(n<25 && c[n-1]>(1<<(n-2))){
        cout<<"no"<<endl;
        return ;
    }
    if(c[0]!=1 || c[1]!=1){
        cout<<"no"<<endl;
        return ;
    }
    ll sum=0;
    for(int i=0; i<n-1;i++){
        sum+=c[i];
        if(sum<c[i+1]){
            cout<<"no"<<endl;
            return ;
        }
    }
    cout<<"yes"<<endl;
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
