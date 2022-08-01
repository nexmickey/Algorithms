//particije broja v2
#include<bits/stdc++.h>
using namespace std;

void obradi(vector<int>& particija, int g)
{
    for (int i = 0; i < g; i++)
        cout << particija[i] << " ";
    cout << endl;
}

void obradiParticije(int n, int smax, vector<int>& particija, int i)
{
    if (n == 0)
        obradi(particija, i);
    else
    {
        if (smax == 0)
            return;
        obradiParticije(n, smax - 1, particija, i);
        if (n >= smax)
        {
            particija[i] = smax;
            obradiParticije(n - smax, smax, particija, i + 1);
        }
        //obradiParticije(n, smax-1, particija, i);
    }
}

void obradiParticije(int n)
{
    vector<int> particija(n);
    obradiParticije(n, n, particija, 0);
}


int main()
{
    int n;
    cin >> n;
    obradiParticije(n);
}

/*
5

1 1 1 1 1
2 1 1 1
2 2 1
3 1 1
3 2
4 1
5
*/
