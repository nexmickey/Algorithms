//broj povezanih komponenti (lista povezanosti+rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

void povKomponente(vector<vector<int>> &graf, vector<bool> &oznaceni, int cvor)
{
    oznaceni[cvor]=true;
    for(auto cv:graf[cvor])
        if(oznaceni[cv]==false)
            povKomponente(graf, oznaceni, cv);
}

int main()
{
    int n,m,a,b,br=0;
    cin >> n >> m;
    vector<vector<int>> graf(n);
    vector<bool> oznaceni(n,false);
    for(int i=0; i<m; i++)
       {
           cin >> a >> b;
           graf[a].push_back(b);
           graf[b].push_back(a);
       }
    for (int i=0;i<n;i++)
        if(oznaceni[i]==false)
        {
            br++;
            povKomponente(graf,oznaceni,i);
        }
    cout << br;
}

/*
15 17
0 1
0 2
0 5
1 3
1 4
2 3
2 6
4 6
5 6
7 11
7 12
8 12
9 10
9 14
10 14
11 12
12 13

3
*/
