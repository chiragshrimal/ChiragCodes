#include<bits/stdc++.h>
using namespace std;

typedef struct Item{
    int value;
    int weight;
}Item;

bool compare(Item a, Item b){
    return ((double)(a.value)/(double)(a.weight))>((double)(b.value)/(double)(b.weight));
    
}
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, vector<Item>arr, int n) {
             double sum=0;
             sort(arr.begin(),arr.end(),compare);
             int i=0;
             while(i<n && w>0){
                 if(w>=arr[i].weight){
                     w=w-arr[i].weight;
                     sum=sum+arr[i].value;
                 }else{
                     double temp=((double)(arr[i].value)/(double)(arr[i].weight))*w;
                     sum=sum+(temp);
                     w=0;
                 }
                 i++;
             }
             return sum;
    }
int main(){
    int n;
    cin>>n;
    int w;
    cin>>w;
    vector<Item> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int y;
        cin>>y;
        arr.push_back({x,y});
    }
    double profit=fractionalKnapsack(w,arr,n);
    cout<<profit<<endl;
}    