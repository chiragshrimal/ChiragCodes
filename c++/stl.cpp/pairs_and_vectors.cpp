#include<bits/stdc++.h>
using namespace std;

//vector<int> v(n);//phle se size bhi declare kr skte hai

void print_vector(vector<int> &v){//* and & ek dusre ki jaan le lete hai yha by vector pass kiya haia nhi toh copy hone m time complexity O(n)ho jati
        cout<<"size:"<<" "<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
        return ;
    }

int main (){

    //intialization of pair
   /* pair<int ,string>p;
    //p=make_pair(2,"shrimal");//1st methord to initialize of pair
    //p={2,"chirag"};//2nd methord to initialize of pair
    cin>>p.first;
    cin>>p.second;
    cout<<p.first<<" "<<p.second<<endl;*/


    //initialization of vector
    
    /*vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> &v2=v;//toh jo change v2 m honge whi change v m bhi honge 
    //print_vector(v);
        */

     //vector of pairs
    /*vector<pair<int,int>> v_p;
     //v_p={{1,2},{3,4},{5,6}};
     int k;
     cin>>k;
     for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        //v_p.push_back(make_pair(x,y));
        v_p.push_back({x,y});

     }
     v_p.pop_back();
     for(int i=0;i<v_p.size();i++){
        cout<< v_p[i].first<<" "<<v_p[i].second<<endl;
     } 
     */

     //array of vector

    /* int N;
     cin>>N;
     vector<int> v[N];
     for(int i=0;i<N;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
     }
     for(int i=0;i<N;i++){
        print_vector(v[i]);
     }
     */


     //vector of vector
      int N;
     cin>>N;
     vector<vector<int>> v_v;
     for(int i=0;i<N;i++){
        int n;
        cin>>n;
        //vector<int>temp;
        v_v.push_back(vector<int> ());//2nd methord
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            v_v[i].push_back(x);
        }
       // v_v.push_back(temp);
     }
     for(int i=0;i<v_v.size();i++){
        print_vector(v_v[i]);
     }
     
}