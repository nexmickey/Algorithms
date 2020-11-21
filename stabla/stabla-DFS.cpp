//DFS pretraga stabla (lista povezanosti + rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &stablo,int cvor, int roditelj)
{
    cout << cvor << " ";
    for(auto cv : stablo[cvor])
        if(cv != roditelj)
            DFS(stablo, cv, cvor);
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
11 10
0 1
0 2
0 3
1 4
1 5
2 6
3 7
3 8
6 9
6 10

0 1 4 5 2 6 9 10 3 7 8
*/
