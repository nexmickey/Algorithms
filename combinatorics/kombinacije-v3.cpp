//kombinacije bez ponavljanja v3
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int> &kombinacija)
{
    for (int i = 0; i < kombinacija.size(); i++)
        cout << kombinacija[i] << " ";
    cout << endl;
}

bool sledecaKombinacija(int n, vector<int>& kombinacija)
{
    int k = kombinacija.size();
    int i;
    for (i = k - 1; i >= 0 && kombinacija[i] == n; i--, n--)
        ;
    if (i < 0)
        return false;
    kombinacija[i]++;
    for (i++; i < k; i++)
        kombinacija[i] = kombinacija[i - 1] + 1;
    return true;
}

void obradiSveKombinacije(int k, int n)
{
    vector<int> kombinacija(k);
    for (int i = 0; i < k; i++)
        kombinacija[i] = i + 1;
    do
    {
        obradi(kombinacija);
    }
    while (sledecaKombinacija(n, kombinacija));
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
