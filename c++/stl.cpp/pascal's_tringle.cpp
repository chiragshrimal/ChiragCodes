#include<bits/stdc++.h>
using namespace std;
/*long long int nCr(int n,int r){
	long long m=1;
	long long k=1;
	for(int i=r;i>=1;i--){
		 m=m*(n-i+1);
		 k=k*i;

	}
	return m/k ;
}
int main (){
	int t;
	cin>>t;
	while(t--){
		int n;
        cin>>n;
		for(int i=1;i<=n;i++){//time comlexity O(n^3);//space complexty is O(1)
			for(int j=1;j<=i;j++){
				cout<<nCr(i-1,j-1)<<" ";
			}
			cout<<endl;
		}
	}
}*/
int main (){
	int n;
	cin>>n;
	int a[n+1][n+1];
	for(int i=1;i<=n;i++){//time complexity O(n^2);//space complexity is O(n^2);
		for(int j=1;j<=i;j++){
			if(j==1){
				a[i][j]==1;
			}else{
				if(j==i){
					a[i][j]==1;
				}else{
					a[i][j]=a[i-1][j-1]+a[i-1][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

}