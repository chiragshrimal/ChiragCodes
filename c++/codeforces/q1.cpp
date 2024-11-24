#include<bits/stdc++.h>
int main (){
    int t;
    std::cin>>t;
    while(t--){
        int a;
        std::cin>>a;
        if((a>=102 && a<=109)||(a>=1010 && a<=1099)){
            std::cout<<"yes"<<std::endl;
        }else{
            std::cout<<"no"<<std::endl;
        }
        
    }
}