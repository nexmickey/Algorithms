//DFS obilazak stabla (lista povezanosti + rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &stablo, int cvor, int roditelj)
{
    cout << cvor << " ";   // ulazna obrada
    for(auto cv : stablo[cvor])
        if(cv != roditelj)
            DFS(stablo, cv, cvor);
    //cout << cvor << " ";    // izlazna obrada
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>> stablo(n);

    for(int i = 0; i < m; i++)
       {
           cin >> a >> b;
           stablo[a].push_back(b);
           stablo[b].push_back(a);
       }

    DFS(stablo, 0, -1);
}

/*
13 12
0 1
0 2
0 3
1 4
1 5
1 6
3 7
3 8
6 9
6 10
7 11
9 12

0 1 4 5 6 9 12 10 2 3 7 11 8
*/
