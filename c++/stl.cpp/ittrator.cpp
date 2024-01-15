#include<bits/stdc++.h>
using namespace std;
int main(){
    //ittrator pointer llike structure 
    //ye container ka address store krte hai

    //uses
    //vector m kisi bhi element ko exsses krna hai toh index ka use krte hai 
    //but map,set m index ka nhi uski jgh pointer ka use krte hai

    vector<pair<int,int>> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
   /*vector<int> :: iterator it=v.begin();//implementation of iterator
    //data_type :: iterator it;
    //v.begin==address of ist element of vector

    for( it=v.begin();it!=v.end();it++){
        cout<<(*it)<<endl;
    }*/

    
   /*vector<pair<int,int>>v_p={{1,2},{3,4}};
    vector<pair<int,int>> :: iterator it =v_p.begin();
    

    for(it=v_p.begin();it!=v_p.end();it++){//1st methord 
         cout<<(*it).first<<" "<<(*it).second<<endl;
    }
     for(it=v_p.begin();it!=v_p.end();it++){//2nd methord 
         cout<<(it->first)<<" "<<(it->second)<<endl;
    }*/


    //short form of for loop in c++*******
    for(pair<int,int> value :v){//copy create hoti hai 
    swap(value.first,value.second);
        cout<<value.first<<value.second<<endl;
    }
    for(pair<int,int> &value :v){//by refrences 
    swap(value.first,value.second);
        cout<<value.first<<" "<<value.second;
    }  

     for(auto value : v){//using *******auto***** variable 
        cout<<value.first<<" "<<value.second;
    }

   
} 