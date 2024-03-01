#include <bits/stdc++.h>
using namespace std;


///  conceptual question hai 


bool is_safe(int num, int row, int col, vector<vector<int>> &v, int n)
{
    // condition for row
    for (int i = 0; i < n; i++)
    {
        if (v[row][i] == num)
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i][col] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
        {
            return false;
        }
    }
    return true;
}

/// concept ************

bool f(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0)
            {
                for (int k = 1; k<=n; k++)
                {
                    if (is_safe(k, i, j, v, n))
                    {
                        v[i][j] = k;
                        if (f(v, n) == true)
                        {
                            return true;
                        }else{
                            v[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "enter a number" << endl;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>v[i][j];
    }
  }
    f(v, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*9
5 4 0 0 2 0 8 0 6
0 1 9 0 0 7 0 0 3
0 0 0 3 0 0 2 1 0
9 0 0 4 0 5 0 2 0
0 0 1 0 0 0 6 0 4
6 0 4 0 3 2 0 8 0
0 6 0 0 0 0 1 9 0
4 0 2 0 0 9 0 0 5
0 9 0 0 7 0 4 0 2*/
