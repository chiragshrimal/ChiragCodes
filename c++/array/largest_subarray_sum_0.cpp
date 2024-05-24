#include<bits/stdc++.h>
using namespace std;
int maxLen(vector<int>&v, int n)
    {   
        vector<int> presum;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            presum.push_back(sum);
        }
        unordered_map<int,int> m;
        for(int i=n-1;i>=0;i--){
            m.insert({presum[i],i});
        }
        int max=0;
        for(int i=0;i<n;i++){
            if(presum[i]!=0){
            auto it =m.find(presum[i]);
            if(it!=m.end()){
                int count=(it->second)-i;
                if(max<count){
                    max=count;
                }
            }
            }else{
                if(max<=i){// if presum already is zero 
                    max=i+1;
                }
            }
         
            
    }
    return max;
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
    int largest=maxLen(v,  n);
    cout<<largest<<endl;
}        