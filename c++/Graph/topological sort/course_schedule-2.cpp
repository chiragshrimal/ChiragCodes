#include<bits/stdc++.h>
using namespace std;

// using bfs impliment topological sort 
// time complexity is O()
// space complexity is O()

// we are asuming that garph is DAG

vector<int> topology_order(unordered_map<int,vector<int>>&map,int n){
    vector<int>indegree(n,0);
    vector<int>ans;
    for(auto it : map){
        for(auto v : it.second){
            indegree[v]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int f=q.front();
        ans.push_back(f);
        for(auto v : map[f]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    for(auto it : indegee){
        if(it!=0){
            return {};
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    // number of pair
    int m;
    cin>>m;
    undirected_map<int,vector<int>>map;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        int y;
        cin>>y;
        map[x]=y;
    }
    vector<int> topo=topological_sort(map,n);
    for(auto it : topo){
        cout<<it<<" ";
    }
    cout<<endl;
    return ;

}