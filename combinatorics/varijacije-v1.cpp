//varijacije v1
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int> &varijacija)
{
    for (int i = 0; i < varijacija.size(); i++)
        cout << varijacija[i] << " ";
    cout << endl;
}

void obradiSveVarijacije(int k, int n, vector<int>& varijacija)
{
    if (k == 0)
        obradi(varijacija);
    else
        for (int nn = 1; nn <= n; nn++)
        {
            varijacija[varijacija.size() - k] = nn;
            obradiSveVarijacije(k - 1, n, varijacija);
        }
}

void obradiSveVarijacije(int k, int n)
{
    vector<int> varijacija(k);
    obradiSveVarijacije(k, n, varijacija);
}

int main()
{
    int k, n;
    cin >> k >> n;
    obradiSveVarijacije(k, n);
}

/*
3 2

1 1 1  1 1 2  1 2 1  1 2 2  2 1 1  2 1 2  2 2 1  2 2 2
*/
