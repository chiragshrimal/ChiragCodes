#include<bits/stdc++.h>
using namespace std;

// brute force apporach like  generates all the subarray
// time complexity is O()
// space complexity is O()
int number_substring_brute(string str){
    int n=str.size();
    int count=0;
    for(int i=0;i<n;i++){
        int hash[3]={0};
        for(int j=i;j<n;j++){
            hash[str[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                count=count+n-j;
                break;
            }
        }
    }
    return count;
}
// optimal apporach using two pointer apporach   
// time complexity is O(2*n)
//space complexity is O(3)

int number_substring_optimal(string str){
    int n=str.size();
    unordered_map<char,int> m;
    int i=0;
    int j=0;
    int count=0;
    while(j<n){
        m[str[j]]++;
        while(m.size()==3){
            count=count+n-j;
            m[str[i]]--;
            if(m[str[i]]==0){
                m.erase(str[i]);
            }
            i++;
        }
        j++;
        }
        return count;

    }

// optimal apporach2 (good concept reverse ka feel aaya hai uper wali apporach ka )
// time complexity is O(n)
// space complexity is O(1);
int number_substring_optimal2(string str){
    int n=str.size();
    int a=-1;
    int b=-1;
    int c=-1;
    int count=0;
    for(int i=0;i<n;i++){
        if(str[i]=='a'){
            a=i;
        }
         if(str[i]=='b'){
            b=i;
        }
         if(str[i]=='c'){
            c=i;
        }
        if(a!=-1 && b!=-1 && c!=-1){
            int minimum=min(a,min(b,c));
            count=count + minimum+1;

        }
    }
    return count;
}


int main(){
    string s;
    cin>>s;
    int brute=number_substring_brute(s);
    cout<<brute<<endl;
    int optimal=number_substring_optimal(s);
    cout<<optimal<<endl;

    int optimal2=number_substring_optimal2(s);
    cout<<optimal2<<endl;
    
}