#include<bits/stdc++.h>
using namespace std;

typedef struct job{
    int id;
    int deadline;
    int profit;
}job;

bool compare(job a,job b){
    return a.profit>b.profit;
}
pair<int,int> job_sequencing(vector<job> arr,int n){
    int profit=0;
    int cnt=0;
    sort(arr.begin(),arr.end(),compare);
    int max_deadline=INT_MIN;
    for(int i=0;i<n;i++){
        max_deadline=max(max_deadline,arr[i].deadline);
    }
    int hash[max_deadline+1];//we cant intialize otherthan zero directly;
    for(int i=0;i<max_deadline;i++){
        hash[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline;j>=1;j--){
            if(hash[j]==-1){
                profit=profit + arr[i].profit;
                cnt++;
                hash[j]=arr[i].id;
                break;
            }
        }
    }
    return pair(cnt,profit);
}

int main(){
    int n;
    cin>>n;
    vector<job> arr(n);
    for(int i=0;i<n;i++){
        int id;
        cin>>id;
        int deadline;
        cin>>deadline;
        int profit;
        cin>>profit;
        arr[i].id=id;
        arr[i].deadline=deadline;
        arr[i].profit=profit;
    }
    pair<int,int> brute=job_sequencing(arr,n);
    cout<<brute.first<<endl;
    cout<<brute.second<<endl;
}