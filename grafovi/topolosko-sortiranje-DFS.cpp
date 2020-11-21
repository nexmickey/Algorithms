//Topolosko sortiranje  - usmereni acklicni graf (DAG)
#include<bits/stdc++.h>
using namespace std;

bool f(vector<vector<int>> &graf,vector<bool> &provera,vector<bool> &put,queue<int> &cvoroviObradjivanje,queue<int> &spisakCvorova,int cvor)
{
    if(provera[cvor]==false && put[cvor])
        return false;
    spisakCvorova.push(cvor);
    cvoroviObradjivanje.push(cvor);
    put[cvor]=true;
    for(auto x:graf[cvor])
    {
        if(provera[x]==false && f(graf,provera,put,cvoroviObradjivanje,spisakCvorova,x)==false)
            return false;
    }
    spisakCvorova.pop();
    put[cvor]=false;
    return true;
}



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m, a, b, g;
    cin >> g;
    for(int j=0;j<g;j++)
    {
        cin >> n >> m;
        bool tacno=true;
        vector<vector<int> > graf(n);
        queue<int> cvoroviObradjivanje;
        queue<int> spisakCvorova;
        vector<bool> provera(n,false);
        vector<bool> put(n,false);
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            graf[a].push_back(b);
        }
        for(int i = 0; i < n; i++)
            if(provera[i]==false && f(graf,provera,put,cvoroviObradjivanje,spisakCvorova,i)==false)
            {
                tacno=false;
                break;
            }
            else
            {
                while(!cvoroviObradjivanje.empty())
                {
                    provera[cvoroviObradjivanje.front()]=true;
                    cvoroviObradjivanje.pop();
                }
            }
        if(tacno)
            cout << "ne" << '\n';
        else
            cout << "da" << '\n';
    }
}

/*
6 6
2 3
3 1
4 0
4 1
5 0
5 2

5 4 2 3 1 0
*/
