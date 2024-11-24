#include<bits/stdc++.h>
using namespace std;

vector<bool> isArraySpecial(vector<int>& v, vector<vector<int>>& q) {
        int n=v.size();
        int m=q.size();
        vector<bool> store;
        vector<int> ans(n,0);
        int sum=0;
        if(v[0]%2==0){
            ans[0]=0;
        }else{
            ans[0]=1;
        }
        for(int i=1;i<n;i++){
            if(v[i]%2==0 ){
                if(v[i-1]%2==0){
                    ans[i]=sum-1;
                    sum=ans[i];
                }else{
                ans[i]=sum+0;
                sum=ans[i];
                }
                
            }else{
                if((v[i-1]%2)!=0){
                    ans[i]=sum-1;
                    sum=ans[i];
                }else{
                    ans[i]=sum+1;
                sum=ans[i];
                }
            }
        }
        for(int i=0;i<m;i++){
            int f=q[i][1];
            int s=q[i][0];
            int k=f-s+1;
            if(v[f]%2==0 && v[s]%2==0){
                if(s>0){
                if(ans[f]-ans[s-1]==k/2){
                    store.push_back(true);
                }
                }else{
                    if(ans[f]==k/2){
                       store.push_back(true);
                    }else{
                        store.push_back(false);
                    }
                }
            }else{
                if((v[f]%2)==0 && (v[s]%2)!=0){
                    if(s>0){
                        if(ans[f]-ans[s-1]==(k+1)/2){
                           store.push_back(true);
                        }
                    }else{
                        if(ans[f]==(k+1)/2){
                          store.push_back(true);
                        }else{
                            store.push_back(false);
                        }
                    }
                    
                }else{
                    if((v[f]%2)!=0 && (v[s]%2)!=0){
                        if(s>0){
                            if(ans[f]-ans[s-1]==(k+1)/2){
                                 store.push_back(true);
                            }
                        }else{
                            if(ans[f]==(k+1)/2){
                                  store.push_back(true);
                            }else{
                                store.push_back(false);
                            }
                        }
                    }else{
                        if((v[f]%2)!=0 && (v[s]%2)==0){
                             if(s>0){
                        if(ans[f]-ans[s-1]==k/2){
                           store.push_back(true);
                        }
                    }else{
                        if(ans[f]==k/2){
                          store.push_back(true);
                        }else{
                            store.push_back(false);
                        }
                    }
                            
                        }
                    }

                }
            }
        }
        return store;
    }

int main(){
    
}