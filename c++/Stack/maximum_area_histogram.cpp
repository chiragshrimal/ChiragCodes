#include<bits/stdc++.h>
using namespace std;

vector<int> nearest_smaller_right(vector<int>& arr){
    vector<int> ans;
    stack<pair<int,int>> s;
    int n=arr.size();

    for(int i=n-1;i>=0;i--){
        while(!s.empty()){
            if(arr[i]>s.top().first){
                ans.push_back(s.top().second);
                break;
            }else{
                s.pop();
            }
        }
        if(s.empty()){
            ans.push_back(n);
        }
        s.push(pair(arr[i],i));

    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> nearest_smaller_left(vector<int>& arr){

    vector<int> ans;
    stack<pair<int,int>> s;
    int n=arr.size();

    for(int i=0;i<n;i++){
        while(!s.empty()){
            if(arr[i]>s.top().first){
                ans.push_back(s.top().second);
                break;
            }else{
                s.pop();
            }
        }
        
        if(s.empty()){
            ans.push_back(-1);
        }
        s.push(pair(arr[i],i));
    }
    return ans;
}

// optimal apporach 
// time complextiys is O()
// space comeplxity is O()

int maximum_area_histogram(vector<int>& arr){

    vector<int> left=nearest_smaller_left(arr);
    for(auto it : left){
        cout<<it;
    }
    cout<<endl;
    vector<int> right= nearest_smaller_right(arr);
    for(auto it : right){
        cout<<it;
    }

    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,abs(arr[i]*(abs(left[i]-right[i])-1)));
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    cout<<"enter n element "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi=maximum_area_histogram(arr);
    cout<<endl;
    cout<<maxi<<endl;
}