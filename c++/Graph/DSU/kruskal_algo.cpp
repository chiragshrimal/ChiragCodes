#include<bits/stdc++.h>
using  namespace std; 

// we have implimented assuming that 1-based indexing 
// but it will also be woerk for 0-based indexing 
// time complexity is O(1)
// space complexity is o(n) where n is number of nodes 
class DSU{
    vector<int> rank, parent , size ;
    public : 
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int findLeader(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findLeader(parent[u]);
    }

    void UnionByRank(int u, int v){
        int rootParent_u=findLeader(u);
        int rootparent_v=findLeader(v);
        if(rootParent_u==rootparent_v) return ;

        if(rank[rootParent_u]<rank[rootparent_v]){
            parent[rootParent_u]=rootparent_v;
        }else{
            if(rank[rootParent_u]>rank[rootparent_v]){
                parent[rootparent_v]=rootParent_u;
            }else{
                parent[rootparent_v]=rootParent_u;
                rank[rootParent_u]++;
            }
        }
    }


    void UnionBySize(int u, int v){
        int rootParent_u=findLeader(u);
        int rootparent_v=findLeader(v);
        if(rootParent_u==rootparent_v) return ;

        if(size[rootParent_u]<size[rootparent_v]){
            parent[rootParent_u]=rootparent_v;
            size[rootparent_v]+=size[rootParent_u];
        }else{
            parent[rootparent_v]=rootParent_u;
            size[rootParent_u]+=size[rootparent_v];
        }
    }
};
// for minimum spanning tree 
// kruskal algorithm 
// time complexity is o(mlog(m))
// space complexiity is o()

vector<vector<int>> Kruskal_algorithm(vector<vector<int>>&graph,int n){
    vector<vector<int>> MST;
    int m=graph.size();
    sort(graph.begin(),graph.end(),compare(vector<int>v1, vector<int>v2){
        return v1[2]<=v2[2];
    });
    DSU ds(n);
    int cnt=0;
   for(auto it; graph){
    int u=it[0];
    int v=it[1];
    int w=it[2];
    if(ds.findLeader(u)!=ds.findLeader  (v)){
        cnt++;
        MST.push(it);
        ds.UnionBySize(u,v);
    }
    if(cnt==n-1){
        break;
    }
   }
   return MST;

}

int main(){
   


}