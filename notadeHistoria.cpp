#include<bits/stdc++.h>

using namespace std;

// lcs naive algorithm
int lcs( int *X, int *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

// lcs dynamic programming algorithm
int lcs(int *ordered, int *awnser, int n){
int lcs[50][50] = {0};
	 for (int i = 1; i < n+1; ++i){
	     for (int j = 1; j < n+1; ++j) {
            if(ordered[i-1] == awnser[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
        }
	 }
    return lcs[n][n];
}
int main()
{
    int n_events;
    int j = 0;
    cin >> n_events;

    int read_value, ordered[n_events], awnser[n_events];

    // reading input to save on the "ordered" array in the correct order
    for(int i = 0; i < n_events; i++)
    {
        cin >> read_value;
        ordered[read_value - 1] = i;
    }

//     for(int i = 0; i < n_events; i++)
//    {
//        cout << ordered[i] << " ";
//    }

    while(1)
    {
        for(int i = 0; i < n_events; i++)
		{
		    // kind of an eof; the while will stop here
			if(scanf("%d", &read_value) != 1)
			{
				return 0;
			}
			// getting the "awnser" array in the correct order
			awnser[read_value - 1] = i;
		}

        cout << lcs(ordered, awnser, n_events) << "\n";

    }
    return 0;
}
