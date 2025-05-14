#include<bits/stdc++.h>
using namespace std;

// better apporach 
// time complexity is O(2*n + 2*n + n)
// space complexity is o(n);
vector<int> find_left_for_nagative(vector<int>& arr){
    int n=arr.size();
    vector<int> ans;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            s.push(arr[i]);
            ans.push_back(0);
            continue;
        }
        int flag=0;
        while(!s.empty()){
            if(s.top()>=abs(arr[i])){
                ans.push_back(0);
                flag=1;
                if(s.top()==abs(arr[i])){
                    s.pop();
                }
                break;
            }else{
                s.pop();
            }
        }
        if(flag==0){
            ans.push_back(1);
        }
    }
    return ans;
}

vector<int> find_right_for_positive(vector<int>& arr){
    int n=arr.size();
    vector<int> ans;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(arr[i]<=0){
            s.push(arr[i]);
            ans.push_back(0);
            continue;
        }
        int flag=0;
        while(!s.empty()){
            if(abs(s.top())>=arr[i]){
                ans.push_back(0);
                flag=1;
                if(abs(s.top())==arr[i]){
                    s.pop();
                }
                break;
            }else{
                s.pop();
            }
        }
        if(flag==0){
            ans.push_back(1);
        }
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> Asteroid_collision(vector<int>& arr){
    int n=arr.size();
    vector<int> ans;
    vector<int> left=find_left_for_nagative(arr);
    vector<int> right=find_right_for_positive(arr);

    for(int i=0;i<n;i++){
        if(left[i]==1 || right[i]==1){
            ans.push_back(arr[i]);
        }
    }
    return ans;

}

// optimal apporach 
// time complexity is O()
// space complexity is O()

vector<int> Asteroid_collision_optimal(vector<int> & arr){
    int n=arr.size();
    stack<int> s;
    vector<int> ans(n,0);
    for(int i=n-1;i>=0;i--){
        int flag=0;
        if(arr[i]<=0){
            s.push(i);
            ans[i]=1;
            continue;
        }
        while(!s.empty()){
            if(abs(arr[s.top()])>=arr[i]){
                ans[i]=0;
                flag=1;
                if(abs(arr[s.top()])==arr[i]){
                    ans[s.top()]=0;
                    s.pop();
                }
                break;
            }else{
                ans[s.top()]=0;
                s.pop();
            }
        }
        if(flag==0){
            ans[i]=1;
        }
    }
    vector<int> result;
    for(int i=0;i<n;i++){
        if(ans[i]==1){
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> ans= Asteroid_collision(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> optimal=Asteroid_collision_optimal(arr);
    for(auto it : optimal){
        cout<<it<<" ";
    }
    cout<<endl;

}