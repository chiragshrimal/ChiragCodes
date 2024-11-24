#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(3*n)
// spacve complexity is O(2*n)

int candy_brute(vector<int>& ratings){
        int n=ratings.size();
        int left[n];
        int right[n];
        left[0]=1;
        right[n-1]=1;
        // solve left
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
            left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
        //solve right
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
            right[i]=right[i+1]+1;
            }else{
                right[i]=1;
            }
        }
        //calculate sum
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+max(left[i],right[i]);
        }
        return sum;
}

// better apporach
// time complexity is O(2*n);
//space complexity is O(n)

int candy_better(vector<int>& ratings){
        int n=ratings.size();
        int left[n];
        left[0]=1;
        // solve left
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
            left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
        int sum=max(left[n-1],1);
        int pre=1;
        int cur=0;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                cur=pre+1;
                pre=cur;
            }else{
                pre=cur=1;
            }
            sum=sum+max(left[i],cur);
        }
        return sum;
}
// optimal apporach  good concept hai 
// time complexity is O(n)
// space ecomplexity is O(1)

int candy_optimal(vector<int>& rating){
    int n=rating.size();
    int sum=1;
    int i=1;
    while(i<n){
        // constant sequence 
        while( i<n && (rating[i]==rating[i-1])){
            sum=sum+1;
            i++;
        }
        int peak=1;
        // increasing sequence 
        while(i<n && rating[i]>rating[i-1]){
            peak=peak+1; // phle ka peak chahiye isliye phle likha hai
            sum=sum+peak;
            i++;
        }
        // decreasing sequence 
        int down=1;
        while(i<n && (rating[i]<rating[i-1])){
            sum=sum+down;
            down++;// because aage ka down chahiye isliye bad m audate kiya hai
            i++;
        }
        // for top of element 
        if(down>peak){
            sum=sum+down-peak;
        }
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> rating ;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        rating.push_back(x);
    }
    int brute=candy_brute(rating);
    cout<<brute<<endl;

    int better=candy_better(rating);
    cout<<better<<endl;

    int optimal=candy_optimal(rating);
    cout<<optimal<<endl;
}