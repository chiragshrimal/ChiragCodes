#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^2)
// space complexity is O(1)
vector<int> reapeat_missing_brute(vector<int>& v){
    int n=v.size();
    vector<int> ans;
    int reapet;
    int missing;
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(v[j]==i){
                count++;
            }
        }
        if(count==0){
            missing=i;
        }else{
            if(count==2){
                reapet=i;
            }
        }
    }
    ans.push_back(reapet);
    ans.push_back(missing);
    return ans;
}
// better apporach 
// time complexity is O(n);
// space complexity is O(n)
vector<int> reapeat_missing_better(vector<int>& v){
    int n=v.size();
    vector<int> fre(n+1,0);
    for(int i=0;i<n;i++){
        if(fre[v[i]]==0){
            fre[v[i]]=1;
        }else{
            fre[v[i]]++;
        }
    }
    int reapet;
    int missing;
    for(int i=1;i<n+1;i++){
        if(fre[i]==0){
            missing=i;
        }
        if(fre[i]>1){
            reapet=i;
        }
    }
    vector<int> ans;
    ans.push_back(reapet);
    ans.push_back(missing);
    return ans;
}
//better apporach 
// time complexity is O(nlog(n))
//space complexity is O(1);
vector<int> reapeat_missing_better2(vector<int>& v){
    int n=v.size();
    sort(v.begin(),v.end());
    int reapet;
    int i=0;
    for( i=0;i<n-1;i++){
        if(v[i]==v[i+1]){
            reapet=v[i];
            break;
        }
    }
    int missing;
    int x=0;
    for(int i=1;i<=n;i++){
        x=x^i;
        x=x^v[i-1];
    }
    missing=x^reapet;
    vector<int> ans;
    ans.push_back(reapet);
    ans.push_back(missing);
    return ans;

}
// optimal apporach using sum methord
// time complexity is O(n)
// space complexity is O(1)
vector<int> repeat_missing_optimal(vector<int>& v){
    int n=v.size();
    long long int actual_sum= (n*(n+1))/2;
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    int num1=actual_sum-sum;// x-y
    long long int actual_square_sum=(n*(n+1));
    actual_square_sum=(actual_square_sum*(2*n+1))/6;
    int square_sum=0;
    for(int i=0;i<n;i++){
        square_sum=square_sum + v[i]*v[i];
    }
    int num2=(long long)(actual_square_sum-square_sum)/(num1);// x+y
    int missing=(num1+num2)/2;
    int reapet=(num2-num1)/2;
    vector<int> ans;
    ans.push_back(reapet);
    ans.push_back(missing);
    return ans;
}
// optimal apporach2 using xor operator
// time complexity is O(n)
//space complexity is O(1)
vector<int> reapet_missing_optimal2(vector<int>& v){
    int n=v.size();
    int x=0;
    for(int i=1;i<=n;i++){
        x=x^v[i-1];
        x=x^i;
    }
    int bit=-1;
    for(int i=0;i<31;i++){
        if((1 & x)==1){
            bit=i;
            break;
        }
        x=x>>1;
    }
    int bit0=0;
    int bit1=0;
    for(int i=1;i<=n;i++){
        if((v[i-1]& (1<<bit))==0){
            bit0=bit0^v[i-1];
        }else{
            bit1=bit1^v[i-1];
        }
        if(((i)& (1<<bit))==0){
            bit0=bit0^i;
        }else{
            bit1=bit1^i;
        }
    }
    int count=0;
    int count2=0;
    int missing=-1;
    int reapet=-1;
    for(int i=0;i<n;i++){
        if(bit0==v[i]){
            count++;
        }
        if(bit1==v[i]){
            count2++;
        }
    }
    if(count==0){
        missing=bit0;
    }else{
        if(count==2){
            reapet=bit0;
        }
    }
    if(count2==0){
        missing=bit1;
    }else{
        if(count2==2){
            reapet=bit1;
        }
    }
    vector<int> ans;
    ans.push_back(reapet);
    ans.push_back(missing);
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> brute=reapeat_missing_brute(v);
    cout<<brute[0]<<" ";
    cout<<brute[1]<<" ";
    cout<<endl;
    vector<int> better=reapeat_missing_better(v);
    cout<<better[0]<<" ";
    cout<<better[1]<<" ";
    cout<<endl;
    vector<int> better2=reapeat_missing_better2(v);
    cout<<better2[0]<<" ";
    cout<<better2[1]<<" "; 
    cout<<endl;
    vector<int> optimal=repeat_missing_optimal(v);
    cout<<optimal[0]<<" ";
    cout<<optimal[1]<<" "; 

    cout<<endl;
    vector<int> optimal2=reapet_missing_optimal2(v);
    cout<<optimal[0]<<" ";
    cout<<optimal2[1]<<" ";




}