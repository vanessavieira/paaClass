/*
    Minimum element in a sorted and rotated array
    A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

    Expected Time Complexity: O(Log n)

    Input:

    The first line of input contains a single integer T denoting the number of test cases.
    Then T test cases follow. Each test case consist of two lines. The first line of each test
    case consists of an integer N, where N is the size of array.
    The second line of each test case contains N space separated integers denoting array elements.

    Output:
    Corresponding to each test case, in a new line, print the minimum element in the array.

    Constraints:

    1 <= T <= 100
    1 <= N <= 500
    1 <= A[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 500

typedef int array[MAX];
int j;
int minimum = 1000;

int searchMinimumElement(array a, int b, int e, int size)
{
    int pivo = (b + e)/2;
    int prev = pivo - 1;
    int next = pivo + 1;

    if (pivo == 0 || pivo == size - 1 || b == e)
    {
        if (a[pivo] <= minimum)
        {
            minimum = a[pivo];
        }
        return minimum;
        //printf ("min: %d\n", minimum);
    }
    /*if (b == e)
    {
        return minimum;
    }*/

    if (pivo > 0 && pivo < size - 1)
    {
        if(a[pivo] < a[prev] && a[pivo] < a[next])
        {
            minimum = a[pivo];
            //return minimum;
        }

        else if (a[pivo] > a[prev] && a[pivo] < a[next])
        {
            return searchMinimumElement(a, b, prev, size);
            return searchMinimumElement(a, next, e, size);
        }

        /*else if (a[pivo] > a[prev] && a[pivo] > a[next])

        {
            printf ("sup\n");
            printf ("next: %d\n", a[next]);
            if (a[next] <= minimum)
            {
                minimum = a[next];
            }
            printf ("minimo: %d\n", minimum);
        }*/
    }
    return minimum;
}

int main()
{
    int n_tests, size, minimum, resp;

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

        resp = searchMinimumElement(a, 0, size - 1, size);

        printf ("%d\n", resp);
    }
    return 0;
}
