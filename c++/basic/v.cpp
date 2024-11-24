#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long int N,M;
		cin>>N>>M;
	unordered_set< long long int> s1;
	vector<long long > v;
	for(int i=1;i<=N;i++){
		long long int x;
		cin>>x;
		s1.insert(x);
	}
	for(int i=1;i<=M;i++){
		long long int x;
		cin>>x;
		v.push_back(x);
	}
	for(auto it=v.begin();it!=v.end();it++){
		auto it1=s1.find(*it);
		if(it1!=s1.end()){
			cout<<"YES"<<endl;
			s1.insert(*it);
		}else{
			cout<<"NO"<<endl;
			s1.insert(*it);
		}
	}
}
}