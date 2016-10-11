#include <bits/stdc++.h>
using namespace std;

map<string, int> dp;

int backtracking(string n)
{
    if(dp.count(n))return dp[n];

    int result = 0;
    vector<int> next(n.size());

    next[n.size()-1] = n.size()-1;
    // separa grupos
    for(int i = n.size()-2; i >= 0; --i)
    {
        if(n[i] == n[i+1])
        {
            next[i] = next[i+1];
        }
        else next[i] = i;
    }

    // "concatenando"
    for(int i = 0; i < next.size(); i = next[i]+1)
    {
        if (i != next[i])
        {
            string conc = n;
            conc.erase(i, next[i]-i+1);
            result = result || backtracking(conc);
        }

    }
    return dp[n] = result;
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();

    dp["a"] = dp["b"] = 0;
    dp[""] = 1;

    while (T--)
    {
        string N;
        getline(cin, N);

        int final_result = backtracking(N);

        if (final_result == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
