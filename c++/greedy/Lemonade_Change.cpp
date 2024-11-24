#include<bits/stdc++.h>
using namespace std;

// optimal  apporach 
// time complexity is O(n)
// space complxity is O(1)
bool lemonadeChange(vector<int>& v) {
        int n=v.size();
        int a=0;// for 5
        int b=0;// for 10
        if(v[0]!=5){
            return false;
        }
        for(int i=0;i<n;i++){
            if(v[i]==5){
                a++;
            }
            if(v[i]==10){
                b++;
                if(a>=1){
                    a--;
                }else{
                    return false;
                }
            }
            if(v[i]==20){
                if(a>=1 && b>=1){
                    a--;
                    b--;
                }else{
                    if(b==0 && a>=3){
                        a=a-3;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;

    }

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    bool check=lemonadeChange(v);
    cout<<check<<endl;
}