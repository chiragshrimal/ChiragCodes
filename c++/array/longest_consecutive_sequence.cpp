#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^3)
// space complexity is O(1);
int longest_consecutive_brute(vector<int> &v){
    int n=v.size();
    int maxcount=INT_MIN;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            int temp=v[i]+j;
            for(int k=0;k<n;k++){
                if(v[k]==temp){
                    count++;
                    break;
                }
            }
            if(maxcount<count){
                maxcount=count;
            }
        }
    }
    return maxcount;
}
// better  apporach (sort krke )
// time complexity is O(nlog(n))
// space complexity is O(1);

int longest_consecutive_better(vector<int> &v){
    sort(v.begin(),v.end());
    // int start_index=-1;
    // int ans_start_index;
    // int ans_last_index=-1;
    int max=INT_MIN;
    int longest=1;
    int n=v.size();
    for(int i=0;i<n-1;i++){
        if(v[i]+1==v[i+1]){
            longest++;
            if(max<longest){
                // ans_last_index=i+1;
                // ans_start_index=start_index;
                max=longest;
            }
        }else{
            if(v[i]!=v[i+1])// 1112234 ko handel krne ke liye  ,
            longest=1;
            // start_index=i+1;
        }
    }
      return max;
}
// optimal apporach 
// time complexity is O(n)
// space complexity is O(1)
// set inserrion tiem complexity is O(1)
int longest_consecutive_optimal(vector<int> v){
    unordered_set<int> s;// unique element and implimented using hash table  and find is O(1);
    int n=v.size();
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        s.insert(v[i]);
    }
    for(auto it : s){
        if(s.find(it-1)==s.end()){
            int count=0;
            while(s.find(it)!=s.end()){
                count++;
                it++;
            }
            if(max<count){
                max=count;
            }
        }
    }
    return max;
}



int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int brute =longest_consecutive_brute(v);
    cout<<brute<<endl;
    int better=longest_consecutive_better(v);
    cout<<better<<endl;
    int optimal=longest_consecutive_optimal(v);
    cout<<optimal<<endl;
}