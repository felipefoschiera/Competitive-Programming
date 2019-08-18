/**
 *  Resolvido com SQRT Decomposition e Ordered Set
 *  Ensinado por Naum Azeredo via Telegram
 */

/**
 *  O ordered_set funciona como um set normal(aqui com a função do multiset, para ter elementos repetidos),
 *  mas sua diferença é que ao utilizarmos uma função de pesquisa, como a lower_bound() (no caso do ordered_set,
 *  é a order_of_key()), ao invés de apontarmos para o elemento, apontamos para o índice.
 *  Portanto, a order_of_key(v) retorna o índice do primeiro elemento >= a v, que consequentemente é
 *  a quantidade de elementos menores que v no conjunto ordenado.
 */
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MAX 312345
#define SQ 550
using namespace std;
using namespace __gnu_pbds;

// SQ é a raiz quadrada do maior N possivel (3*10^5)

typedef long long ll;
typedef pair<ll, ll> pll; 
typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// SQ ordered sets 
ordered_set b[SQ];

int n, m, u;
ll a[MAX];
 
// A query retorna o número de elementos menores que v no intervalo.
int query(int l, int r, int v) {
  int ans = 0;
  // Primeiro busca pelos blocos inteiramente dentro do intervalo dos blocos de L e R.
  // O bloco de L é L/SQ, então inicia em L/SQ+1, e o bloco R é R/SQ, terminando antes dele.
  for (int i = l/SQ+1; i < r/SQ; i++)
    ans += b[i].order_of_key({ v, 0 });
    // order_of_key aponta para a posição do primeiro elemento >= a v, como um lower_bound
 
  // Aqui ele busca os elementos nos cantos, não inteiramente dentro do intervalo
  if (l/SQ != r/SQ) {
    // Se estão em blocos diferentes, adiciona-se a parte de L até o bloco de L,
    // e a parte do bloco de R até R.
    for (int i = l; i < (l/SQ+1)*SQ; i++) ans += a[i] < v;
    for (int i = r/SQ*SQ; i <= r; i++) ans += a[i] < v;
  } else {

    // Se ambos estão no mesmo bloco, basta adicionar todos eles
    for (int i = l; i <= r; i++) ans += a[i] < v;
  }
 
  return ans;
}
 
void update(int p, int k, int l, int r) {
  // Realiza o cálculo da questão e troca o valor do elemento a[p]
  ll val = 1LL*u*k/(r-l+1);
  b[p/SQ].erase({ a[p], p });
  a[p] = val;
  b[p/SQ].insert({ a[p], p });
}
 
int main() {
  scanf("%d %d %d", &n, &m, &u);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    // i/SQ é o 'bloco' onde o elemento i é inserido, considerando SQ bloco.
    // Insere-se o par {valor, indice} para poder haver elementos repetidos.
    b[i/SQ].insert({ a[i], i });
  }
 
  for (int i = 0; i < m; i++) {
    int l, r, v, p;
    scanf("%d %d %d %d", &l, &r, &v, &p);
    int ans = query(l, r, v);
    update(p, ans, l, r);
  }
 
  for (int i = 1; i <= n; i++) printf("%lld\n", a[i]);
 
  return 0;
}