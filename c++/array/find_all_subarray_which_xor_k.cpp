#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^3)
// space complexity is O(1)
int find_subarray_xor_brute(vector<int>& v,int p ){
    int n=v.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int z=0;
            for(int k=i;k<=j;k++){
                z=z^v[k];
            }
            if(z==p){
                count++;
            }
        }
    }
    return count;
}
// better apporach 
// time complexity is O(n^2)
// space complexity is O(1)

int find_subarray_xor_better(vector<int>& v,int p){
    int n=v.size();
    int count=0;
    for(int i=0;i<n;i++){
        int z=0;
        for(int j=i;j<n;j++){
            z=z^v[j];
            if(z==p){
                count++;
            }
        }
    }
    return count;
}
// optimal apporach 
// time complexity is O(n)
// space complexity is O(n);
int find_subarray_xor_optimal(vector<int>& v,int k){
    unordered_map<int,int > m;
    int n=v.size();
    int prefix_xor=0;
    int count=0;
    m.insert({0,1});
    for(int i=0;i<n;i++){
        prefix_xor=prefix_xor^v[i];
        //k
        int x=prefix_xor^k;
        count+=m[x];
        m[prefix_xor]++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>> k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x; 
        cin>>x;
        v.push_back(x);
    }
    int brute=find_subarray_xor_brute(v,k );
    cout<<brute<<endl;
    int better =find_subarray_xor_better(v,k);
    cout<<better<<endl;
    int optimal =find_subarray_xor_optimal(v,k);
    cout<<optimal<<endl;

}