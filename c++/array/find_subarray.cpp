#include <bits/stdc++.h>
using namespace std;
// subarray means contigeous element
// time complexity is o(n^3)
// space complexity is O(1)
// brute force appporach
int find_largest_subarray(int n, int arr[], int k)
{
    // int l=1;
    // int max=0;
    // while(l<=n){
    //     for(int i=0;i<n;i++){
    //         int sum=0;
    //         for(int j=i;j<i+l && j<n && i+l<n;j++){// good logic hai // ye lengthwise hai
    //             sum+=arr[j];
    //         }
    //         if(sum==k){
    //             if(max<l){
    //                 max=l;
    //             }
    //         }
    //     }
    //     l++;
    // }
    // return max;

    // other way to find subarray
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            { // agar ise m o(1) find kar du toh kam ho jayega
                sum += arr[k];
            }
            if (sum == k)
            {
                if (max < j - i + 1)
                {
                    max = j - i + 1;
                }
            }
        }
    }
    return max;
}
// better  apporach
// time complexity is o(n^2)
// space complexity is o(n)
int find_largest_Better(int n, int arr[], int k)
{
    // int max = 0;
    // int sum[n];
    // sum[0] = arr[0];
    // for (int i = 1; i < n; i++)
    // {
    //     sum[i] = sum[i - 1] + arr[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         int m;
    //         if (i != 0)
    //         {
    //             m = sum[j] - sum[i - 1];
    //         }
    //         else
    //         {
    //             m = sum[j];
    //         }
    //         if (m == k)
    //         {
    //             if (max < j - i + 1)
    //             {
    //                 max = j - i + 1;
    //             }
    //         }
    //     }
    // }
    // return max;
    // time complexity is O(n^2)
    // space complexity is O(1)
    // it is better from above 
    int max=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                if(max<j-i+1){
                    max=j-i+1;
                }
            }
        }
    }
    return max;


}
// optimal technique (good concept) only for non_negative elements 
//time complexity is o(n)
// space somplexity is O(1)
int find_largest_optimal(int n, int arr[],int k){
    int i=0;
    int j=0;
    int max=0;
    int sum=0;
    while(i<n||j<n){
        if(sum==k){
            if(max<j-i){
                max=j-i;
            }
            sum=sum+arr[j];
        }
        while(sum<k){
            sum+=arr[j];
            j++;
        }
        while(sum>k){
            sum=sum-arr[i];
            i++;
        }
    }
    return max;
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int m = find_largest_subarray(n, arr, k);
    cout << m << endl;
    int g = find_largest_Better(n, arr, k);
    cout << g << endl;
    int l=find_largest_optimal(n,arr,k);
    cout<<l<<endl;
}