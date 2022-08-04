#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > potezi ={{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
int br=0;

void ispisi(const vector<vector<int> >& tabla,int m,int n)
{
    br++;
    cout << br << endl;
    for (int i=0;i<m;i++,cout << endl)
            for (int j=0;j<n;j++)
                cout << tabla[i][j] << " ";
        cout << endl;
}


void obidjiTabluSkakacem(vector<vector<int> >& tabla,int m,int n,int v,int k,int sledece)
{
    if(sledece>m*n)
        ispisi(tabla,m,n);
    else
    {

    for (int i=0;i<8;i++)
    {
        int nv=v+potezi[i][0];
        int nk=k+potezi[i][1];
        if(0<=nv && nv<m && 0<=nk && nk<n && tabla[nv][nk]==0)
        {
            tabla[nv][nk]=sledece;
            obidjiTabluSkakacem(tabla,m,n,nv,nk,sledece+1);
            tabla[nv][nk]=0;
        }
    }
    }
}
int main()
{
    int m,n,x;
    cin >> m >> n;
    vector<vector<int> > tabla(m,vector<int> (n,false));
    tabla[0][0]=1;
    int sledece=2;
    obidjiTabluSkakacem(tabla,m,n,0,0,sledece);
}


