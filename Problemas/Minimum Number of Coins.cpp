#include <iostream>
#define INF ((int)1e9)
#define MAX 1123456
using namespace std;

int value[MAX];  // Armazena o menor número de moedas para formar um valor x.
bool ready[MAX]; // Armazena se o menor número para o valor já foi calculado.
int coins[] = {1, 2, 3};

/**
 * A recursão vai descendo e calculando o resultado para valores pequenos como 1, 2, 3
 * e torna rápido o cálculo com o solve para números maiores.
 */

int solve(int x)
{
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    int best = INF;
    // Para cada moeda calculamos o menor valor entre o atual e tentar colocar a moeda na soma.
    for (auto c : coins)
        best = min(best, solve(x - c) + 1);
    value[x] = best;
    ready[x] = true;
    return best;
}

int main()
{
    int x, ans;
    cin >> x;
    ans = solve(x);
    cout << (ans != INF ? solve(x) : -1) << endl;
    return 0;
}
