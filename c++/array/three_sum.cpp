#include<bits/stdc++.h>
using namespace std;
//q 
// find all triplet whose sum is zero (unique triplet)
// brute force apporach 
// time complexity is o(n^3)
// space complexity is O(n^3)
set<vector<int>> sum_brute(vector<int>& v ){
    set<vector<int>> s;
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(v[i]+v[j]+v[k]==0){
                    vector<int> temp={v[i],v[j],v[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    return s;
}
// good concept to use same key in the set
// better apporach 1;->> writen below
// better apporach 2:->> you can sort before the loop so.
// time complexity is O(n^2* log(n))
// space complxity is O(n^3)
set<vector<int>> sum_better(vector<int>& v){
    unordered_set<int> s;
    set<vector<int>>ans;
    int n=v.size();
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=i+1;j<n;j++){
            int k=-(v[i]+v[j]);
            auto it =s.find(k);// 
            if(it!=s.end()){
                temp={v[i],v[j],k};
                sort(temp.begin(),temp.end());
            }
            s.insert(v[j]);
        }
        s.clear();
        ans.insert(temp);// insert into ordered set; then o(log(n^3));
    }
    return ans;

}
// optimal apporach 
// time complexity is O(n^2)
//space complexity is O()
set<vector<int>> sum_optimal(vector<int>& v){
    sort(v.begin(),v.end());
    int n=v.size();
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=v[i]+v[j]+v[k];
            if(sum==0){
                vector<int> temp={v[i],v[j],v[k]};
                s.insert(temp);
                int tempj=v[j];
                int tempk=v[k];
                j++;
                while(j<n && v[j]==tempj){
                    j++;
                }
                k--;
                while(k>=0 && v[k]==tempk){
                    k--;
                }
            }else{
                if(sum>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
    }
    return s;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<vector<int>> brute=sum_brute(v);
    for(auto it : brute){
        for(auto k : it){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    set<vector<int>> better=sum_better(v);
     for(auto it : better){
        for(auto k : it){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    set<vector<int>> optimal=sum_optimal(v);
     for(auto it : optimal){
        for(auto k : it){
            cout<<k<<" ";
        }
        cout<<endl;
    }
}