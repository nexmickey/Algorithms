//kombinacije bez ponavljanja v2
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int> &kombinacija)
{
    for (int i = 0; i < kombinacija.size(); i++)
        cout << kombinacija[i] << " ";
    cout << endl;
}

void obradiSveKombinacije(vector<int>& kombinacija, int i, int n_min, int n_max)
{
    int k = kombinacija.size();
    if (i == k)
    {
        obradi(kombinacija);
        return;
    }
    if (n_min > n_max)
        return;
    kombinacija[i] = n_min;
    obradiSveKombinacije(kombinacija, i + 1, n_min + 1, n_max);
    obradiSveKombinacije(kombinacija, i, n_min + 1, n_max);
}

void obradiSveKombinacije(int k, int n)
{
    vector<int> kombinacija(k);
    obradiSveKombinacije(kombinacija, 0, 1, n);
}

int main()
{
    int n, k;
    cin >> k >> n;
    obradiSveKombinacije(k, n);
}

/*
3 5

1 2 3  1 2 4  1 2 5  1 3 4  1 3 5  1 4 5  2 3 4  2 3 5  2 4 5  3 4 5
*/
