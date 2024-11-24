#include<bits/stdc++.h>
using namespace std;

// majority element means >n/2;
// brute force apporach 
// calculate count of each element 
// time complexity is O(n^2)
// space complexity is O(1)
int majority_brute(int n,int arr[]){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>n/2){
            return arr[i];
        }
    }
    return -1;
}
// better apporach 
// time complexity is o(nlog(n));
// space complexity is o(n)

int majority_better(int n, int arr[]){
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto it : m){
        if(it.second>n/2){
            return it.first;
        }
    }
    return -1;

}

// optimal apporach 
// time compplexity is O(n);
// space complexity is o(1);
// called moore's voting algorithm 
int majority_optimal(int n, int arr[]){
    int element=0;
    int cnt=0;
    int i=0;
    while(i<n){
        if(cnt==0){
        element=arr[i];
        cnt++;
        }else{
            if(element==arr[i]){
                cnt++;
            }else{
                cnt--;
            }
        }
        i++;
    }
    if(cnt>0){
        int count=0;
        for(int i=0;i<n;i++){
            if(element==arr[i]){
                count++;
            }
        }
        if(count>n/2){
            return element;
        }
    }
    return -1;
}

int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int brute=majority_brute(n,arr);
    cout<<brute<<endl;
    int better=majority_better(n,arr);
    cout<<better<<endl;
    int optimal=majority_optimal(n,arr);
    cout<<optimal<<endl;

}