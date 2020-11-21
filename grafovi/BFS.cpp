//lista povezanosti u neusmerenom grafu + nerekurzivni BFS
#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &graf, vector<bool> &oznaceni, int cvor)
{
    queue<int> q;
    oznaceni[cvor] = true;
    q.push(cvor);
    while (!q.empty())
    {
        cvor = q.front();
        q.pop();
        cout << cvor << " ";
            for (int cv : graf[cvor])
                if (oznaceni[cv]==false)
                {
                    oznaceni[cv] = true;
                    q.push(cv);
                }
    }
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
       for (int i = 0; i < n; i++)           //mogu se obici i nepovezani grafovi
            if (oznaceni[i] == false)       //cvorovi se unose od 1, onda je 0 nepovezana
                BFS(graf, oznaceni, i);
   // BFS(graf, oznaceni, 0);            //moze i ovako, bez petlje, ali samo povezani grafovi!
}
