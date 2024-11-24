#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) 
    {
        int N=3*1e4+10;
        int a[N];
         for(int i=0;i<nums.size();i++){
            a[i]=0;
        }
        int min =*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]-min;
        }
        for(int i=0;i<nums.size();i++){
            a[i]++;
        }
        for(int i=0;i<N;i++){
            if(a[i]==1){
                return i;
            }
        }
    }
    int main (){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m=singleNumber(a);
        

    }
