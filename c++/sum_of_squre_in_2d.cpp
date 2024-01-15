#include<bits/stdc++.h>
using namespace std;
//n===10^3;
// q==10^5;
int main(){
    int N=1e3;
long long int brr[N][N];
    int row,colum;
    cin>>row>>colum;
    int q;
    cin>>q;
    int arr[row+1][colum+1];
    for(int i=1;i<=row;i++){
        for(int j=1;j<=colum;j++){
            cin>>arr[i][j];
            brr[i][j]=brr[i-1][j]+brr[i][j-1]+arr[i][j];
        }
    }
    while(q--){
        int a;
        int b;
        int c;
        int d;
        cin>>a>>b>>c>>d;
       // int sum=0;
        //for(int i=a;i<=c;i++){
            //for(int j=b;j<=d;j++){
               // sum=sum+arr[i][j];
           // }
       // }

        cout<<brr[c][d]-brr[c][b-1]-brr[a-1][d]+brr[a-1][b-1]<<endl;
//// 1 sec ke ander complete krne k liye while k  under O(1) hona chahiye
    }
    //time complexity is >> 1sec;

}