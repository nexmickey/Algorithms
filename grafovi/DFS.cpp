//lista povezanosti u neusmerenom grafu + rekurzivni DFS
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &graf, vector<bool> &oznaceni, int cvor)
{
    oznaceni[cvor] = true;
    cout << cvor << " ";   // ulazna obrada
    for(auto cv : graf[cvor])
        if(oznaceni[cv] == false)
            DFS(graf, oznaceni, cv);
    //cout << cvor << " ";    // izlazna obrada
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

    for (int i = 0; i < n; i++)             //mogu se obici i nepovezani grafovi
		if (oznaceni[i] == false)           //cvorovi se unose od 1, onda je 0 nepovezana
            DFS(graf, oznaceni, i);
    // DFS(graf, oznaceni, 0);              //moze i ovako, bez petlje, ali samo povezani grafovi!
}

