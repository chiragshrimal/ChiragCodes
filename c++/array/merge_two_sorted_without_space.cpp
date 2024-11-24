#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
//time complexity is O(n+m);
// space complexity is O(n+m);
void merge_brute(vector<int> v1,vector<int> v2){
    int n=v1.size();
    int m=v2.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(v1[i]<v2[j]){
            ans.push_back(v1[i]);
            i++;
        }else{
            ans.push_back(v2[j]);
            j++;
        }
    }
    while(i<n){
        ans.push_back(v1[i]);
        i++;
    }
    while(j<m){
        ans.push_back(v2[j]);
        j++;
    }
    for(int k=0;k<n;k++){
        v1[k]=ans[k];
        cout<<v1[k]<<" ";
    }
    for(int k=0;k<m;k++){
        v2[k]=ans[n+k];
        cout<<v2[k]<<" ";
    }

    return ;
}

// optimal qpporach 
// time complexity is O(min(m,n)+ mlog(m)+nlog(n))
// space complexity is O(1)
void merge_optimal1(vector<int>& v1,vector<int>& v2){
    int n=v1.size();
    int m=v2.size();
    int i=n-1;
    int j=0;
    while(i>=0 && j<m){
        if(v1[i]>v2[j]){
            swap(v1[i],v2[j]);
            i--;
            j++;
        }else{
            break;
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    return ;
}
// 2 optimal apporach good concept 
// time complexity is O()
// space complexity is O()

void merge_optimal2(vector<int>& v1,vector<int>& v2){
    int n=v1.size();
    int m=v2.size();
    int gap=(n+m)/2;
    int left=0;
    int right=gap;
    while(gap>=1){
        while(right<m+n){
            if(left<n && right<n){
                if(v1[left]>v1[right]){
                    swap(v1[left],v2[right]);
                }
            }else{
                if(left<n && right>=n){
                    if(v1[left]>v2[right-n]){
                        swap(v1[left],v2[right-n]);
                    }
                }else{
                    if(left>=n && right>=n){
                        if(v2[left-n]>v2[right-n]){
                            swap(v1[left-n],v2[right-n]);
                        }
                    }
                }
            }
            left++;
            right++;
        }
        gap=gap/2;
        left=0;
        right=gap;
    }
    
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }
     for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    // merge_brute(v1,v2);
    // merge_optimal1(v1,v2);
    merge_optimal2(v1,v2);
    for(auto it : v1){
        cout<<it<<" ";
    }
    for(auto it : v2){
        cout<<it<<" ";
    }
}