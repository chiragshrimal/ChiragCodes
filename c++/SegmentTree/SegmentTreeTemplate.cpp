#include <bits/stdc++.h>
using namespace std;


// time complelxity of creating  segTree is O(n);
// space complexity is O(4*n);

// time complexiity of findMin is O(log(n));
// time complexity of update element is O(log(n));
// in the above  two findMin and update space compleity is O(log(n));


// formation of segmrnt tree based on min 
// hum sum ka bhi bna skte hai 
// hum max ka bhi bna skte hai 


// remember one thing always jis trh se question pucha jayega wese hi 
// segment Tree ka impliment krna hoga 
class MinSgTree
{

    vector<int> seg , lazy;

public:
    MinSgTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    // build degment tree using min
    void segTree(int ind, int low, int high, vector<int> &arr)
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

    int findMin(int ind, int l, int r, int low, int high)
    {

        // no overlap
        if (r < low || l > high)
        {
            return INT_MAX;
        }
        // complete overlap
        if (l <= low && high <= r)
        {
            return seg[ind];
        }
        // partially overlap

        int mid = low + (high - low) / 2;

        int left = findMin(2 * ind + 1, l, r, low, mid);

        int right = findMin(2 * ind + 2, l, r, mid + 1, high);

        return min(left, right);
    }

    // point update 
    int updateVal(int i, int low, int high, int ind, int val)
    {

        // here ind is give in the query
        // and i is the segment tree index
        if (low == high && ind == low)
        {
            return seg[i] = val;
        }

        int mid = low + (high - low) / 2;

        int ans = INT_MAX;

        if (mid < ind)
        {
            ans = updateVal(2 * i + 2, mid + 1, high, ind, val);
        }
        else
        {
            ans = updateVal(2 * i + 1, low, mid, ind, val);
        }

        return seg[i] = min(seg[i], ans);
    }

    // range m update krna hai toh 
    void updateRangeQuery(int ind, int l, int r, int low , int high ,int val){
        
        // propogate downword
        if(lazy[ind]!=0){
            seg[ind]+=lazy[ind];
            // and propogateto the child 
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind]
            }
            lazy[ind]=0;
        }

        // no overlap 
        if(r<low || l>high){
            return ;
        }

        // complate overlap 
        if(l<=low && r>=high){
            seg[ind]+=val;

            if(low!=high){
                lazy[2*ind+1]+=val;
                lazy[2*ind+2]+=val;
            }
            return ;
        }

        // partially overlap 
        int mid=low+(high-low)/2;

        updateRangeQuery(2*ind+1,l,r,low,mid,val);
        updateRangeQuery(2*ind+2,l,r,mid+1,high,val);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        return ;
    }
    // ydi range m update krna hai toh is function ka use kro 
    int findMinRangeQuery(int ind, int l , int r, int low, int high){

        // propogate 
        if(lazy[ind]!=0){
            seg[ind]+=lazy[ind];
            // and propogateto the child 
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind]
            }
            lazy[ind]=0;
        }
       // no overlap
        if (r < low || l > high)
        {
            return INT_MAX;
        }
        // complete overlap
        if (l <= low && high <= r)
        {
            return seg[ind];
        }
        // partially overlap

        int mid = low + (high - low) / 2;

        int left = findMinRangeQuery(2 * ind + 1, l, r, low, mid);

        int right = findMinRangeQuery(2 * ind + 2, l, r, mid + 1, high);

        return min(left, right);
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
    MinSgTree sg1(n);
    sg1.segTree(0, 0, n - 1, arr); 
    cout << endl;
    int mini = sg1.findMin(0, 2, 4, 0, n - 1);
    cout << mini << endl;
}