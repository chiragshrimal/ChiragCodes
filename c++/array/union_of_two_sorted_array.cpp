#include <bits/stdc++.h>
using namespace std;

// time complexity is o(m+n)
int *union_of_two_sorted_array(int n1, int n2, int arr1[], int arr2[])
{
    int m = n1 + n2;
    int *arr3 = (int *)malloc(m * sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    return arr3;
}
int * intersaction(int n1,int n2 ,int arr1[],int arr2[]){
    int m=min(n1,n2);
    int * arr=(int *)malloc(m*sizeof(int));
    int i=0;
    int j=0;
    int k=0;
    while(i<n1 && j<n2){
        if(arr1[i]==arr2[j]){
            arr[k]=arr1[i];
            i++;
            j++;
            k++;
        }else{
            if(arr1[i]<arr2[j]){
                i++;
            }else{
                j++;
            }
        }
    }
    return arr;
}

int main()
{
    int n1;
    cin >> n1;
    int n2;
    cin >> n2;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    int *arr = union_of_two_sorted_array(n1, n2, arr1, arr2);
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << arr[i] << endl;
    }
    int * arr3=intersaction(n1,n2,arr1,arr2);
    for(int i=0;i<min(n1,n2);i++){
        cout<<arr3[i]<<endl;
    }
}