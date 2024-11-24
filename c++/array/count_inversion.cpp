#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n^2)
// space complexity is O(1)
int count_inversion_brute(vector<int>& v){
    int n=v.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]){
                count++;
            }
        }
    }
    return count;
}
//optimal apporach like merge sort 
// time complexity is O(nlog(n))
// space complexity is O(n)
int merge(vector<int>& v,int l ,int mid,int h){
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
    int k=l;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]>v2[j]){
            count=count+v1.size()-i;
            v[k]=v2[j];
            j++;
        }else{
            v[k]=v1[i];
            i++;
        }
        k++;
    }
    while(i<v1.size()){
        v[k]=v1[i];
        i++;
        k++;
    }
    while(j<v2.size()){
        v[k]=v2[j];
        j++;
        k++;
    }
    return count;
}
int count_inversion_optimal(vector<int>& v,int l,int h){
    if(h==l){
        return 0;
    }
    int mid= l+(h-l)/2;
    int a=count_inversion_optimal(v,l,mid);
    int b=count_inversion_optimal(v,mid+1,h);
    // count inversion in two sorted array;
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
    int inversion=count_inversion_brute(v);
    cout<<inversion<<endl;

    int optimal=count_inversion_optimal(v,0,n-1);
    cout<<optimal<<endl;
    return 0;
}

