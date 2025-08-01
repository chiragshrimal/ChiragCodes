#include <bits/stdc++.h>
using namespace std;


// fanvik tree ka use tab kar rhe hote hai jab rang query par kam krna hota hai 


// time complelxity of creating  segTree is O(n);
// space complexity is O(4*n);

// time complexiity of findMin is O(log(n));
// time complexity of update element is O(log(n));
// in the above  two findMin and update space compleity is O(log(n));

class SumSgTree
{

    vector<int> seg , lazy;

public:
    SumSgTree(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4*n+1);
    }

    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;

        segTree(2 * ind + 1, low, mid, arr);
        segTree(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        return;
    }

    void updateRangeQuery(int ind, int l, int r, int low, int high, int val){

        // update previous updates
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            //  for children propogate 
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }

        // no overlaps 
        if(l>high || r<low){
            return ;
        }


        // complete overlap 
        if(l<=low && r>=high){
            seg[ind]+=(high-low+1)*val;

            if(low!=high){
                lazy[2*ind+1]+=val;
                lazy[2*ind+2]+=val;
            }
            return ;
        }

        // partially overlap 

        int mid = low+(high-low)/2;

        updateRangeQuery(2*ind+1,l,r,low,mid,val);
        updateRangeQuery(2*ind+2,l,r,mid+1,high,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        return ;
    }

    int findSum(int ind ,int l ,int r, int low, int high){
        
        // propogate 
       if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            //  for children propogate 
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
          // no overlaps 
        if(l>high || r<low){
            return 0;
        }

        // complete overlap
        if(l<=low && r>=high){
            return seg[ind];
        }

        // partially overlap
        int mid=low+(high-low)/2;
        int left=findSum(2*ind+1,l,r,low,mid);
        int right=findSum(2*ind+2,l,r,mid+1,high);

        return left+right;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SumSgTree sg1(n);
    sg1.segTree(0, 0, n - 1, arr); 
    cout << endl;
}