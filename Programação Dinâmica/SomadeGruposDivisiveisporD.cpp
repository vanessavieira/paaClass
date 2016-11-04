#include <bits/stdc++.h>
using namespace std;

#define MAX 210
int numbers, M, D, total_queries;

int arr[MAX], memo[MAX][MAX][15];

int dp(int i, int sum, int c)
{
    if(c == M && sum == 0)
        return 1;
    if(c == M && sum != 0)
        return 0;
    if(i == numbers)
        return 0;
    if(memo[i][sum][c] != -1)
        return memo[i][sum][c];

    memo[i][sum][c] = dp(i+1, sum%D, c) + dp(i+1, (sum+arr[i])%D, c+1);

    return memo[i][sum][c];
}

int main()
{
    int SET = 0, res;

    cin >> numbers;
    cin >> total_queries;

    while(numbers != 0 && total_queries != 0)
    {
        SET++;

        // input
        for (int j = 0; j < numbers; ++j)
        {
            cin >> arr[j];
        }

        // input & output
        cout << "SET " << SET << ":\n";

        for (int i = 0; i < total_queries; ++i)
        {
            cin >> D;
            cin >> M;

            memset(memo, -1, sizeof(memo));
            res = dp(0, 0, 0);
            // output
            cout << "QUERY " << i + 1 << ": " << res << "\n";
        }

//test
//        cout << "array: ";
//        for (int j = 0; j < numbers; ++j)
//        {
//            cout << arr[j] << " ";
//        }
//        cout << "\n";
//
//        for (int i = 0; i < total_queries; ++i)
//        {
//            cout << "D: " << D[i] << " ";
//            cout << "M: " << M[i] << " ";
//        }
//        cout << "\n";

        cin >> numbers;
        cin >> total_queries;
    }
    return 0;
}
