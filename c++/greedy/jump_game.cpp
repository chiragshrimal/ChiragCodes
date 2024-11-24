#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
// time complexity is O(n)
// sspace compelxity is O(1)

int jump_game(vector<int>& v){
    int n=v.size();
    int max_index=0;
    for(int i=0;i<n;i++){
        if(max_index>=i){
            max_index=max(i+v[i],max_index);
        }else{
            return false;
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
    bool check= jump_game(v);
    cout<<check<<endl;
}    