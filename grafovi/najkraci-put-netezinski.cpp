//najkraci put u neusmerenom i netezinskom grafu (lista povezanosti+BFS)
#include<bits/stdc++.h>
using namespace std;

void najkraci_put(vector<vector<int>> &graf,vector<int> &rastojanje,vector<int> &pred,vector<bool> &oznaceni,int s, int d)
{
    queue<int>q;
    q.push(s);
    rastojanje[s] = 0;
    oznaceni[s] = true;

    while(!q.empty())
    {
        int cvor=q.front();
        q.pop();
        for(auto cv:graf[cvor])
        {
            if(oznaceni[cv]==false)
            {
                oznaceni[cv]=true;
                rastojanje[cv]=rastojanje[cvor] + 1;
                pred[cv]=cvor;
                q.push(cv);

                if(cv==d)
                    return;
            }
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > graf(n);
    vector<int> rastojanje(n,INT_MAX);
    vector<int> pred(n,-1);
    vector<bool> oznaceni(n,false);
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    cin >> a >> b;
    najkraci_put(graf,rastojanje,pred,oznaceni,a,b);
    cout << rastojanje[b] << endl;

    //rekonstrukcija puta
    vector<int> putanja;
    int kraj=b;
    putanja.push_back(kraj);
    while(pred[kraj]!=-1)
    {
        putanja.push_back(pred[kraj]);
        kraj=pred[kraj];
    }
    //ispisivanje puta
    for(int i=putanja.size()-1; i>=0; i--)
        cout<< putanja[i]<< " ";
}
/*
8 10
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7
2 6

5
2 1 0 3 4 6
*/
