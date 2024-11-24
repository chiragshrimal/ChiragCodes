#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity O(m*n)
// space complekity is O(n*m)

//Q1 
// given row and coloum find element
// 1 st apporach is using recurssion 
int f(int row,int coloum){
    if(row==1|| coloum==1){
        return 1;
    }
    if(row==coloum){
        return 1;
    }
    int m=f(row-1,coloum);
    int k=f(row-1,coloum-1);
    return m+k;

}
// using n-1Cc-1 
// time complexity is O(coloum);
// space complexity is O(1)
int n_c_r(int row,int coloum){
    row--;
    coloum--;
    double l=1;
    for(int k=0;k<coloum;k++){
        l=(l*(row-k))/(coloum-k);
    }
    return l;
}
// q2
// brute  force apporach 
// print a perticular row
// time complexity is O(row*coloum)
// space complexity is o(1)
vector<int> print_row_brute(int row){
    vector<int> v;
    for(int i=0;i<row;i++){
        v.push_back(n_c_r(row,i+1));
    }
    return v;
}
// optimal apporach 
// time complexity is o(row)
// space complexity is O(1)
vector<int> print_row_optimal(int row){
    vector<int> v;
    int k=1;
    if(row>=1){
        v.push_back(k);
    }
    for(int i=0;i<row-1;i++){
        k=(k*(row-1-i))/(i+1);
        v.push_back(k);
    }
    return v;
}
// q3 
// print all the tringle 
// brute force apporach 
// time complexity is O(n^3)
// space complexity is O(1);
vector<vector<int>> print_all_brute(int row){
    vector<vector<int>> ans;
    for(int i=1;i<=row;i++){
        ans.push_back(print_row_brute(i));
    }
    return ans;
}
// optimal apporach 
// time complexity is O(n^2)
//space complexity is O(1)

vector<vector<int>> print_all_optimal(int row){
    vector<vector<int>> v;
    for(int i=1;i<=row;i++){
        v.push_back(print_row_optimal(i));
    }
    return v;
}

int main(){
    int row;
    cin>>row;
    int coloum;
    cin>>coloum;
    int ans=f(row,coloum);
    cout<<ans<<endl;
    int n=n_c_r(row,coloum);
    cout<<n<<endl;
    vector<int> brute=print_row_brute(row);
    cout<<endl;
    vector<int> optimal=print_row_optimal(row);
    for(auto it : optimal){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<vector<int>> all_brute=print_all_brute(row);
    for(auto it: all_brute){
        for(auto p: it){
            cout<<p<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> all_optimal=print_all_optimal(row);
    for(auto it: all_optimal){
        for(auto p: it){
            cout<<p<<" ";
        }
        cout<<endl;
    }

}
