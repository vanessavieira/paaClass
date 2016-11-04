#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

typedef int vetor[MAX];

void merge(vetor marbles, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = marbles[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = marbles[m + 1+ j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            marbles[k] = L[i];
            i++;
        }
        else
        {
            marbles[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        marbles[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        marbles[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vetor marbles, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(marbles, l, m);
        mergeSort(marbles, m+1, r);

        merge(marbles, l, m, r);

    }
}

int searchQuerie(vetor marbles, int b, int e, int querie)
{
    // printf("entrou\n");
    int pivo = (b + e)/2;
    int prev = pivo - 1;
    int next = pivo + 1;

    if (b > e)
    {
        return -1;
    }

    else if (b == e)
    {
        if (marbles[b] == querie) return b;

        else return -1;
    }

    // procura mais a esquerda
    if (querie <= marbles[pivo])
    {
        searchQuerie(marbles, b, pivo, querie);
    }
    // procura mais a direita
    else {
        searchQuerie(marbles, next, e, querie);
    }
}

int main()
{
    // n_marbles = size
    int n_marbles;
    int n_queries;
    vetor marbles, ordered;
    int querie;
    int cases = 1, pos;

    scanf("%d %d", &n_marbles, &n_queries);
    while (n_marbles != 0 && n_queries != 0)
    {
        for (int i = 0; i < n_marbles; ++i)
        {
            scanf("%d", &marbles[i]);
        }

        printf("CASE# %d:\n", cases++);
        // chama uma funcao de ordenacao
        mergeSort(marbles, 0, n_marbles - 1);

        for (int j = 0; j < n_queries; ++j)
        {
            scanf("%d", &querie);

//            printf("array ordenado:\n");
//            for (int a = 0; a < n_marbles; ++a){
//                printf("%d ", marbles[a]);
//            }
            // chama uma funcao de busca
            pos = searchQuerie(marbles, 0, n_marbles - 1, querie);

            if (pos == -1)
            {
                printf("%d not found\n", querie);
            }
            else
            {
                printf("%d found at %d\n", querie, pos+1);
            }
        }
        scanf("%d %d", &n_marbles, &n_queries);
    }

    return 0;
}
