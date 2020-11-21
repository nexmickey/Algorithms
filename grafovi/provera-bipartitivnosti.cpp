// provera bipartitivnosti  (lista povezanosti+BFS)
// ako je aktivna linija 21,ispisuje se udaljenost od pocetnog cvora
// ako je aktivna linija 22, ispisuju se nule i jedinice
#include<bits/stdc++.h>
using namespace std;

bool check_bipart(vector<vector<int>> &graf, vector<bool> &oznaceni,vector<int> &nivo, int cvor)
{
    queue<int> q;
    oznaceni[cvor] = true;
    nivo[cvor] = 0;
    q.push(cvor);
    while (!q.empty())
    {
        cvor = q.front();
        q.pop();
            for (int cv : graf[cvor])
                if (oznaceni[cv]==false)
                {
                    oznaceni[cv] = true;
                    nivo[cv] = nivo[cvor] + 1;
                    //nivo[cv] = 1 - nivo[cvor];
                    q.push(cv);
                }
                else if(nivo[cvor] == nivo[cv])
                    return false;
    }
    return true;
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int> > graf(n);
    vector<int> nivo(n);
    vector<bool> oznaceni(n,false);
    for(int i = 0; i < m; i++)
       {
           cin >> a >> b;
           graf[a-1].push_back(b-1);
           graf[b-1].push_back(a-1);
       }

    if(check_bipart(graf, oznaceni, nivo, 0))
        cout << "Bipartitni graf";
    else
        cout << "Nije bipartitni graf";
}

/*
9 8
1 2
2 3
2 8
3 4
4 6
5 7
5 9
8 9
Bipartitni graf

9 9
1 2
2 3
2 8
3 4
4 6
5 7
5 9
8 9
2 4
Nije bipartitni graf
*/
