#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^2)
// space complexity si O(1)
int count_sunbarray_brute(vector<int>& v,int k){
    int n=v.size();
    int count=0;
    for(int i=0;i<n;i++){
        set<int> s;
        for(int j=i;j<n;j++){
            s.insert(v[j]);
            if(s.size()==k){
                count++;
            }
            if(s.size()>k){
                break;
            }
        }
    }
    return count;
}

// optimal apporach 
//time complexity is O(2*n)
// space complexity is O(1)

int count_subarray_optimal(vector<int>& v,int k){
    int n=v.size();
    int count=0;
    unordered_map<int,int> m;
    int i=0;
    int j=0;
    while(j<n){
        m[v[j]]++;
        while(m.size()>k){
            m[v[i]]--;
            if(m[v[i]]==0){
                m.erase(v[i]);
            }
            i++;
        }
        if(m.size()<=k){
            count=count+j-i+1;
        }
        j++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int brute=count_sunbarray_brute(v,k);
    cout<<brute<<endl;

    int count1=count_subarray_optimal(v,k);
    int count2=count_subarray_optimal(v,k-1);
    int optimal=count1-count2;
    cout<<optimal<<endl;
}