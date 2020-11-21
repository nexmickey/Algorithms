//precnik stablo (lista povezanosti + rekurzivni DFS)
#include<bits/stdc++.h>
using namespace std;

int x;

void DFS(vector<vector<int>> &stablo, int cvor, int precnik, int &max_precnik, int roditelj)
{
	precnik++;
    for(auto cv : stablo[cvor])
    {
		if(cv != roditelj)
		{
            if(precnik >= max_precnik)
			{
				max_precnik = precnik;
				x = cv;
			}
           DFS(stablo, cv, precnik, max_precnik,cvor);
		}
	}
}

int precnik_stablo(vector<vector<int>> &stablo)
{
	int max_precnik=INT_MIN;
    int precnik = 0;
    DFS(stablo, 0, precnik+1, max_precnik,-1);
    precnik = 0;
    DFS(stablo, x, precnik+1, max_precnik,-1);
    return max_precnik;
}


int main()
{
    int n,m,a,b,x;
    cin >> n >> m;
    vector<vector<int>> stablo(n);
    for(int i = 0; i < m; i++)
       {
           cin >> a >> b;
           stablo[a].push_back(b);
           stablo[b].push_back(a);
       }

    cout << precnik_stablo(stablo);
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
