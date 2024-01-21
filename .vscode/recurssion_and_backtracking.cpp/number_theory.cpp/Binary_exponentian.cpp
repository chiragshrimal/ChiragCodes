#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
// a<= 1e9;
// b<=1e9;

int bit_exponention(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if ((b & 1) == 1)
            ans = (ans * a)%m;
             a = (a * a)%m;
             b = b >> 1;
    }
   
    return ans;
}
  //if a<=10^18
  // than call a%m phle kar ligiye 
  // ya fir issse bdi value ho toh function ko call kro 
  // if a<= 2^1024
int a_bit_exponention(int a, int b)
{
    a=a_bit_exponention(2,1024);
    int ans = 1;
    while (b)
    {
        if ((b & 1) == 1)
            ans = (ans * a)%m;
             a = (a * a)%m;
             b = b >> 1;
    }
   
    return ans;
}
// if  m<=10^18
// than 

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
int binary_multiplication (int a, int b)
{
    int sum  = 0;
    while (b)
    {
        if ((b & 1) == 1)
        sum=(sum+a)%m;
             a = (a * a)%m;
             b = b >> 1;
    }
   
    return sum;
}
int binary_exponention(int a, int b)
{ // time complexity is O(log(n))

    if(b==0){
        return 1;
    }
    int rest = binary_exponention(a, b/2);
    if ((b & 1) == 1) 
    {
        return (a * (rest * rest)%m)%m;
    }
    else
    { 
        return (rest * rest)%m;
    }
}

int main()
{
    // pow(2,3)--->> return double value
    // as we know bhut bde number m double m error aa jati hain
    int a, b;
    cin >> a>>b;
    int k = bit_exponention(a, b);
    cout << k << endl;
    int m=binary_exponention(a,b);
    cout<<m<<endl;
}