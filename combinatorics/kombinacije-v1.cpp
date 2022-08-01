//kombinacije bez ponavljanja v1
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int> &kombinacija)
{
    for (int i = 0; i < kombinacija.size(); i++)
        cout << kombinacija[i] << " ";
    cout << endl;
}

void obradiSveKombinacije(vector<int>& kombinacija, int i, int n, int k)
{
    if (i == k)
    {
        obradi(kombinacija);
        return;
    }
    int pocetak = i == 0 ? 1 : kombinacija[i - 1] + 1;
    int kraj = n + i - k + 1;
    for (int x = pocetak; x <= kraj; x++)
    {
        kombinacija[i] = x;
        obradiSveKombinacije(kombinacija, i + 1, n, k);
    }
}

void obradiSveKombinacije(int k, int n)
{
    vector<int> kombinacija(k);
    obradiSveKombinacije(kombinacija, 0, n, k);
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
