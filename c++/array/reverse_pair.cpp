#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^2)
// space complexity is  O(1)
int reverse_pair_brute(vector<int>& v){
    int n=v.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>2*v[j]){
                count++;
            }
        }
    }
    return count;
}
int merge(vector<int>& v,int l,int mid,int h){
    vector<int> v1;
    vector<int> v2;
    for(int i=l;i<=mid;i++){
        v1.push_back(v[i]);
    }
    for(int i=mid+1;i<=h;i++){
        v2.push_back(v[i]);
    }
    int i=0;
    int j=0;
    int count=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]>2*v2[j]){
            count=count+v1.size()-i;
            j++;
        }else{
            i++;
        }
    }
    int p=0;
    int q=0;
    int k=l;
    while(p<v1.size() && q<v2.size()){
        if(v1[p]<v2[q]){
            v[k]=v1[p];
            p++;
        }else{
            v[k]=v2[q];
            q++;
        }
        k++;
    }
    while(p<v1.size()){
        v[k]=v1[p];
        p++;
        k++;
    }
     while(q<v2.size()){
        v[k]=v2[q];
        q++;
        k++;
    }
    return count;
}
int reverse_pair_optimal(vector<int>& v,int l ,int h){
    if(h==l){
        return 0;
    }
    int mid=l+(h-l)/2;
    int a=reverse_pair_optimal(v,l,mid);
    int b=reverse_pair_optimal(v,mid+1,h);
    // merge them 
    int c=merge(v,l,mid,h);
    return a+b+c;
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
    int brute=reverse_pair_brute(v);
    cout<<brute<<endl;

    int optimal=reverse_pair_optimal(v,0,n-1);
    cout<<optimal<<endl;

}