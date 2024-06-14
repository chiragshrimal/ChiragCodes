#include<bits/stdc++.h>
using namespace  std;

// brute force apporach 
// time complexity is O(m+n)
// spac ecomplexity is O(1)

int row_with_maximum_ones_brute(vector<vector<int>> & v){
    int n=v.size();
    int m=v[0].size();
    int index=-1;
    int max_row=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            cnt=cnt+v[i][j];
        }
        if(max_row<cnt){
            max_row=cnt;
            index=i;
        }
    }
    return index;
}
int lower_bound(vector<int>& v,int n,int target){
    int low=0;
    int high=n-1;
    int index=INT_MAX;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(target<=v[mid]){
            index=min(index,mid);
            high=mid-1;
        }else{
            low=mid+1;
        }

    }
    return index;
}
// better apporach using binary search 
// time complexity is O()
// space complexity is O(1)

int row_with_maximum_ones_better(vector<vector<int>>& v){
    int n=v.size();
    int m=v[0].size();
    int index=-1;
    int max=-1;
    for(int i=0;i<n;i++){
        int cnt= m-lower_bound(v[i],m,1);
        if(max<cnt){
            max=cnt;
            index=i;
        }

    }
    return index;
    
}
// optimal apporach 
//time complexity is O(n+m)
// space complexity is O(1)

int row_with_maximum_ones_optimal(vector<vector<int>>& v){
    int n=v.size();
    int m=v[0].size();
    int index=-1;
    int i=0;
    int j=m-1;
    while(i<n && j>=0){
        if(v[i][j]==1){
            index=i;
            j--;
        }else{
            i++;
        }
    }
    return index;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    int brute=row_with_maximum_ones_brute(v);
    cout<<brute<<endl;

    int better=row_with_maximum_ones_better(v);
    cout<<better<<endl;

    int optimal=row_with_maximum_ones_optimal(v);
    cout<<optimal<<endl;
}