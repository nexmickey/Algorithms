#include<bits/stdc++.h>
using namespace std;

int n, zbir, br=0;
vector<vector<int> > kvadrat;
vector<bool> upotrebnjen;


void ispisi()
{
    br++;
    cout << br << endl;
    for (int i=0;i<n;i++,cout << endl)
        for (int j=0;j<n;j++)
            cout << kvadrat[i][j] << " ";
    cout << endl;
}

int zbirVrste(int v)
{
    int zbir=0;
    for (int k=0;k<n;k++)
        zbir+=kvadrat[v][k];
    return zbir;
}

int zbirKolone(int k)
{
    int zbir=0;
    for (int v=0;v<n;v++)
        zbir+=kvadrat[v][k];
    return zbir;
}

int zbirGlavneDijagonale()
{
    int zbir=0;
    for (int i=0;i<n;i++)
        zbir+=kvadrat[i][i];
    return zbir;
}

int zbirSporedneDijagonale()
{
    int zbir=0;
    for (int i=0;i<n;i++)
        zbir+=kvadrat[i][n-i-1];
    return zbir;
}

bool magican()
{
    for (int v=0;v<n;v++)
        if(zbirVrste(v)!=zbir)
            return false;
    for (int k=0;k<n;k++)
        if(zbirKolone(k)!=zbir)
            return false;
    if(zbirGlavneDijagonale()!=zbir)
        return false;
    if(zbirSporedneDijagonale()!=zbir)
        return false;


    return true;
}

void popuni(int v,int k)
{
    if(v==n)
    {
        if(magican())
            ispisi();
    }
    else
    {
    for (int broj=1;broj<=n*n;broj++)
        if(!upotrebnjen[broj-1])
        {
            kvadrat[v][k]=broj;
            upotrebnjen[broj-1]=true;
            int sv=v;
            int sk=k+1;
            if(sk==n)
            {
                sv=v+1;
                sk=0;
            }
            popuni(sv,sk);
            upotrebnjen[broj-1]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    kvadrat.resize(n);
    for (int i=0;i<n;i++)
        kvadrat[i].resize(n);
    upotrebnjen.resize(n*n,false);
    zbir=n*(n*n+1)/2;
    popuni(0,0);
}


