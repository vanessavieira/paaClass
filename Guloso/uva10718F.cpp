#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    unsigned int N, L, U;

    while (cin >> N >> L >> U)
    {
        unsigned int M = ~N;
        for (int i = 31; i >= 0; --i)
        {
            unsigned int mask = 1 << i;
            if ((M >> i) < (L >> i))
            {
                M |= mask;
            }
            else if ((M >> i) > (U >> i))
            {
                M &= ~mask;
            }
        }
        cout << M << endl;
    }
    return 0;
}
