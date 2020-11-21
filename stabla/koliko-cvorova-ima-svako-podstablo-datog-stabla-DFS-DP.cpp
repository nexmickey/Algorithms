//koliko cvorova ima svako podstablo datog stabla (lista povezanosti + rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &stablo, vector<int> &DP,int cvor, int roditelj)
{
    DP[cvor]=1;
    for(auto cv : stablo[cvor])
    {
        if(cv == roditelj)
			continue;
         DFS(stablo, DP, cv, cvor);
         DP[cvor] += DP[cv];
    }
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>> stablo(n);
	vector<int> DP(n);
    for(int i = 0; i < m; i++)
       {
           cin >> a >> b;
           stablo[a].push_back(b);
           stablo[b].push_back(a);
       }
    DFS(stablo, DP, 0, -1);
    for(int i = 0; i < n; i++)
		cout << DP[i] << " ";
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

11 3 4 3 1 1 3 1 1 1 1
*/
