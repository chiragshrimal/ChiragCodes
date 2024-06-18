#include<bits/stdc++.h>
using namespace std;

// brute force apporach find all posiible way recurssion   
// time complexity is O(n^n)
// space complexity is O(n)

int jump_game2_brute(int index,int jump ,vector<int> & v){
    if(index>=v.size()-1){
        return jump;
    }
    int mini=INT_MAX;
    for(int i=1;i<=v[index];i++){
        mini=min(mini,jump_game2_brute(index+i,jump+1,v));
    }
    return mini;
}

// optimal apporach 
// time complexity is O(n)
//space complexity is o(1)

int jump_game2_optimal(vector<int>& v){
    int l=0;
    int r=0;
    int jump=0;
    int n=v.size();
    while(r<n-1){
        int farthest=0;
        for(int i=l;i<=r;i++){
            farthest=max(farthest,i+v[i]);
        }
        l=r+1;
        r=farthest;
        jump++;
    }
    return jump;
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
    int brute=jump_game2_brute(0,0,v);
    cout<<brute<<endl;

    int optimal=jump_game2_optimal(v);
    cout<<optimal<<endl;
}