#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// find the all permutation in sorted order 
// and to linear search to encode that arr
// then print next permutation to give your ans 
// but time complexity is very high across o(n!*n)
// space complexity is O(n!*n)


// better apporch 
// we have inbuild function in c++
vector<int> next_permutation_find(vector<int> &v){
    next_permutation(v.begin(),v.end());
    return v;
}
// optimal apporach to impliment next_permutation 
// time complexity is O(3*n)
// space complexity is O(1)

 void next_permutation_optimal(vector<int> &v){
     int n= v.size();
     int i;
    for(i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){ 
            break;
        }
    }
    if(i>=0){
    int just_max=INT_MAX;
    int number=v[i];
    int index=-1;
    for(int j=i+1;j<n;j++){
        if(number<v[j]){
            if(just_max>v[j]){
                just_max=v[j];
                index=j;
            }
        }
    }
    swap(v[i],v[index]);
    }
    reverse(v.begin()+i+1,v.end());

}
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    // vector<int> k= next_permutation_find(v);
    // for(auto it: k){
    //     cout<<it<<endl;
    // }
    next_permutation_optimal(v);
    for(auto it: v){
        cout<<it<<endl;
    }
}