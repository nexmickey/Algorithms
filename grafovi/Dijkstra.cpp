//najkraci put u tezinskom grafu - Dijkstra  (lista povezanosti+BFS)
#include<bits/stdc++.h>
using namespace std;

void Dijkstra(vector<vector<pair<int, int>> > graf, vector<int> &rastojanje, vector<int> &prethodni, int cvor)
{
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    rastojanje[cvor] = 0;
    pq.push({0,cvor});
    while (!pq.empty())
    {
        int v = pq.top().second;
        int rast_v = pq.top().first;
        pq.pop();
        if(rast_v != rastojanje[v])
            continue;
            for (auto cv: graf[v])
            {
                int u = cv.first;
                int tezina = cv.second;
                if (rastojanje[u] > rastojanje[v] + tezina)
                {
                    rastojanje[u] = rastojanje[v] + tezina;
                    prethodni[u] = v;
                    pq.push({rastojanje[u], u});
                }
            }
    }
}


int main()
{
    int n,m,a,b,tez;
    cin >> n >> m;
    vector<vector <pair<int, int>> > graf(n);
    vector<int> rastojanje(n,INT_MAX);
    vector<int> prethodni(n,-1);
    for(int i = 0; i < m; i++)
       {
           cin >> a >> b >> tez;
           graf[a].push_back({b,tez});
           graf[b].push_back({a,tez});
       }
    Dijkstra(graf, rastojanje, prethodni, 0);
    for(int i = 0; i < n; i++)
        cout << i << " -> " << rastojanje[i] << endl;
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

0 -> 0
1 -> 4
2 -> 12
3 -> 19
4 -> 21
5 -> 11
6 -> 9
7 -> 8
8 -> 14

*/
