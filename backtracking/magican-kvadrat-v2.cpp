#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > kvadrat;
vector<bool> upotrebnjen;
int zbir,br=0;

int zbirVrste(int v,int maxk)
{
    int zbir=0;
    for (int k=0;k<=maxk;k++)
        zbir+=kvadrat[v][k];
    return zbir;
}

int zbirVrste(int v)
{
    return zbirVrste(v,n-1);
}

int zbirKolone(int k,int maxv)
{
    int zbir=0;
    for (int v=0;v<=maxv;v++)
        zbir+=kvadrat[v][k];
    return zbir;
}

int zbirKolone(int k)
{
    return zbirKolone(k,n-1);
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

void ispisi()
{
    br++;
    cout << br << endl;
    for (int i=0;i<n;i++,cout << endl)
        for (int j=0;j<n;j++)
            cout << kvadrat[i][j] << " ";
    cout << endl;
}

void popuni(int v,int k)
{
    if(k==0 && v>0)
        if(zbirVrste(v-1)!=zbir)
            return;
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

            int pk=n-k-1;
            if(zbirVrste(v,k)+pk*(pk+1)/2>zbir)
            {
                kvadrat[v][k]=0;
                upotrebnjen[broj-1]=false;
                return;
            }

            int pv=n-v-1;
            if(zbirKolone(k,v)+pv*(pv+1)/2>zbir)
            {
                kvadrat[v][k]=0;
                upotrebnjen[broj-1]=false;
                return;
            }

            int sv=v;
            int sk=k+1;
            if(sk==n)
            {
                sv=v+1;
                sk=0;
            }
            popuni(sv,sk);
            kvadrat[v][k]=0;
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
