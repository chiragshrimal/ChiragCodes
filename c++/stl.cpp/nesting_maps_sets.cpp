#include<bits/stdc++.h>
using namespace std;
int main (){
    //comparision of pair and set based on first element 
    //but first is same then based on second element 

   // map<pair<int,int>,set<int>>;
    //set<pair<int,int>>;
    //map<pair<int,int>,set<int>>;
    //map<vector<int>,set<int>>;
    //set<map<int,int>>;
    map<pair<string,string>,vector<int>> m;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string firstname;
        cin>>firstname;
        string lastname;
        cin>>lastname;
        int k;
        cin>>k;
        //vector<int> temp;
        for(int i=1;i<=k;i++){
            int x;
            cin>>x;
            m[{firstname,lastname}].push_back(x);
           //temp.push_back(x);
        }
        //m[{firstname,lastname}]=temp;
    }
    for(auto value :m){
        cout<<"size :"<<value.second.size()<<endl;
        cout<<value.first.first<<" "<<value.first.second<<endl;
        for(auto key :value.second){
            cout<<key<<" ";
        }
        cout<<endl;
    }
    

}