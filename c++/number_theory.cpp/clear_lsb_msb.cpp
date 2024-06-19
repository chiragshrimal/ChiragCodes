#include<bits/stdc++.h>
using namespace std;
void print_binary(int n){
    for(int i=5;i>=0;i--){
        cout<<(((n>>i)&1));
    }
    return ;
}
int main() {
    int n;
    cin>>n;
    print_binary(n);
    cout<<endl;
    int i;
    cin>>i;
    int clear_lsb=(n&(~((1<<(i+1))-1)));
    print_binary(clear_lsb);
    cout<<endl;
    int clear_msb=(n&((1<<(i+1))-1));
    print_binary(clear_msb);

}