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
    // for(auto it : left){
    //     cout<<it;
    // }
    // cout<<endl;
    vector<int> right= nearest_smaller_right(arr);
    // for(auto it : right){
    //     cout<<it;
    // }
    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,abs(arr[i]*(abs(left[i]-right[i])-1)));
    }
    return maxi;
}

// otimal apporach 
// time complexitye is O()
// space compelxity is O()

int max_area_rectangle(vector<vector<int>>& arr){

    int n=arr.size();
    int m=arr[0].size();

    vector<vector<int>> height(n,vector<int>(m,0));

    height[0]=arr[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                height[i][j]=height[i-1][j]+arr[i][j];
            }
        }
    }

    vector<int> ans;
    for(int i=0;i<n;i++){
        int temp=maximum_area_histogram(height[i]);
        ans.push_back(temp);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<height[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int maxi=0;
    for(auto it :ans){
        maxi=max(maxi,it);
    }
    return maxi;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int ans=max_area_rectangle(v);
    cout<<ans<<endl;
}