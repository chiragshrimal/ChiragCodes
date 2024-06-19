#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
//  time complexity is O(n^2)
// space complexity id O(n)
int minimum_platform_brute(vector<int>& arr,vector<int>& dep){
    int n=arr.size();
    int cnt=0;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty()){
            cnt++;
            ans.push_back({arr[i],dep[i]}); 
        }else{
            int k=0;
            for(int j=0;j<ans.size();j++){
                if(ans[j][1]>arr[i]){// overlapping ki or bhi conditions aayegi 
                    k++;
                }else{
                    ans[j][0]=arr[i];
                    ans[j][1]=dep[i];
                    break;
                }
            }
            if(k==ans.size()){
                cnt++;
                ans.push_back({arr[i],dep[i]});
            }
        }
    }
    return cnt;
}

// optimal apporach 
// time complexity is O(n*log(n))
// space complexity is O(2*n)

int minimum_platform_optimal(vector<int>& arr, vector<int>& dep){
    int n=arr.size();
    int cnt=0;
    int maxcnt=0;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        ans.push_back({arr[i],0});
    }
    for(int i=0;i<n;i++){
        ans.push_back({dep[i],1});
    }
    sort(ans.begin(),ans.end());

    for(int i=0;i<2*n;i++){
        if(ans[i][1]==0){
            cnt++;
            maxcnt=max(maxcnt,cnt);
        }else{
            cnt--;
        }
    }
    return maxcnt;
}

// optimize space complexity is O(1)
int minimum_platform_optimal2(vector<int>& arr,vector<int>& dep){
    int n=arr.size();
    int cnt=0;
    int maxcnt=0;
    int i=0;
    int j=0;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            cnt++;
            maxcnt=max(maxcnt,cnt);
            i++;
        }else{
            cnt--;
            j++;
        }
    }
    return maxcnt;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr;
    vector<int> dep;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        dep.push_back(y);
    }
    int brute =minimum_platform_brute(arr,dep);
    cout<<brute<<endl;

    int optimal =minimum_platform_optimal(arr,dep);
    cout<<optimal<<endl;

    int optimal2=minimum_platform_optimal2(arr,dep);
    cout<<optimal2<<endl;
}