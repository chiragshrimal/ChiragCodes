#include<bits/stdc++.h>
using namespace std;
//lower_bound and upper_bound fuction always address return krte hai
//lower_bound ydi element milta hai toh uska eddress return krta hai o/w usse bda element ka address return krta hai
//agr us element se bda koi element koi hai hi nhi toh last element ke next element ka address return krta hai
//upper _bound always return address of next greater element 
//third line same as upper_bound 
//array,vector, etc sab sort hone chahiye 
//array ke case m c wale pointer ka use krte hai 
//vector ,map,sets etc m iterator ka use krte hai 
//lower_bound and upper_bound always take stating element ka address and 2nd argument as jha tak element ko lena hau uske next elemrnt ka addres
//agar data sorted hai toh ye O(lon(n)) complexity m kam krte hai
//agar data sorted nhi hai toh ye O(n) comlexity m kam krte hai  
//array or vector ke case m binary search ka se implimentation hota hai
// set or map ke case m tree se implimantation hota hai 
int main (){
     /*int n;
     cin>>n;
     ///int a[n];
     vector<int> v;
     for(int i=0;i<n;i++){
        //cin>>a[i];
        int x;
        cin>>x;
        v.push_back(x);
     }
     //sort(a,a+n);
     for(int i=0;i<n;i++){
        //cout<<a[i]<<" ";
        cout<<v[i]<<" ";
     }
     cout<<endl;
    // int *p=lower_bound(a,a+n,5);
     if(p!=a+n)
     //cout<<(*p)<<" ";
     else{
       // cout<<"invalid"<<endl;
     }
    // int *q=upper_bound(a,a+n,6);
     if(q!=a+n){
     //   cout<<(*q)<<endl;
     }else{
        //cout<<"invalid";
     }
     sort(v.begin(),v.end());
     iterator it=lower_bound(v.begin(),v.end(),5);
     if(it!=v.end())
     cout<<(*it)<<" ";
     else{
        cout<<"invalid"<<" ";
     }
     iterator it1=upper_bound(v.begin(),v.end(),6);
     if(it1!=v.end())
     cout<<(*it1)<<" ";
     else{
        cout<<"invalid"<<" ";
     }*/


     /// in case of set aand map m kese use hota hai wo *** important hai 
     set<int> s;//already sorted toh hota hi hai 
     for(int i=1;i<=(int)1e9;i++){
        s.insert(rand());
     }
     for(int i=1;i<=1e6;i++){
        // auto it=lower_bound(s.begin(),s.end(),rand());//it take o(n) time 
        auto it =s.lower_bound(rand()); //it take O(log(n)) time 
     cout<<(*it)<<" ";
     }
      // in case of map

      map<int,int> m;//already sorted toh hota hi hai 
      //in case of map key pr hi upper_bound and lower_bound lgate hai 
      // toh wo us key ke corresponding iterator  written krte hai 
      // agr multiple key present hai toh first wale ka iterator deta hai
     for(int i=1;i<=(int)1e9;i++){
        m[i]=rand();
     }
     for(int i=1;i<=1e6;i++){
        // auto it=lower_bound(m.begin(),m.end(),rand());//it take o(n) time 
        auto it =m.lower_bound(rand()); //it take O(log(n)) time 
       cout<<((*it).first)<<" ";  
     }

}