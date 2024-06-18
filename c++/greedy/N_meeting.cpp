#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
//  time complexity is O(n*log(n))
// space compplexity is o(2*n)
typedef struct meeting {
    int start;
    int end;
}meeting ;

bool compare(meeting a,meeting b){
    return a.end<b.end;
}

int N_meeting(vector<int>& start,vector<int>& end){
    int n=start.size();
    vector<meeting> arr(n);
    for(int i=0;i<n;i++){
        arr[i].start=start[i];
        arr[i].end=end[i];
    }
    sort(arr.begin(),arr.end(),compare);
    if(n==1){
        return 1;
    }
    int i=0;
    int j=1;
    int cnt=1;
    while(j<n){
        if(arr[i].end<arr[j].start){
            cnt++;
            i=j;
            j++;
        }else{
            j++;
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> start;
    vector<int> end;
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    start.push_back(x);
    }
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    end.push_back(x);
    }
    int optimal =N_meeting(start,end);
    cout<<optimal<<endl;

}