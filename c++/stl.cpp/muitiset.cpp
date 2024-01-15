#include<bits/stdc++.h>
using namespace std;
//same as normal map
//but we can add same type of key
int main(){
    multiset<int> s;
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=1;i<=n;i++){
         long long int x;
        cin>>x;
        s.insert(x);
    }
   long long  int count=0;
    for(int i=1;i<=k;i++){
        auto it=(--s.end());
        count=count+(*it);
        if(it!=s.end()){
            s.insert((*it)/2);
            s.erase(it);
        }else{
            cout<<"not reach at home"<<endl;
        }
    }
    cout<< count;

}