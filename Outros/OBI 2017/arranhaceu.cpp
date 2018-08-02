#include <iostream>
#include <vector>
#include <string.h>
#define MAX 112345
using namespace std;
typedef long long ll;
int ft[MAX];

int LSOne(int S)
{
    return S & (-S);
}

void adjust(int k, ll v)
{
    while (k < MAX)
    {
        ft[k] += v;
        k += LSOne(k);
    }
}

ll rsq(int b)
{
    int soma = 0;
    while (b > 0)
    {
        soma += ft[b];
        b -= LSOne(b);
    }
    return soma;
}

int main()
{
    memset(ft, 0, MAX);
    int N, Q;
    cin >> N >> Q;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        ll s;
        cin >> s;
        v.push_back(s);
        adjust(i + 1, s);
    }
    for (int i = 0; i < Q; i++)
    {
        int q, k;
        cin >> q >> k;
        if (q == 1)
        {
            cout << rsq(k) << endl;
        }
        else
        {
            ll val;
            cin >> val;
            adjust(k, val - v[k - 1]);
            v[k - 1] = val;
        }
    }

    return 0;
}