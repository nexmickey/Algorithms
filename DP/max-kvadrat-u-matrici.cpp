//max kvadrat
#include<bits/stdc++.h>
using namespace std;

int f1(vector<vector<int> > v,int n,int m,vector<vector<int> > &dp1)
{
    int mx = 0;
     for (int i=0;i<n;i++)
        dp1[i][0]=v[i][0];
    for (int j=0;j<m;j++)
        dp1[0][j]=v[0][j];

    for (int i=1;i<n;i++)
        for (int j=1;j<m;j++)
        {
            if(v[i][j]==0)
                dp1[i][j]=0;
            else
                dp1[i][j]=min({dp1[i-1][j], dp1[i][j-1], dp1[i-1][j-1]})+1;
            if(mx<dp1[i][j])
                mx=dp1[i][j];
        }
    return mx;
}

int f(vector<vector<int> > v,int n,int m,vector<int> &dp)
{
    int mx = 0;
    for (int j = 0; j < m; j++)
        {
        dp[j] = v[0][j];
        if (dp[j] > mx)
            mx = dp[j];
        }
        for (int i = 1; i < n; i++)
        {
            int prethodni = dp[0];
            dp[0] = v[i][0];
            if (dp[0] > mx)
                mx = dp[0];
            for (int j = 1; j < m; j++)
            {
                int tekuci = dp[j];
                if (v[i][j] == 0)
                    dp[j] = 0;
                else
                    dp[j] = min({prethodni, tekuci, dp[j-1]}) + 1;
                if (dp[j] > mx)
                    mx = dp[j];
                prethodni = tekuci;
            }
        }
    return mx;
}

int main()
{
    int n,m,mx=0;
    cin >> n >> m;
    vector<vector<int> > v(n,vector<int> (m,0));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> v[i][j];
    vector<int> dp(m+1,0);
    vector<vector<int> > dp1(n,vector<int> (m,0));

    cout << f(v,n,m,dp) << endl;
    cout << f1(v,n,m,dp1) << endl;

    for (int i = 0; i < n; i++, cout << endl) //ispis DP matrice
        for (int j = 0; j < m; j++)
            cout << dp1[i][j] << " ";
}

/*
5 5
1 1 1 1 1
1 0 1 1 1
1 1 1 1 1
1 0 1 0 1
1 1 1 1 1
3
*/
