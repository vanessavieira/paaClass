/*
    Count the Zeros
    Given an array of size N consisting of only 0's and 1's,
    which is sorted in such a manner that all the 1's are placed first and then they are followed by all the 0's.
    You have to find  the count of all the 0's.


    Input:
    The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
    The first line of each test case contains an integer N, where N is the size of the array A[ ].
    The second line of each test case contains N space separated integers of all 1's follwed by all the 0's,
    denoting elements of the array A[ ].


    Output:
    Print out the number of 0's in the array.

    Constraints:
    1 <= T <= 100
    1 <= N <= 30
    0 <= A[i] <= 1

*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 30

typedef int array[MAX];
int j;

bool searchZeros(array a, int b, int e, int sum, int size)
{
    int pivo = (b + e)/2;
    int prev = pivo - 1;
    int next = pivo + 1;

    //achou o pivo como 0
    if (pivo == 0)
    {
        sum += e + 1;
        printf("%d\n", sum);
    }
    else if (pivo == size)
    {
        printf ("%d", sum);
    }
    else
    {
        if (a[pivo] == 0)
        {
            if (a[prev] == 1)
            {
                sum += (size - pivo) + 1;
                printf ("%d\n", sum);
                return true;

            }
            else
            {
                //chama de novo a funcao pra o array da esquerda (pra achar o primeiro 0)
                sum += (size - pivo) + 1;
                searchZeros(a, 0, prev, sum, size);
            }

        }
        else if (a[pivo] == 1)   //achou o pivo como 1
        {
            if (a[next] == 0)
            {
                sum += (size - next) + 1;
                printf ("%d\n", sum);
                return true;
            }
            else
            {
                //chama a funcao pra o lado direito do array (pois antes so vai ter 1)
                searchZeros(a, next, size, sum, size);
            }

        }
    }
}

int main()
{

    int testCases, size;

    scanf("%d", &testCases);

    for (int i = 0; i < testCases; ++i)
    {

        array a;
        int sum = 0;

        scanf("%d", &size);

        for (j = 0; j < size; ++j)
        {
            scanf("%d", &a[j]);
        }

        searchZeros(a, 0, size - 1, sum, size - 1);

    }
    return 0;
}
