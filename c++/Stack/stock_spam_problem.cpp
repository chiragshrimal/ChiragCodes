#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time completiys is O(N^2)
// space complextiys is O(N)

vector<int> stock_spam_brute(vector<int>& arr){

    vector<int> ans;
    int n=arr.size();
    
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i;j>=0;j--){
            if(arr[j]<=arr[i]){
                cnt++;
            }else{
                break;
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

// optimal apporach 
// time compolexity is O(2*N)
// space compelxtiys is O(N+N)

vector<int> stock_spam_optimal(vector<int>& arr){

    vector<int> ans;
    int n=arr.size();
    stack<pair<int,int>> s;

    for(int i=0;i<n;i++){
        int cnt=1;
        while(!s.empty()){
            if(s.top().first<=arr[i]){
                cnt+=s.top().second;
                s.pop();
            }else{
                break;
            }
        }
        ans.push_back(cnt);
        s.push(pair(arr[i],cnt));
    }
    return ans;
}

int main(){

    int n;
    cout<<"enter n element "<<endl;
    cin>>n;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans_brute=stock_spam_brute(arr);
    vector<int> ans_optimal=stock_spam_optimal(arr);

    cout<<"using brute force apporach "<<endl;

    for(auto it : ans_brute){
        cout<<it<<endl;
    }

    cout<<"using optimal apporach "<<endl;
    
    for(auto it : ans_optimal){
        cout<<it<<endl;
    }


}