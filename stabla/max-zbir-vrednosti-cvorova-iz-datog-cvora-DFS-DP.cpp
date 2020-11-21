//max zbir vrednosti cvorova iz datog cvora (root) (lista povezanosti + rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &stablo, vector<int> &DP,vector<int> &vrednost_cvora, int cvor, int roditelj)
{
    DP[cvor]=vrednost_cvora[cvor];
    int mx=0;
    for(auto cv : stablo[cvor])
    {
        if(cv == roditelj)
			continue;
         DFS(stablo, DP, vrednost_cvora, cv, cvor);
         mx = max(mx, DP[cv]);
    }
    DP[cvor]+=mx;
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>> stablo(n);
	vector<int> DP(n);
	vector<int> vrednost_cvora(n);
    for(int i = 0; i < m; i++)
       {
           cin >> a >> b;
           stablo[a].push_back(b);
           stablo[b].push_back(a);
       }
    for(int i = 0; i < n; i++)
		cin >> vrednost_cvora[i];

    DFS(stablo, DP, vrednost_cvora, 0, -1);
    cout << DP[0];
}

/*
14 13
0 1
0 2
0 3
1 4
1 5
2 6
3 7
3 8
3 9
4 10
4 11
6 12
6 13
3 2 1 10 1 3 9 1 5 3 4 5 9 8

22
*/
