#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define maxN 11

int main()
{
    vi champer[maxN];

    double sumChamper[maxN];

    int n, m, a[maxN], cases = 0;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        double avg = 0.0;

        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
            avg += a[i];
        }
        for (int i = 0; i < n; i++)
            sumChamper[i] = 0.0, champer[i].clear();

        avg /= n;
        sort(a, a + m);

        for (int i = m - 1, j = 0, k = 1; i >= 0; i--, j += k)
        {
            sumChamper[j] += a[i];
            champer[j].push_back(a[i]);

            if (j == n - 1 && k == 1) k = 0;

            else if (j == n - 1 && k == 0) k = -1;
        }

        double res = 0.0;
        for (int i = 0; i < n; i++)
            res += fabs(sumChamper[i] - avg);

        printf("Set #%d\n", ++cases);

        for (int i = 0; i < n; i++)
        {
            printf("%2d:", i);
            for (int j = 0; j < champer[i].size(); j++)
                printf(" %d", champer[i][j]);

            putchar('\n');
        }
        printf("IMBALANCE = %.5lf\n\n", res);
    }
    return 0;
}
