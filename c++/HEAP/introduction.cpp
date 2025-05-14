#include<bits/stdc++.h>
using namespace std;

// implementing max heap class
// using array
class Heap{
    public : 
    int arr[100];
    // element in the heap
    int size=0;

    // time complexity is O(log(n)),
    // space somplexity is o(1)
    void insertElement(int x){
        size=size+1;
        int index=size;
        arr[index]=x;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }
    }
    // delete the root element 
    // time complexity is O(log(n))
    // space complexity is O(1)
    void deleteElement(){
        if(size==0){
            printf("heap is already empty");
            return ;
        }
        if(size==1){
            size=size-1;
            return ;
        }
        swap(arr[1],arr[size]);
        size=size-1;
        int index=1;
        while(index<size){
            if(2*index<=size && 2*index+1<=size){
                if(arr[index]>max(arr[2*index],arr[2*index+1])){
                    return ;
                }
                if(arr[2*index]>arr[2*index+1]){
                    swap(arr[index],arr[2*index]);
                    index=2*index;
                    continue;
                }else{
                    swap(arr[index],arr[2*index+1]);
                    index=2*index+1;
                    continue;
                }
            }else{
                if(2*index<=size){
                    swap(arr[index],arr[2*index]);
                    index=2*index;
                    continue;
                }else{
                    return ;
                }
            }
            return ;
        }
        return ;
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<endl;
        }
        return ;
    }


};

// time complexity is o(log(n));
// space complexity is O(1) without recursion 
void Heapify(vector<int>&arr,int index,int n){

    int parent=arr[index];
    int leftChild=2*index>n?INT_MIN:arr[2*index];
    int rightChild=2*index+1>n?INT_MIN:arr[2*index+1];

    if(parent>max(leftChild,rightChild)){
        return ;
    }
   
    if(leftChild>rightChild){
        swap(arr[index],arr[2*index]);
        index=2*index;
        Heapify(arr,index,n);
    }else{
        swap(arr[index],arr[2*index+1]);
        index=2*index+1;
        Heapify(arr,index,n);
    }
    return ;
}

// time complexity is O(n)**********
// space compelxity is O(1)

void build_Heap(vector<int>&arr,int n){
    for(int i=n/2;i>=0;i--){
        Heapify(arr,i,n);
    }
    return ;
}

// Heap Sort 
// time complexity is O(nlog(n));
// space complexity is O(1);

void HeapSort(vector<int>&arr,int size){
    int t=size;
    while(t>1){
        swap(arr[1],arr[t]);
        t--;
        Heapify(arr,1,t);
    }
    return ;
}

int main(){
    
    // Heap h;
    // h.insertElement(2);
    // h.insertElement(3);
    // h.insertElement(4);
    // h.insertElement(5);
    // // h.print();
    // h.deleteElement();
    // // h.print();

    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }
    // build_Heap(arr,n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }

    HeapSort(arr,n);
    for(int i=1;i<n+1;i++){
        cout<<arr[i];
    }
    cout<<endl;


    // max Heap using inbuilt function
    // by default maxHeap hota hai 
    priority_queue<int> maxHeap;

    maxHeap.push(1);
    maxHeap.push(2);
    maxHeap.push(3);
    maxHeap.push(5);
    maxHeap.push(6);

    cout<<maxHeap.top()<<endl;

    maxHeap.pop();
    maxHeap.pop();

    cout<<maxHeap.top()<<endl;

    // minHeap 
    priority_queue<int, vector<int> , greater<int>> minHeap;

    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(6);

    cout<<minHeap.top()<<endl;

    minHeap.pop();
    minHeap.pop();

    cout<<minHeap.top()<<endl;


}