//Topolosko sortiranje  - usmereni acklicni graf
//Ispisuje leksikografsko najmanje resenje
//ako nije bitno najmanje,moze da se koristi i queue
#include<bits/stdc++.h>
using namespace std;

void topolosko_sortiranje(vector<vector<int>> &graf, int n)
{
    vector<int> ulStepen(n, 0);
    vector<int> topSort;
    int brPosecenih = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < graf[i].size(); j++)
            ulStepen[graf[i][j]]++;
    for (int i = 0; i < n; i++)
        if (ulStepen[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        int cvor = q.top();
        q.pop();
        topSort.push_back(cvor);
        brPosecenih++;
        for(auto cv: graf[cvor])
        {
            ulStepen[cv]--;
            if (ulStepen[cv] == 0)
                q.push(cv);
        }
    }
    if (brPosecenih == n)
        for(int i = 0; i < n; i++)
            cout << topSort[i] << " ";
    else
        cout << "Ne" << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > graf(n);
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
    }
    topolosko_sortiranje(graf, n);
}

/*
6 6
2 3
3 1
4 0
4 1
5 0
5 2

4 5 0 2 3 1
*/
