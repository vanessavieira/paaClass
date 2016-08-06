#include <bits/stdc++.h>
using namespace std;

#define MAX 500

typedef int array[MAX];

void searchQuerie(array marbles, int b, int e, int size, int querie)
{
    int pivo = (b + e)/2;
    int prev = pivo - 1;
    int next = pivo + 1;

    if (b == e)
    {
        if (pivo[marbles] == querie)
        {
            printf("%d found at %d", querie, pivo);
        }
        else
        {
            printf("%d not found", querie);
        }
    }
    else
    {
        // se ja achar
        if (marbles[pivo] == querie)
        {
            printf("%d found at %d", querie, pivo);
        }

        // procura mais a direita
        else if (querie > marbles[pivo])
        {
            searchQuerie(marbles, next, e, size, querie);
        }
        // procura mais a esquerda
        else if (querie < marbles[pivo])
        {
            searchQuerie(marbles, b, prev, size, querie);
        }
    }
}

int main()
{
    // n_marbles = size
    int n_marbles = 1;
    int n_queries = 1;
    array marbles;
    int querie;

    while (n_marbles != 0 && n_queries != 0)
    {
        scanf("%d %d", &n_marbles, &n_queries);

        for (int i = 0; i < n_marbles; ++i)
        {
            scanf("%d", &marbles[i]);
        }

        for (int j = 0; j < n_queries; ++j)
        {
            scanf("%d", &querie);

            // chama uma funcao de busca
            searchQuerie(marbles, 0, n_marbles - 1, n_queries, querie);

        }

    }

}
