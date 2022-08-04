#include<bits/stdc++.h>
using namespace std;

bool postojiPut(vector<vector<bool> > v,vector<vector<bool> > poseceno,int n,int sv,int sk,int cv,int ck)
{
    if(sv==cv && sk==ck)
        return true;
    poseceno[sv][sk]=true;
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,-1,1};
    for (int i=0;i<4;i++)
    {
        int nsv=sv+dx[i];
        int nsk=sk+dy[i];
        if(0<=nsv && nsv<n && 0<=nsk  && nsk<n && !poseceno[nsv][nsk] && !v[nsv][nsk])
            if(postojiPut(v,poseceno,n,nsv,nsk,cv,ck))
                return true;
    }
    return false;
}

int main()
{
    int n,x;
    cin >> n;
    vector<vector<bool> > v(n,vector<bool> (n,false));
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            cin >> x;
            if(x==1)
                v[i][j]=true;
            else
                v[i][j]=false;
        }
    vector<vector<bool> > poseceno(n,vector<bool> (n,false));

    if(postojiPut(v,poseceno,n,0,0,n-1,n-1))
        cout << "Nasao sam put";
    else
        cout << "Nisam nasao put";
}
/*
6
0 1 1 1 1 1
0 0 0 0 0 1
0 1 0 1 0 1
0 1 0 1 0 1
0 0 1 1 0 1
1 1 1 0 0 0
Nasao sam put

6
0 1 1 1 1 1
0 0 0 0 0 1
0 1 0 1 0 1
0 1 0 1 1 1
0 0 1 1 0 1
1 1 1 0 0 0
Nisam nasao put
*/
