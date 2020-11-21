//maksimalna dubina stabla iz datog cvora (lista povezanosti + rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

void DFS1(vector<vector<int>> &stablo, vector<int> &in, vector<int> &out, int cvor, int roditelj)
{
    in[cvor]=0;
    for(auto cv : stablo[cvor])
    {
        if(cv == roditelj)
			continue;
         DFS1(stablo, in, out, cv, cvor);
         in[cvor] = max(in[cvor], 1 + in[cv]);
    }
}

void DFS2(vector<vector<int>> &stablo, vector<int> &in, vector<int> &out, int cvor, int roditelj)
{
    int mx1=-1;
    int mx2=-2;
    for(auto cv : stablo[cvor])
    {
        if(cv == roditelj)
			continue;
		if (in[cv] >= mx1)
		{
            mx2 = mx1;
            mx1 = in[cv];
        }
        else if (in[cv] > mx2)
            mx2 = in[cv];
	}

	for (auto cv : stablo[cvor])
    {
        if (cv == roditelj)
            continue;
        int najduzi = mx1;
        if (mx1 == in[cv])
            najduzi = mx2;
        out[cv] = 1 + max(out[cvor], 1 + najduzi);

        DFS2(stablo, in, out, cv, cvor);
    }
}


int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<vector<int>> stablo(n);
	vector<int> in(n);
	vector<int> out(n,0);

    for(int i = 0; i < m; i++)
       {
           cin >> a >> b;
           stablo[a].push_back(b);
           stablo[b].push_back(a);
       }
    DFS1(stablo, in, out, 0, -1);
    DFS2(stablo, in, out, 0, -1);

    for(int i = 0; i < n; i++)
		cout << max(in[i],out[i]) << " ";
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

3 4 3 4 5 5 4 5 5 5 5
*/
