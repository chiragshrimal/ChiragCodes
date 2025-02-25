#include<bits/stdc++.h>
using namespace std;


// brute force apporach 
// time complexity ---> O(N^2)
// space complexity is O(N)
vector<int> nearest_greater_right_brute(vector<int>& arr){
    vector<int> ans;
    int n=arr.size();
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                flag=1;
                ans.push_back(arr[j]);
                break;
            }
        }
        if(flag==0){
            ans.push_back(-1);
        }
        flag=0;
    }
    return ans;
}

// optimal apporach 
// time complexity is O(2*N)
// space complexity is O(N+N)
vector<int> nearest_greater_right_optimal(vector<int>& arr){
    vector<int> ans;
    stack<int> s;
    int n=arr.size();

    for(int i=n-1;i>=0;i--){
        while(!s.empty()){
            if(s.top()>arr[i]){
                ans.push_back(s.top());
                break;
            }else{
                s.pop();
            }
        }
        if(s.empty()){
            ans.push_back(-1);
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    cout<<"enter n element "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans_brute=nearest_greater_right_brute(arr);
    vector<int> ans_optimal=nearest_greater_right_optimal(arr);

    cout<<"using brute force apporach"<<endl;
    for(auto it : ans_brute){
        cout<<it<<endl;
    }
    cout<<"using optimal apporach"<<endl;
    for(auto it : ans_optimal){
        cout<<it<<endl;
    }

}
