#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time comolexity is O(m*n)
// space complexity is O(n)
int assian_cookies_brute(vector<int>& s,vector<int>& g){
    int n=g.size();
    int m=s.size();
    int cnt=0;
    vector<int> check(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(check[j]==0 && s[i]>=g[j]){
                cnt++;
                check[j]=1;
                break;
            }
        }
    }
    return cnt;
}

// optimal apporach 
// time complexity is O()
// space complexity is O()
int assian_cookies_optimal(vector<int>& g,vector<int>& s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int n=g.size();
    int m=s.size();
    int i=0;
    int j=0;
    int cnt=0;
    while(i<n && j<m){
        if(s[j]>=g[i]){
            cnt++;
            i++;
            j++;
        }else{
            j++;
        }
    }
    return cnt;
}


int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> g;
    vector<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        g.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        s.push_back(x);
    }
    int brute=assian_cookies_brute(g,s);
    cout<<brute<<endl;

    int optimal=assian_cookies_optimal(g,s);
    cout<<optimal<<endl;
}