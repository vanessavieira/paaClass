// *using kadane's 2D algorithm*
// the only change that was made was that i'm not using an int matrix
// i'm using a vector<string> matrix (it was easier to read the input)

#include <bits/stdc++.h>
using namespace std;

typedef std::vector<string> Matrix;

Matrix matrix; // the data matrix
int b[110]; // temp array

int max_sum_subarray(int * array, int n)
{
    int sum = -INT_MAX;
    int maxsum = -INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        sum = (sum < 0) ? array[i] : (sum + array[i]);
        maxsum = max(maxsum, sum);
    }

    return maxsum;
}

int max_sum_submatrix(int n)
{
    int maxsum = 0;
    for (int x = 0; x < n; ++x)
    {
        memset(b, 0, sizeof(b));
        for (int y = x; y < n; ++y)
        {
            for (int i = 0; i < n; ++i)
            {
                // the algorithm does not work with 0
                b[i] += (matrix[i][y] - '0') ? 1 : -99999999;
            }
            maxsum = max(maxsum, max_sum_subarray(b, n));
        }
    }
    return maxsum;
}

int main()
{
    int test_cases;

    cin >> test_cases;

    while (test_cases--)
    {
        string line;
        cin >> line;
        // size for each line
        int size_ = line.size() - 1;

        matrix.push_back(line);

        while(size_--)
        {
            cin >> line;
            matrix.push_back(line);
        }
        cout << max_sum_submatrix(line.size()) << endl;

        if(test_cases) cout << endl;
        matrix.clear();
    }
    return 0;
}
