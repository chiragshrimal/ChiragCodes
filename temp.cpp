#include<bits/stdc++.h>
using namespace std;


int binary_multiplication (int a, int b)
{
    int m=1e9+7;
    int sum  = 0;
    while (b)
    {
        if ((b & 1) == 1){
            sum=(sum+a)%m;
        }
             a = (a + a)%m;
             b = b >> 1;
    }
    
    return sum;
}
int m_bit_exponention(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if ((b & 1) == 1)
            ans = binary_multiplication(ans,a);
             a = binary_multiplication(a,a);
             b = b >> 1;
    }
   
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<1<<endl;
            continue;
        }
        int result=m_bit_exponention(2,y);
        cout<<result<<endl;
    }
    return 0;
}
