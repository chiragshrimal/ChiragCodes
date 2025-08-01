#include<bits/stdc++.h>
using namespace std; 

class SGTree{

    vector<int> seg, lazy;

    public: 

    SGTree(int n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
    }

    // build the segment tree
    void build(int ind, int low, int high, vector<int>&arr){
        
        if(low!=high){
            seg[ind]=arr[low];
            return;
        }

        int mid=low+(high-low)/2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        return;
    }

    // lazy[i]==1 then we have to flip 
    // othewise  dont flip 
    // update previous update 
    // this function only updates and do nothing 
    void update(int ind, int l,int r, int low, int high){

        if(lazy[ind]!=0){
            // change yourself 
            // seg[ind] represent the number of heads 
            seg[ind]=(high-low+1)-seg[ind];
            if(low!=high){
                lazy[2*ind+1]=1-lazy[2*ind+1];
                lazy[2*ind+2]=1-lazy[2*ind+2];
            }
            // complete update 
            lazy[ind]=0;
        }

        // no overlap 
        if(r<low || l>high){
            return ;
        }

        // complete overlap
        if(l<=low && r>=high){
                // do flip always
                seg[ind]=(high-low+1)-seg[ind];
                
                if(low!=high){
                    lazy[2*ind+1]=1-lazy[2*ind+1];
                    lazy[2*ind+2]=1-lazy[2*ind+2];
                }
            return ;
        }

        // partially overlap
        int mid = low+(high-low)/2;

        update(2*ind+1,l,r,low,mid,);
        update(2*ind+2,l,h,mid+1,high);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        return ;
    }

    int findSum(int ind , int l, int r, int low, int high){

        // propogate the pre updates 
         if(lazy[ind]!=0){
            // change yourself 
            // seg[ind] represent the number of heads 
            seg[ind]=(high-low+1)-seg[ind];
            if(low!=high){
                lazy[2*ind+1]=1-lazy[2*ind+1];
                lazy[2*ind+2]=1-lazy[2*ind+2];
            }
            // complete update 
            lazy[ind]=0;
        }
        // no overlap 
        if(r<low || l>high){
            return 0;
        }

        // complete overlap 
        if(l<=low && r>=high){
            return seg[ind];
        }

        // partiallly overlap 
        int mid=low+(high-low)/2;

        int left=findSum(2*ind+1,l,r,low,mid);
        int right=findSum(2*ind+2,l,r,mid+1,high);

        return left+right;
    }

};

int main(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SGTree sg;
    sg.build(0,0,n-1,arr);

    while(q--){
        int l,r;
        cin>>l>>r;
        int mini=sg.findSum(0,l,r,0,n-1);
        cout<<mini<<" ";
        sg.update(0,l,r,0,n-1);
    }


}