//provera ciklicnosti u neusmerenom grafu (lista povezanosti+rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

bool ciklus(vector<vector<int>> &graf, vector<bool> &oznaceni, int cvor, int otac)
{
    oznaceni[cvor] = true;
    for(auto cv : graf[cvor])
    {
         if(oznaceni[cv]==false)
         {
             if (ciklus(graf, oznaceni, cv,cvor))
                return true;
         }
        else if(cv != otac)
            return true;
    }
    return false;
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>> graf(n);
    vector<bool> oznaceni(n,false);
    for(int i = 0; i < m; i++)
       {
           cin >> a >> b;
           graf[a].push_back(b);
           graf[b].push_back(a);
       }

        if (ciklus(graf, oznaceni, 0,-1))
            {
                cout << "ima ciklusa!";
                //return 0;
            }
        else
            cout << "nema ciklusa";
}

/*
6 5
0 1
0 2
2 1
0 3
3 4

Ima ciklusa!
Ako  0 2 premenimo u 5 2 - nema cklusa
*/
