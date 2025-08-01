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

int main(){
    DSU ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    
    if(ds.findLeader(3)==ds.findLeader(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"NotSame"<<endl;
    }

    ds.UnionBySize(3,7);
     
    if(ds.findLeader(3)==ds.findLeader(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"NotSame"<<endl;
    }


}