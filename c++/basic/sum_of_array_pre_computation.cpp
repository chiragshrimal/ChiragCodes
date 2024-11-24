#include<bits/stdc++.h>
using namespace std;
//q==10^5
//n==10^5
//given l and r and return sum from l index to r index
// agr negative number ho toh phle array ka min element find krke uske bad sub m us number ko positive bnake add kiya jaye or bad m ans dete time subtract kiya jaye 

int main(){
    int N=10^5;
   int q;
   cin>>q;
   int n;
   long long int b[N];
        cin>>n;
        int a[n];
        a[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=b[i-1]+a[i];
        }
    while(q--){
        int l;
        int r;
        cin>>l>>r;
        int sum=0;
        //for(int i=l;i<=r;i++){///O(n)
          //  sum+=a[i];
        //}
       cout<<a[r]-a[l-1]<<endl;//O(1)

    }
    //time complexity is more than 1 sec ;
}