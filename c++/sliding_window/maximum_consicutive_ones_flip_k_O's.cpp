#include<bits/stdc++.h>
using namespace std;

// brute force apporach like find all the subarray whivh have at most k zeros
// time complexity is O(n^3)
// space complexity is O(1)
int maximum_consecutive_brute(vector<int>& v,int k){
    int n=v.size();
    int maxlength=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int zeros=0;
            for(int k=i;k<=j;k++){
                if(v[k]==0){
                    zeros++;
                }
            }
            if(v[j]==0){
                zeros++;
            }
            if(zeros<=k){
                maxlength=max(maxlength,j-i+1);
            }
            if(zeros>k){
                break;
            }
        }
    }
    return maxlength;
}


// better apporch 
// time complexity is O(N^2)
// space complexity is O(1)

int maximum_consecutive_better(vector<int>& v,int k){
    int n=v.size();
    int maxlength=0;
    for(int i=0;i<n;i++){
        int zeros=0;
        for(int j=i;j<n;j++){
            if(v[j]==0){
                zeros++;
            }
            if(zeros<=k){
                maxlength=max(maxlength,j-i+1);
            }
            if(zeros>k){
                break;
            }
        }
    }
    return maxlength;
}



// optimal apporach using sliding window two pointer concept
// time complexity is O(2*n)
// space copmplexity is O(1)
int maximum_consecutive_optimal(vector<int>& v,int k){
    int n=v.size();
    int maxlength=0;
    int j=0;
    int i=0;
    int zero=0;
    while(j<n){
        if(v[j]==0){
            zero++;
        }
        while(zero>k){
            if(v[i]==0){
                zero--;
            }
            i++;
        }
        if(zero<=k){
            maxlength=max(maxlength,j-i+1);
        }
        j++;
    }
    return maxlength;

}
// optimal apporach using sliding window two pointer concept with some time fixed the window size
// time complexity is O(n)
// space copmplexity is O(1)
int maximum_consecutive_optimal2(vector<int>& v,int k){
    int n=v.size();
    int maxlength=0;
    int j=0;
    int i=0;
    int zero=0;
    while(j<n){
        if(v[j]==0){
            zero++;
        }
        if(zero>k){ // we can use "if" in place of while
            if(v[i]==0){
                zero--;
            }
            i++;
        }
        if(zero<=k){
            maxlength=max(maxlength,j-i+1);
        }
        j++;
    }
    return maxlength;

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
    int brute=maximum_consecutive_brute(v,k);
    cout<<brute<<endl;
    int better=maximum_consecutive_better(v,k);
    cout<<better<<endl;
    int optimal=maximum_consecutive_optimal(v,k);
    cout<<optimal<<endl;




}