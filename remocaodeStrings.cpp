#include <bits/stdc++.h>
using namespace std;

vector<string> results;
vector<int> groups_index_i;
vector<int> groups_index_j;

int i, j;

int dp(string n)
{
}

int searchString(vector<string> results, string N)
{
    //found
    if (std::find(results.begin(), results.end(), N) != results.end())
    {
        return 1;
    }
    else
    {
        printf("nao achou\n");
        return -1;
    }

}

int findGroup(string N)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < N.size(); i++)
    {
        if (N[i] != N[j])
        {
            k = i - 1;
            groups_index_i.push_back(j);
            groups_index_j.push_back(k);
            j = i;
        }
    }
    for (int i = 0; i < N.length(); i++)
    {
        for (int v = groups_index_i[i]; v < groups_index_j[i]; v++)
        {
            cout << groups_index_i[v] << " " << groups_index_j[v];
            return 1;
        }
    }
}

int main()
{
    int T;
    string N;
    string space;

    scanf("%d", &T);
    getchar();

    while (T--)
    {
        getline(cin, N);

        //results.push_back(N);
        findGroup(N);

        for (int i = 0; i < results.size(); i++)
            cout << results[i];
        cout << endl;

//        for ( int i = 0; i < N.length(); i++)
//            cout << N[i];
//        cout << endl;
    }
    return 0;
}
