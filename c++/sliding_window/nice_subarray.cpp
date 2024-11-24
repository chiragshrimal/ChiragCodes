#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^2);
// space complexity is O(1);
int count_nice_subarray_brute(vector<int>& v,int k){
    int n=v.size();
    int count=0;
    for(int i=0;i<n;i++){
        int check=0;
        for(int j=i;j<n;j++){
            if(v[j]%2!=0){
                check++;
            }
            if(check==k){
                count++;
            }
            if(check>k){
                break;
            }
        }
    }
    return count;
}

// optimal apporach 
// time compelxity is O(2*n);
// space complexity is O(1)

int count_nice_subarray_optimal(vector<int>& v,int k){
    int n=v.size();
    int count=0;
    int j=0;
    int i=0;
    int check=0;
    while(j<n){
        if((v[j]%2)!=0){
            check++;
        }
        while(check>k){
            if((v[i]%2)!=0){
                check--;
                i++;
            }else{
                i++;
            }
        }
        if(check<=k){
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
    int brute=count_nice_subarray_brute(v,k);
    cout<<brute<<endl;

    int count1=count_nice_subarray_optimal(v,k);
    int count2=count_nice_subarray_optimal(v,k-1);
    cout<<count1<<endl;
    cout<<count2<<endl;
    int optimal=count2-count1;
    cout<<optimal<<endl;
}