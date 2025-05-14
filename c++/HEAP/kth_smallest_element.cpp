#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(nlog(n))
// space complexitty is o(1)

int brute_apporach(vector<int>&arr,int k){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    return  arr[k-1];
}

// optimal apporach
// time complexity is O(nlog(k))
// space complexity is o(log(k));

int optimal_apporach(vector<int>&arr,int k){

    int n=arr.size();
    priority_queue<int> h;
    for(int i=0;i<n;i++){
        h.push(arr[i]);
        if(h.size()>k){
            h.pop();
        }
    }
    return h.top();
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int brute=brute_apporach(arr,k);

    cout<<"using brute apporach "<<endl;
    cout<<brute<<endl;

    int optimal=optimal_apporach(arr,k);

    cout<<"using optimal apporach"<<endl;
    cout<<optimal<<endl;

}