#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^3)
// space complexity is O(1)
// you have already done 
// like find all subarray and then calculate 





// better apporach 
// time complexity is O(n^2)
// space complexity is O(1)
// you have already solved 







// optimal apporach (good apporach)
// time complexity is O(n)
//space complexity is O(n)
int count_subarray_optimal(vector<int> &v,int k){
    unordered_map<int,int> m;// <prefxsum,count>
    int n=v.size();
    int prefix_sum=0;
    int count=0;
    m.insert({0,1});
    for(int i=0;i<n;i++){
        prefix_sum+=v[i];
        auto it =m.find(prefix_sum -k);
        if(it!=m.end()){
            count+=m[prefix_sum-k];
        }
        auto p=m.find(prefix_sum);
        if(p!=m.end()){
            m[prefix_sum]++;
        }else{
            m.insert({prefix_sum,1});
        }
    }
    return count;
}
int main(){
int n;
cin>>n;
int k;
cin>>k;
vector<int > v(n,0);
for(int i=0;i<n;i++){
    cin>>v[i];
}
int ans=count_subarray_optimal(v,k);
cout<<ans<<endl;


}