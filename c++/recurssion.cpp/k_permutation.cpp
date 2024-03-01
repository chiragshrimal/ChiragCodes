#include<bits/stdc++.h>
using namespace std;
int g(int n){
    if(n==0||n==1){
        return 1;
    }
    return g(n-1)*n;
}
void f(vector<int> &s,int k ,vector<int> &mark){
    if(s.size()==0){
        return ;
    }
    int div=k/g(s.size()-1);
    int rem=k%g(s.size()-1);
    mark.push_back(s[div]);
    s.erase(s.begin()+div);
    f(s,rem,mark);
}

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int k;
    cout<<"enter number of permutation"<<endl;
    cin>>k;
    k--;
    vector<int> v(n);
    vector<int> s(n);
    vector<int> mark;
    for(int i=0;i<n;i++){
        cin>>v[i];
        s[i]=v[i];
    }
    f(s,k,mark);
    for(auto value : mark){
        cout<<value;
    }
}