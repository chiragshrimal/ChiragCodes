#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        int k;
        cin>>k;
        while(k--){
            string str;
            cin>>str;
            if(str.size()==n){
                unordered_map<char,int> m;
                int cnt=0;
                for(int i=0;i<n;i++){
                    if(m.find(str[i])==m.end()){
                        for(auto it : m){
                            if(it.second==v[i]){
                                cnt++;
                                cout<<"no"<<endl;
                                break;
                            }
                        }
                        if(cnt==0){
                            m[str[i]]=v[i];
                        }else{
                            break;
                        }
                    }else{
                        if(m[str[i]]!=v[i]){
                            cnt++;
                            cout<<"no"<<endl;
                            break;
                        }
                    }
                }
                if(cnt==0){
                    cout<<"yes"<<endl;
                    continue;
                }
            }else{
                cout<<"no"<<endl;
                continue;
            }
        }
    }
}

