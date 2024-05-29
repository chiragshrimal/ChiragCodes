#include<bits/stdc++.h>
using namespace std;
// sliding window/ two pointer concept
// type of sliding window
//1.constant window
//2. not constant like find longest subarray with some condition are there 
// on the second type let find the longest subarray with sum<=k
//1. brute foorce apporach 
// 2. better apporach 
// 3. optimal apporach

// 3. find the number of subarray with some condition 
// like find number of subarray with sum =k;
// in this case we dont no wether to expand or shrink 
// break this problem into two problem 
//1. is find number of subarray where sum <=k ===== x
//2. is find number of subarray where sum<=k-1   ===== y
// ans is x-y;


// 4. find the shortest/ window <condition> 








// brute force apporach 
// time complexity is O(n^2)
// space complexity is O(1)
int longest_subarray_brute(vector<int>& v,int k){
    int n=v.size();
    int maxlength=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=v[j];
            if(sum<=k){
                if(maxlength<j-i+1){
                    maxlength=j-i+1;
                }
            }else{
                break;
            }
        }
    }
    return maxlength;
}

// better apporach 
// time complexity is O(2*n)
//space complexity is O(1)
int longest_subarray_better(vector<int>& v,int k){
    int n=v.size();
    int l=0;
    int r=0;
    int sum=0;
    int max=0;
    while(r<n){
        sum=sum+v[r];
        while(sum>k){
            sum=sum-v[l];
            l++;
        }
        if(sum<=k){
            if(max<r-l+1){  
                max=r-l+1;
            }
        }
        r=r+1;
    }
    return max;
}
// optimal apporach (why we have to decrese the maxlength)(good concept)
// time complexity is O(n);
// space complexity is O(1);
int longest_subarray_optimal(vector<int>& v,int k){
    int n=v.size();
    int l=0;
    int r=0;
    int max=0;
    int sum=0;
    while(r<n){
        sum=sum+v[r];
        if(sum>k){
            sum=sum-v[l];
            l++;
        }
        if(sum<=k){
            if(max<r-l+1){
                max=r-l+1;
            }
        }
        r=r+1;
    }
    return max;

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
    int brute=longest_subarray_brute(v,k);
    cout<<brute<<endl;

    int better=longest_subarray_better(v,k);
    cout<<better<<endl;

    int optimal=longest_subarray_optimal(v,k);
    cout<<optimal<<endl;

}