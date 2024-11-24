#include<bits/stdc++.h>
using namespace std;
// yha pe majority means frequency is greater than n/3;
//q 
// find all majority element of given array;

// brute force apporach 
// time complexity is O(n^2)
// space complexity is O(1)

vector<int> majority_brute(vector<int> v){
    vector<int> ans;
    int n=v.size();
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j<n;j++){
            if(v[i]==v[j]){
                count++;
            }
        }
        if(count>n/3){
            ans.push_back(v[i]);
        }
        if(ans.size()==2){
            return ans;
        }
    }
    return ans;
}
//better apporach 
// time complexity is O(n)
// space complexity is O(n);

vector<int> majority_better(vector<int> v){
    vector<int> ans;
    int n=v.size();
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        auto it =m.find(v[i]);
        if(it!=m.end()){
            m[v[i]]++;
        }else{
              m.insert({v[i],1});
        }
    }
    for(auto it : m){
        if(it.second>n/3){
            ans.push_back(it.first);
        }
        if(ans.size()==2){
            return ans;
        }
    }
    return ans;
}
// optimal apporach 
// time complexity is o( 3*n)
// space complexity is O(1);
vector<int> majority_optimal(vector<int> v){
    vector<int> ans;
    int n=v.size();
    int cnt1=0;
    int ele1=0;
    int cnt2=0;
    int ele2=0;
    for(int i=0;i<n;i++){
        if(cnt1==0 && v[i]!=ele2){
            cnt1++;
            ele1=v[i];
        }else{
            if(cnt2==0 && v[i]!=ele1){
                cnt2++;
                ele2=v[i];
            }else{
                if(ele1==v[i]){
                    cnt1++;
                }else{
                    if(ele2==v[i]){
                        cnt2++;
                    }else{
                        cnt1--;
                        cnt2--;
                    }
                }
            }
        }
    }
    if(cnt1>0){
        int count=0;
        for(int i=0;i<n;i++){
            if(ele1==v[i]){
                count++;
            }
        }
        if(count>n/3){
            ans.push_back(ele1);
        }
    }
     if(cnt2>0){
        int count=0;
        for(int i=0;i<n;i++){
            if(ele2==v[i]){
                count++;
            }
        }
        if(count>n/3){
            ans.push_back(ele2);
        }
    }
    return ans;
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
    vector<int> brute=majority_brute(v);
    for(auto it : brute){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> better=majority_better(v);
    for(auto it : better){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> optimal=majority_optimal(v);
    for(auto it : optimal){
        cout<<it<<" ";
    }
    cout<<endl;
}