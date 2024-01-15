#include <iostream>
using namespace std;
int main() {
	string s;
	cin>>s;
	int q;
	cin>>q;
	while(q){
		char a;
		cin>>a;
		char b;
		cin>>b;
		int count=0;
		if(a==b){
			for(int i=0;i<s.size();i++){
				if(s[i]==a){
					count++;
				}
                }
				count=count+(count*(count-1))/2;
				cout<< count;
			
		}else{
			int count2=0;
			for(int i=0;i<s.size();i++){
				if(s[i]==a){
					for(int j=i;j<s.size();j++){
						if(s[j]==b){
							count2++;
						}
					}
				}
			}
			cout<<count2;
		}
		q--;
		cout<<endl;
	}
}