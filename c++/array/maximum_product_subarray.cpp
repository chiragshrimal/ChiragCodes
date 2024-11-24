#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^3)
// space somplexity is O(1)
int maximun_product_subarray_brute(vector<int>& v){
    int n=v.size();
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product=1;
            for(int k=i;k<=j;k++){
                product*=v[k];
            }
            if(max<product){
                max=product;
            }
        }
    }
    return max;
}
// better apporach 
// time complexity is O(n^2)
// space complexity is O(1)
int maximun_product_subarray_better(vector<int>& v){
    int n=v.size();
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        int product=1;
        for(int j=i;j<n;j++){
            product*=v[j];
            if(max<product){
                max=product;
            }
        }
    }
    return max;
}
// optimal apporach 
// time complexity is O(n)
// space complexity is O(1)
int maximun_product_subarray_optimal(vector<int>& v){
    int n=v.size();
    int prefix=1;
    int suffix=1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix==0){
            prefix=1;
        }
        if(suffix==0){
            suffix=1;
        }
        prefix*=v[i];
        suffix*=v[n-i-1];
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;

}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute= maximun_product_subarray_brute(v);
    cout<<brute<<endl;
    int better=maximun_product_subarray_better(v);
    cout<<better<<endl;
    int optimal=maximun_product_subarray_optimal(v);
    cout<<optimal<<endl;
}