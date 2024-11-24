#include <bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(n^2)
// space complexity is O(1)
int count_subarray_brute(vector<int>& v,int k){
    int n=v.size();
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+v[j];
            if(sum==k){
                count++;
            }else{
                if(sum>k){
                    break;
                }
            }
        }
    }
    return count;
}
// better apporach 
// time complexity is O(n)
// space complexity is O(n)
int count_subarray_better(vector<int>& v,int k){
    int n=v.size();
    int count=0;
    unordered_map<int,int> m;
    m[0]=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+v[i];
        if(m.find(sum-k)!=m.end()){
            count=count+m[sum-k];
        }
        m[sum]++;

    }
    return count;
}

// optimal apporach 
// time complexity is O(2*n)
// space complexity is O(1)
long long int count_subarray(vector<int> &v, int k)
{
    if(k<0){
        return 0;
    }
    int n = v.size();
    long long int count = 0;
    int j = 0;
    int i = 0;
    long long int sum = 0;
    while (j < n)
    {
        sum = sum + v[j];
        while(sum>k){
            sum=sum-v[i];
            i++;
        }
        if(sum<=k){
            count=count+j-i+1;
        }
        j++;
    }
    return count;
}
int numSubarraysWithSum(vector<int> &v, int k)
{
    long long int count1 = count_subarray(v, k);
    long long int count2 = count_subarray(v, k - 1);
    long long int count = count1 - count2;
    return count;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int brute=count_subarray_brute(v,k);
    cout<<brute<<endl;
    int better=count_subarray_better(v,k);
    cout<<better<<endl;
    int optimal = numSubarraysWithSum(v, k);
    cout << optimal << endl;
}