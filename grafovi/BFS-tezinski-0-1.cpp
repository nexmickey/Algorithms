//najkraci put u tezinskom grafu 0-1  (lista povezanosti+BFS)
#include<bits/stdc++.h>
using namespace std;

void najkraci_put(vector<vector<pair<int, int>> > graf, vector<int> &rastojanje, int cvor)
{
    deque<int> d;
    rastojanje[cvor] = 0;
    d.push_back(cvor);
    while (!d.empty())
    {
        int v = d.front();
        d.pop_front();
            for (auto cv: graf[v])
            {
                int u = cv.first;
                int tezina = cv.second;
                if (rastojanje[u] > rastojanje[v] + tezina)
                {
                   rastojanje[u] = rastojanje[v] + tezina;
                   if(tezina == 0)
                        d.push_front(u);
                    else
                        d.push_back(u);
                }
            }
    }
     for (int i=0; i< rastojanje.size(); i++)
        cout << rastojanje[i] << " ";
}


int main()
{
    int n,m,a,b,tez;
    cin >> n >> m;
    vector<vector <pair<int, int>> > graf(n);
    vector<int> rastojanje(n,INT_MAX);
    for(int i = 0; i < m; i++)
       {
           cin >> a >> b >> tez;
           graf[a].push_back({b,tez});
           graf[b].push_back({a,tez});
       }
    najkraci_put(graf, rastojanje, 0);

}

/*
BFS 0-1.png
9 13
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
7 8 1

0 0 1 1 2 1 2 1 2
*/
