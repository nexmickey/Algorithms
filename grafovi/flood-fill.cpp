//flood fill (lista povezanosti+rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

void flood_fill(vector<vector<int> > &graf,vector<bool> &obilazak,int cvor)
{
    obilazak[cvor]=true;
    for(auto x:graf[cvor])
        if(obilazak[x]==false)
            flood_fill(graf,obilazak,x);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,a,b,br=0,g;
    cin >> n >> m;
    vector<vector<int> > graf(n);
    vector<bool> obilazak(n,false);
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    cin >> g;
    flood_fill(graf,obilazak,g);
    for (int i=0;i<n;i++)
        if(obilazak[i])
            cout << i << " ";
}

