#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n^2)
// space complexity is O(1);

int minimum_subarray_brute(vector<int>& v,int k){
    int n=v.size();
    int minimum=INT_MAX;
    for(int i=0;i<n;i++){
        int cur_and=~(0);
        for(int j=i;j<n;j++){
            cur_and=cur_and &v[j];
            minimum=min(minimum,abs(k-cur_and));
        }
    }
    return minimum;
}
// optimal apporach 
// time complexity is O(2*n)
// space complexity is O(32)
void add(vector<int>& hash,int num){
    for(int i=0;i<32;i++){
        if(((num>>i)&1)==0){
            hash[i]++;
        }
    }
}

void sub(vector<int>& hash,int num){
    for(int i=0;i<32;i++){
        if(((num>>i)&1)==0){
            hash[i]--;
        }
    }
}
int cal(vector<int>& hash){
    int num=0;
    for(int i=0;i<32;i++){
        if(hash[i]==0){
            num=num|(1<<i);
        }
    }
    return num;
}

int minimum_subarray_optimal(vector<int>& v,int k){
    int n=v.size();
    int minimum=INT_MAX;
    int high=*max_element(v.begin(),v.end());
    vector<int> hash(32,0);
    int cur=~(0);
    int i=0;
    int j=0;
    if(k>=high){
        return k-high;
    }
    while(j<n){
            cur=cur & v[j];
            add(hash,v[j]);
            minimum=min(minimum,abs(k-cur));
        while(cur<k & i<j){
            sub(hash,v[i]);
            cur=cal(hash);
            minimum=min(minimum,abs(k-cur));
            i++;
        }
        if(cur==k){
            return 0;
        }
        j++;
    }
    return minimum;
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
    int brute=minimum_subarray_brute(v,k);
    cout<<brute<<endl;

    int optimal=minimum_subarray_optimal(v,k);
    cout<<optimal<<endl;
}