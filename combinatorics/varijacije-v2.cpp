//varijacije v2
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int>& varijacija)
{
    for (int i = 0; i < varijacija.size(); i++)
        cout << varijacija[i] << " ";
    cout << endl;
}

bool sledecaVarijacija(int k, int n, vector<int>& varijacija)
{
    int i;
    for (i = k - 1; i >= 0 && varijacija[i] == n; i--)
        varijacija[i] = 1;
    if (i < 0)
        return false;
    varijacija[i]++;
    return true;
}
void obradiSveVarijacije(int k, int n)
{
    vector<int> varijacija(k, 1);
    do
    {
        obradi(varijacija);
    }
    while(sledecaVarijacija(k, n, varijacija));
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
