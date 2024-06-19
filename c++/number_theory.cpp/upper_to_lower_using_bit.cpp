#include<bits/stdc++.h>
using namespace std;
int main(){
    //upper case letter ki binary m 5th bit unset hoti hai 
    // or lower case lettter ki binary m 5th bit set hoti  hai

    char a=('A'|(1<<5));/// upper to lower
    cout<<a<<endl;
    // 1<<5  ====' '
    char b=('a'&(~(1<<5)));
    cout<<b<<endl;
    // ~(1<<5)  --->>> not a character
    // but 'a'&'_'===A
    // '_'== 000001011111
    

}