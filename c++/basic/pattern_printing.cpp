#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "enter a number ";
    cin >> n;
    //******
    //******
    //******
    //******
    //******
    //******
    /*for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             cout<<"* ";
         }
         cout<<endl;
     }*/
    //*****
    //*   *
    //*   *
    //*****
    /*for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++){
            if(i==1||j==1||j==n||i==n-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
    }
    cout<<endl;
}*/
    //*
    //**
    //***
    //****
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/
    //   *
    //  **
    // ***
    //****
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>=1&&j<=n-i){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }*/
    // 1
    // 12
    // 123
    // 1234
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }*/
    // 1
    // 23
    // 456
    // 78910
    /*int k=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<k;
            k++;
        }
        cout<<endl;
    }*/
    // 1
    // 01
    // 101
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if((i+j)%2==0){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }
        cout<<endl;
    }*/
    //*  *
    //****
    //****
    //*  *
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"*";
        }
        for(int j=1;j<=2*(i-1);j++){
            cout<<" ";
        }
        for(int j=1;j<=n-i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
            for(int k=1;k<=n-i;k++){
                cout<<"*";
            }
        cout<<endl;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int k=1;k<=i;k++){
             cout<<i<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        int k=i;
        for(int j=1;j<=i;j++){
            cout<<k;
            k--;
        }
        int x=2;
        if(i>=2){
            for(int j=1;j<=i-1;j++){
                cout<<x;
                x++;
            }
        }
        cout<<endl;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        if(i>=2){
            for(int j=1;j<=i-1;j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        cout<<"*";
        for(int j=1;j<=i-2;j++){
            cout<<" ";
        }
        if(i>1)
        cout<<"*";
        for(int j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        cout<<"*";
        for(int j=1;j<=i-2;j++){
            cout<<" ";
        }
        if(i>1)
        cout<<"*";
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        cout<<"*";
        for(int j=1;j<=n-(i+1);j++){
            cout<<" ";
        }
        if(i<n)
        cout<<"*";
        for(int j=1;j<=2*i-2;j++){
            cout<<" ";
        }
        cout<<"*";
         for(int j=1;j<=n-(i+1);j++){
            cout<<" ";
        }
        if(i<n){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            cout<<" ";
        }
        for(int j=1;j<=n-i+1;j++){
            cout<<i<<" ";
        }
        cout<<endl;

    }

}