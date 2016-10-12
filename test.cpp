#include <bits/stdc++.h>
#define f(i,s,e) for (int i = s; i < e; ++i)

using namespace std;

typedef std::vector<string> vs;

vs lol;
int aux[110]; // temp array

int max_sum_subarray(int * arr, int n)
{
    int sum = -INT_MAX;
    int maxsum = -INT_MAX;
    f(i, 0, n)
    {
        sum = (sum < 0) ? arr[i] : (sum + arr[i]);
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

int go(int n)
{
    int maxsum = 0;
    f(x, 0, n)
    {
        memset(aux, 0, sizeof(aux));
        f(y, x, n)
        {
            f(i, 0, n)
            aux[i] += (lol[i][y] - '0') ? 1 : -99999999;
            maxsum = max(maxsum, max_sum_subarray(aux, n));
        }
    }
    return maxsum;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        int n = str.size() - 1;
        lol.push_back(str);
        while(n--)
        {
            cin >> str;
            lol.push_back(str);
        }

        cout << go(str.size()) << endl;
        if(t) cout << endl;
        lol.clear();
    }
    return 0;
}
