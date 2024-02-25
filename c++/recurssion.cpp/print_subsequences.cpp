#include<bits/stdc++.h>
using namespace std;

vector<int> v;
void print(vector<int> v){
    for(auto value:v){
        cout<<value;
    }
    cout<<endl;
}
int sum(vector<int> v){
    int sum=0;
    for(auto value: v){
        sum+=value;
    }
    return sum;
}

// we want print any one of sequence which sum is k
bool print_one(int arr[],int l,int h,int k){
    if(l>h){
        if(sum(v)==k){
            print(v);
            return true;
        }
        return false;
    }
    v.push_back(arr[l]);
    if(print_one(arr,l+1,h,k)==true){// let remaining sum de dega 
        return true;
    }
    v.pop_back();
    if(print_one(arr,l+1,h,k)==true){
        return true;
    }
    return false;
}
void sum_is_k(int arr[],int l,int h,int k){
     if(l>h){
        if(sum(v)==k){
        print(v);
        }
        return;
    }
        v.push_back(arr[l]);
        sum_is_k(arr,l+1,h,k);
        v.pop_back();
        sum_is_k(arr,l+1,h,k);

}

void f(int arr[],int l,int h){
    if(l>h){
        print(v);
        return;
    }
    v.push_back(arr[l]);
    f(arr,l+1,h);
    v.pop_back();
    f(arr,l+1,h);
}

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter numbers"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //f(arr,0,n-1);
    int k=3;
    sum_is_k(arr,0,n-1,k);

    //any one sequence is
    //print_one(arr,0,n-1,k);
}