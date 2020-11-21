//precnik stablo (lista povezanosti + rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;


int DFS(vector<vector<int>> &stablo, vector<int> &DP1, vector<int> &DP2, int cvor, int roditelj)
{
    int prvi_maks = -1;
    int drugi_maks = -1;
    for(auto cv : stablo[cvor])
    {
        if(cv == roditelj)
			continue;

         DFS(stablo, DP1, DP2, cv, cvor);
         if (prvi_maks == -1)
            prvi_maks = DP1[cv];
         else if (DP1[cv] >= prvi_maks)
         {
            drugi_maks = prvi_maks;
            prvi_maks = DP1[cv];
         }
         else if (DP1[cv] > drugi_maks)
            drugi_maks = DP1[cv];
	}

    DP1[cvor] = 1;
    if (prvi_maks != -1)
        DP1[cvor] += prvi_maks;
    if (drugi_maks != -1)
        DP2[cvor] = 1 + prvi_maks + drugi_maks;

    return max(DP1[cvor], DP2[cvor]);
}
int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>> stablo(n);
    vector<int> DP1(n,0);
    vector<int> DP2(n,0);
    for(int i = 0; i < m; i++)
       {
           cin >> a >> b;
           stablo[a].push_back(b);
           stablo[b].push_back(a);
       }
    cout << DFS(stablo, DP1, DP2, 0, 0);
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

8

5 4
0 1
0 2
1 3
1 4

4
*/
