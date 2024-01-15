#include<bits/stdc++.h>
using namespace std;
//comparator funtion ulta kam krta hai 
//ydi apne false return kiya hai toh whi kam krta hain;
//isse bachne  ke liye jo chahiye usko retuen m likhte hai 
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first){
        return a.first<b.first;
    }else{
        return a.second>b.second ;
    }

}
bool cmp2(int a,int b){
    return a>b;
}
int main (){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    /*for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(should_i_swap(v[i],v[j])){//condition for swap ;
            //comparator bhi isi trh kam krta hai ;
            //comparator btata hai ki kis bases pr sort krna hai ;
            //u can give an extra comparator in sort ;
                swap(v[i],v[j]);
            }
        }
    }*/
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}