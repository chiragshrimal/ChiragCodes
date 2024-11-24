#include<bits/stdc++.h>
using namespace std;

// brute force apporach using merging 
// time complexity is O(m+n)
// space complexity is O(m+n);
int Kth_element_brute(vector<int> &v1, vector<int> &v2,int k)
{
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> v3;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            v3.push_back(v1[i]);
            i++;
        }
        else
        {
            v3.push_back(v2[j]);
            j++;
        }
    }
    while (i < n1)
    {
        v3.push_back(v1[i]);
        i++;
    }
    while (j < n2)
    {
        v3.push_back(v2[j]);
        j++;
    }
    return v3[k-1];
}

// better apporach using cnt variable
// time complexity is O(m+n)
// space complexity is O(1)
int Kth_element_better(vector<int> &v1, vector<int> &v2,int k)
{
    int n1 = v1.size();
    int n2 = v2.size();
    int i = 0;
    int j = 0;
    int n = n1 + n2;
    int ind1 =k-1;
    int cnt = -1;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            cnt++;
            if (cnt == ind1)
            {
                return v1[i];
            }
            i++;
        }
        else
        {
            cnt++;
            if (cnt == ind1)
            {
               return v2[j];
            }
            j++;
        }
    }
    while (i < n1)
    {
        cnt++;
        if (cnt == ind1)
        {
          return v1[i];
        }
        i++;
    }
    while (j < n2)
    {
        cnt++;
        if (cnt == ind1)
        {
            return v2[j];
        }
        j++;
    }
    return -1;
}
// optimal apporach  binary search apply on less element containing  vector
// time complexity is O(log(min(n1,n2)))
// space complecity is o(1)

double Kth_element_optimal(vector<int> &v1, vector<int> &v2,int k)
{
    int n1 = v1.size();
    int n2 = v2.size();
    if (n1 > n2)
    {
        return Kth_element_optimal(v2, v1,k);// important point hai return krna hota hain
    }
    int n = n1 + n2;
    int low = max(k-n2,0);// important case hai 
    int high = min(n1,k);// smjho bro 
    while (low <= high)
    {
        int mid1 = low + ((high - low) >> 1);
        int mid2 = k- mid1;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        if (mid1 < n1)
        {
            r1 = v1[mid1];
        }
        if (mid2 < n2)
        {
            r2 = v2[mid2];
        }

        if (mid1 - 1 >= 0)
        {
            l1 = v1[mid1 - 1];
        }

        if (mid2 - 1 >= 0)
        {
            l2 = v2[mid2 - 1];
        }
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1,l2);
        }

        if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}


int main(){
    int n1,n2;
    cin>>n1>>n2;
    int k;
    cin>>k;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    int brute=Kth_element_brute(v1,v2,k);
    cout<<brute<<endl;

    int better=Kth_element_better(v1,v2,k);
    cout<<better<<endl;

    int optimal=Kth_element_optimal(v1,v2,k);
    cout<<optimal<<endl;
}