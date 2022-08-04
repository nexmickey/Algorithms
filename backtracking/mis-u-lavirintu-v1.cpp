#include<bits/stdc++.h>
using namespace std;

bool postojiPut(vector<vector<bool> > v,vector<vector<bool> > poseceno,int n,int sv,int sk,int cv,int ck)
{
    if(sv==cv && sk==ck)
        return true;
    poseceno[sv][sk]=true;
    if(sv>0 && !poseceno[sv-1][sk] && !v[sv-1][sk])
        if(postojiPut(v,poseceno,n,sv-1,sk,cv,ck))
            return true;
    if(sk>0 && !poseceno[sv][sk-1] && !v[sv][sk-1])
        if(postojiPut(v,poseceno,n,sv,sk-1,cv,ck))
            return true;
    if(sk>0 && !poseceno[sv][sk-1] && !v[sv][sk-1])
        if(postojiPut(v,poseceno,n,sv,sk-1,cv,ck))
            return true;
    if(sv<n-1 && !poseceno[sv+1][sk] && !v[sv+1][sk])
        if(postojiPut(v,poseceno,n,sv+1,sk,cv,ck))
            return true;
    if(sk<n-1 && !poseceno[sv][sk+1] && !v[sv][sk+1])
        if(postojiPut(v,poseceno,n,sv,sk+1,cv,ck))
            return true;
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
