#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vetor;

int searchLastSmaller(vetor &females_h, int q)
{
    int l = 0;
    int r = (int)females_h.size() - 1;
    int awnser = -1;

    while (l <= r)
    {
        int j = l + ((r - l) >> 1);
        if (females_h[j] < q)
        {
            awnser = females_h[j];
            l = j + 1;
        }
        else
            r = j - 1;
    }
    return awnser;
}

int searchFirstLarger(vetor &females_h, int q)
{
    int l = 0;
    int r = (int)females_h.size() - 1;
    int awnser = -1;

    while (l <= r)
    {
        int j = l + ((r - l) >> 1);
        if (females_h[j] > q)
        {
            awnser = females_h[j];
            r = j - 1;
        }
        else
            l = j + 1;
    }
    return awnser;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> females_h(n);
        for (int i = 0; i < n; ++i)
            cin >> females_h[i];

        //sort(females_h.begin(), females_h.end());

        int q;
        cin >> q;
        while (q--)
        {
            int q;
            cin >> q;

            int smaller, highest;
            smaller = searchLastSmaller(females_h, q);
            highest = searchFirstLarger(females_h, q);

            if (smaller == -1)
                cout << "X";
            else
                cout << smaller;

            cout << " ";

            if (highest == -1)
                cout << "X";
            else
                cout << highest;

            cout << endl;
        }
    }
    return 0;
}
