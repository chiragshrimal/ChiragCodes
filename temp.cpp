#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << " = " << x << endl;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Function to calculate (a^b) % mod using Binary Exponentiation
ll power(ll a, ll b, ll mod=MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Function to find modular inverse using Fermat's Little Theorem (a^(MOD-2) % MOD)
ll mod_inv(ll a, ll mod = MOD) {
    return power(a, mod - 2, mod);
}

// Function to check if a number is prime
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Function to compute GCD
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// Function to compute LCM
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Sieve of Eratosthenes for finding all prime numbers up to MAXN
const int N = 1e7 + 5;
vi high_primefactor(N,0);// store high prime factor of ith element
vi low_primefactor(N,0);// store low prime factor of ith element
void sieve() {
    vi v(N,1);// let assume all numbers are prime 
    v[1]=v[0]=0;
    // sleves algorithm 
    for(int i=2;i<N;i++){// time complexity is O(n*log(log(n)))
        if(v[i]==1){
            low_primefactor[i]=i;
            high_primefactor[i]=i;
            for(int j=i*2;j<N;j+=i){
                v[j]=0;
                if(low_primefactor[j]==0){
                    low_primefactor[j]=i;
                }
                high_primefactor[j]=i;
            }
        }
    }
}

long long int prefix_max(vll &arr, int l, int h){
    ll sum=0;
    ll maxsum=0;
    for(int i=h;i>=l;i--){
        sum=sum+arr[i];
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}

long long int sufix_max(vll &arr, int l, int h ){
    ll sum=0;
    ll maxsum=0;
    for(int i=l;i<=h;i++){
        sum=sum+arr[i];
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}

long long int maximum_subarray_sum(vll &arr, int l, int h){
    ll sum=0;
    int i=l;
    int j=l;
    ll maxsum=0;
    while(i<=j && j<=h){
        sum=sum+arr[j];
        maxsum=max(maxsum,sum);
        j++;
        if(sum<=0){
            sum=0;
            i=j;
        }
    }
    return maxsum;
}

void solve(){
    ll n,k;
    cin>>n;
    cin>>k;
    vll arr(n,0);
    string s;
    cin>>s;
    int count_zero=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(s[i]=='0'){
            count_zero++;
        }
    }
    vll index;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            index.push_back(i);
        }
    }

    if(count_zero==0){
        ll val=maximum_subarray_sum(arr,0,n-1);
        if(val>k || val<k){
            cout<<"no"<<endl;
            return ;
        }
        if(val==k){
            cout<<"yes"<<endl;
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            return ;
        }
    }
    vll vec;
    int i=0;
    ll val2=maximum_subarray_sum(arr,0,index[0]);
    vec.push_back(val2);
    for(;i<index.size()-1;i++){
        ll val=maximum_subarray_sum(arr,index[i],index[i+1]);
        vec.push_back(val);
    }
    ll val1=maximum_subarray_sum(arr,index[i],n-1);
    vec.push_back(val1);

    for(auto it : vec){
        if(it>k){
            cout<<"no"<<endl;
            return ;
        }
    }
    int flag=0;
    for(auto it : vec){
        if(it==k){
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout<<"yes"<<endl;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                arr[i]=-1e18;
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    cout<<"yes"<<endl;

    arr[index[0]]=k-prefix_max(arr,0,index[0])-sufix_max(arr,index[0],index.size()>=2?index[1]:n-1);

    for(int i=1;i<index.size();i++){
        arr[index[i]]=-1e18;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return ;  
}


int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
