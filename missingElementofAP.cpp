/*
    Missing element of AP

    Find the missing element from  an ordered array A[ ],
    consisting of N elements representing an Arithmetic Progression (AP).

    Input:
    The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
    The first line of each test case contains an integer N, where N is the size of the array A[ ].
    The second line of each test case contains N space separated integers of an Arithmetic Progression
    denoting elements of the array A[ ].


    Note: The series should have a missing element in between a perfect A.P.
    with no missing element will not be considered.


    Output:
    Print out the missing element.


    Constraints:
    1 <= T <= 100
    2 <= N <= 10
    -50 <= A[i] <=50
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 10

typedef int array[MAX];
int j;

bool searchMissingElement(array a, int q, int b, int e){
	int size = e - b;
	int pivo = (b + e)/2;
	int prev = pivo - 1;
	int next = pivo + 1;

	//printf("pivo: %d\n", pivo);
	//printf("valor pivo: %d\n", a[pivo]);

	if (pivo > 0 && pivo < size){

		if (((a[pivo] - a[prev]) == q) && ((a[next] - a[pivo]) == q)){

			searchMissingElement(a, q, 0, prev);
			searchMissingElement(a, q, next, size);

		} else if ((a[pivo] - a[prev]) != q) {
			//achou no lado esquerdo pivo - q
			printf("%d\n",a[pivo] - q);
			return true;
		} else if ((a[next] - a[pivo]) != q){
			//achou no lado direito pivo + q
			printf("%d\n",a[pivo] + q);
			return true;
		}

	} else {
		if (pivo == 0 && (a[next] - a[pivo]) == q) return false;
		else if (pivo == size && (a[pivo] - a[prev]) == q) return false;
	}
}



main(){
	int n_tests, size;

	scanf("%d", &n_tests);

	for (int i = 0; i < n_tests; ++i){
		scanf("%d", &size);

		array a;
		int q;

		for (j = 0; j < size; ++j){
			scanf("%d", &a[j]);
		}

		q = (a[size-1] - a[0])/size;

		searchMissingElement(a, q, 0, size - 1);

	}

	//for (int k = 0; k < n_tests; ++k){
    //    printf("%d\n", anwser[k]);
	//}
}
