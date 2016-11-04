#include <bits/stdc++.h>
using namespace std;

#define MAX 500

typedef int array[MAX];
int j;

int findingNonDuplicate(array a, int b, int e)
{
    int pivo = (b + e)/2;
    int prev = pivo - 1;
    int next = pivo + 1;

    if (a[pivo] != a[next] && a[pivo] != a[prev])
    {
        return a[pivo];
    }

    if (pivo % 2 != 0 && a[pivo] != a[prev])
    {
        findingNonDuplicate(a, b, prev);
    }

    else if (pivo % 2 != 0 && a[pivo] == a[prev])
    {
        findingNonDuplicate(a, next, e);
    }
}

int main()
{
    int n_tests, size;

    scanf("%d", &n_tests);

    for (int i = 0; i < n_tests; ++i)
    {
        scanf("%d", &size);

        array a;
        int q;

        for (j = 0; j < size; ++j)
        {
            scanf("%d", &a[j]);
        }

        int resp = findingNonDuplicate(a, 0, size - 1);

        printf ("%d", resp);
    }
    return 0;
}

