#include<bits/stdc++.h>
using namespace std;
void print(unordered_map<int,string> &m){
    cout<<"size :"<<m.size()<<endl;
    for(auto value :m){
        cout<<value.first<<" "<<value.second<<endl;
    }
    }
int main (){
    //inbuilt implimentation of hashing 
    //exess or insert krne ki complexity o(1) hoti hai 
    //
    unordered_map<int ,string> m;//***isme hm complex data type nhi rkh skte like vector ,pair ,set map,etc
    //because inke hash function inbuilt nhi hote hai 
    //hm isme basic data type like int,double,float,string etc rkh skte hai
    m[1]="chirag";//o(1)
    m[9]="shrimal";
    m[3]="palasha";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        string s;
        cin>>s;
        m[x]=s;
    }
    auto it=m.find(1);
    if(it!=m.end()){
    cout<<(*it).first<<" "<<(*it).second;
    }else{
        cout<<"invalid"<<endl;
    }
    if(it!=m.end()){
        m.erase(it);
    }else{
        cout<<"invalid"<<endl;
    }
    
    print(m);


    //multimap 
    //isme ek se jyada same same keys ho skti hai
    //mmultimap ka use bhut kam hota hai 
    //becoz hm multimap lo map<int,vector<int>> ka use kr skte hai 
    //element lene ka trika m.insert();

    }